#ifndef BOARD_CPP
#define BOARD_CPP

#include "Classes.h"

#include <iostream>

using namespace std;

Board::Board() {
  black = new Player('b');
  red = new Player('r');
  gameover = false;
  turncheck = 'b';

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 8; col++) {
      if (row % 2 == col % 2) {
        black->add(row, col);
        board[row][col] = black->pieces;
      } else {
        board[row][col] = nullptr;
      }
    }
  }
  for (int row = 3; row < 5; row++) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = nullptr;
    }
  }
  for (int row = 5; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (row % 2 == col % 2) {
        red->add(row, col);
        board[row][col] = red->pieces;
      } else {
        board[row][col] = nullptr;
      }
    }
  }
}

void Board::updateBoard() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      board[row][col] = nullptr;
    }
  }
  CheckerPiece* current = black->pieces;
  while (current) {
    board[current->row][current->column] = current;
    current = current->next;
  }
  current = red->pieces;
  while (current) {
    board[current->row][current->column] = current;
    current = current->next;
  }
}

void Board::showBoard() {
  cout << "C    ";
  for (int col = 0; col < 8; col++) {
    cout << col;
  }
  cout << endl;
  for (int row = 0; row < 8; row++) {
    cout << "R" << row << " - ";
    for (int col = 0; col < 8; col++) {
      if (board[row][col]) {
        cout << board[row][col]->color;
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}

void Board::game() {
  int piece_r, piece_c, move_r, move_c;
  if (!CPU) {
    while (!gameover) {
      updateBoard();
      showBoard();
      clearMoves();
      generateMoves();
      if (turncheck == 'b') {
        cout << "Black player turn.\n";
        black->printPieces();
        black->printMoves();
        do {
          cout << "Enter coordinates\n";
          cout << "current piece: (row column): ";
          cin >> piece_r >> piece_c;
          cout << "requested move: (row column): ";
          cin >> move_r >> move_c;
        } while (!(black->inList(piece_r, piece_c, move_r, move_c)));
        makeMove(piece_r, piece_c, move_r, move_c);
      } else if (turncheck == 'r') {
        cout << "Red player turn.\n";
        red->printPieces();
        red->printMoves();
        do {
          cout << "Enter coordinates\n";
          cout << "current piece: (row column): ";
          cin >> piece_r >> piece_c;
          cout << "requested move: (row column): ";
          cin >> move_r >> move_c;
        } while (!(red->inList(piece_r, piece_c, move_r, move_c)));
        makeMove(piece_r, piece_c, move_r, move_c);
      }
      gameover = gameOver();
      turncheck = (turncheck == 'b') ? 'r' : 'b';
    }
  } else {
    char choice;
    do {
      cout << "Pick a player (enter b or r): ";
      cin >> choice;
    } while (choice != 'b' && choice != 'r');
    turncheck = choice;
    Player* player = (choice == 'b') ? black : red;
    Player* cpu = (choice == 'b') ? red : black;
    while (!gameover) {
      updateBoard();
      showBoard();
      clearMoves();
      generateMoves();
      if (turncheck == choice) {
        cout << "your turn!\n";
        player->printPieces();
        player->printMoves();
        do {
          cout << "Enter coordinates\n";
          cout << "current piece: (row column): ";
          cin >> piece_r >> piece_c;
          cout << "requested move: (row column): ";
          cin >> move_r >> move_c;
        } while (!(player->inList(piece_r, piece_c, move_r, move_c)));
        makeMove(piece_r, piece_c, move_r, move_c);
      } else {
        cout << "CPU turncheck\n";
        cpu->printMoves();
        moveCPU(cpu);
      }
      gameover = gameOver();
      turncheck = turncheck == 'b' ? 'r' : 'b';
    }
  }
  if (black->pieces == nullptr) {
    cout << "Red wins!\n";
  } else if (red->pieces == nullptr) {
    cout << "Black wins!\n";
  } else if (black->moves == nullptr && red->moves == nullptr) {
    cout << "Draw!\n";
  }
}

void Board::moveCPU(Player* cpu) {
  Move* first_move = cpu->moves;
  int r1, c1, r2, c2;
  if (first_move) {
    r1 = first_move->rowloc;
    c1 = first_move->columnloc;
    r2 = first_move->newrowloc;
    c2 = first_move->newcolumnloc;
    cout << "CPU performing move from Row" << r1 << " Column" << c1;
    cout << " to Row" << r2 << " Column" << c2 << endl;
    cout << "Making move...\n";
    makeMove(r1, c1, r2, c2);
  } else {
    cout << "CPU has no possible moves!\n";
  }
}

bool Board::gameOver() {
  if (black->pieces == nullptr || red->pieces == nullptr ||
         (black->moves == nullptr && red->moves == nullptr)) {
            gameover = true;
         }
         return gameover;
}


void Board::clearMoves() {
  black->clearMoves();
  red->clearMoves();
}

bool Board::jumpPossible(int r1, int c1, int r2, int c2, int r3, int c3) {
  if (r3 < 0 || r3 > 7 || c3 < 0 || c3 > 7) turncheck = false;
  if (!board[r1][c1] || !board[r2][c2]) turncheck = false;
  if (board[r3][c3]) turncheck = false;
  if (board[r1][c1]->color == 'b') {
    if (r3 < r1) turncheck = false;
    if (board[r2][c2]->color != 'r') turncheck = false;
    turncheck = true;
  } else {
    if (r3 > r1) turncheck = false;
    if (board[r2][c2]->color != 'b') turncheck = false;
    turncheck = true;
  }
return turncheck;
}

bool Board::movePossible(int r1, int c1, int r2, int c2) {
  if (r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7) turncheck = false;
  if (board[r2][c2]) turncheck = false;
  turncheck = true;
  return turncheck;
}

void Board::generateMoves() {
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (!board[r][c]) continue;
      if (board[r][c]->color == 'b') {
        if (jumpPossible(r, c, r+1, c+1, r+2, c+2)) {
          black->plusMove(r, c, r+2, c+2, 3);
        }
        if (jumpPossible(r, c, r+1, c-1, r+2, c-2)) {
          black->plusMove(r, c, r+2, c-2, 3);
        }
      }
      if (board[r][c]->color == 'r') {
        if (jumpPossible(r, c, r-1, c+1, r-2, c+2)) {
          red->plusMove(r, c, r-2, c+2, 3);
        }
        if (jumpPossible(r, c, r-1, c-1, r-2, c-2)) {
          red->plusMove(r, c, r-2, c-2, 3);
        }
      }
    }
  }
  if (!black->moves) {
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (!board[r][c]) continue;
        if (board[r][c]->color == 'b') {
          if (movePossible(r, c, r+1, c+1)) {
            black->plusMove(r, c, r+1, c+1, 1);
          }
          if (movePossible(r, c, r+1, c-1)) {
            black->plusMove(r, c, r+1, c-1, 1);
          }
        }
      }
    }
  }
  if (!red->moves) {
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (!board[r][c]) continue;
        if (board[r][c]->color == 'r') {
          if (movePossible(r, c, r-1, c+1)) {
            red->plusMove(r, c, r-1, c+1, 1);
          }
          if (movePossible(r, c, r-1, c-1)) {
            red->plusMove(r, c, r-1, c-1, 1);
          }
        }
      }
    }
  }
}

void Board::makeMove(int r1, int c1, int r3, int c3) {
  cout << "Executing make move.....\n\n\n";
  if (r1 + 2 == r3 || r1 - 2 == r3) {
    cout << "Executing jump move...\n";
    int r2 = (r1 + r3) / 2;
    int c2 = (c1 + c3) / 2;
    if (board[r1][c1]->color == 'b') {
      red->deletePiece(r2, c2);
    } else if (board[r1][c1]->color == 'r') {
      black->deletePiece(r2, c2);
    }
  }
  board[r1][c1]->row = r3;
  board[r1][c1]->column = c3;
}

void Board::CPUPlayer(bool mode) {
  CPU = mode;
}

#endif
