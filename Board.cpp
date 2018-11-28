#ifndef BOARD_CPP
#define BOARD_CPP
#include "Classes.h"
#include <iostream>

using namespace std;

Board::Board() {
  black = new Player('O');
  red = new Player('X');
  gameover = false;
  turncheck = 'X';

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
        cout << "  ";
        cout << board[row][col]->color;
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}

void Board::gameLoop() {
  int piece_r, piece_c, move_r, move_c;
  if (!CPU) {
    while (!gameover) {
      updateBoard();
      showBoard();
      clearMoves();
      generateMoves();
      if (turncheck == 'X') {
        cout << "BLACK turncheck\n";
        black->printPieces();
        black->printMoves();
        do {
          cout << "ENTER MOVE COORDINATES\n";
          cout << "CHOSEN PIECE (ROW COLUMN): ";
          cin >> piece_r >> piece_c;
          cout << "PIECE DESTINATION (ROW COLUMN): ";
          cin >> move_r >> move_c;
        } while (!(black->inList(piece_r, piece_c, move_r, move_c)));
        // black->makeMove(piece_r, piece_c, move_r, move_c);
        makeMove(piece_r, piece_c, move_r, move_c);
      } else if (turncheck == 'O') {
        cout << "RED turncheck\n";
        red->printPieces();
        red->printMoves();
        do {
          cout << "ENTER MOVE COORDINATES\n";
          cout << "CHOSEN PIECE (ROW COLUMN): ";
          cin >> piece_r >> piece_c;
          cout << "PIECE DESTINATION (ROW COLUMN): ";
          cin >> move_r >> move_c;
        } while (!(red->inList(piece_r, piece_c, move_r, move_c)));
        // red->makeMove(piece_r, piece_c, move_r, move_c);
        makeMove(piece_r, piece_c, move_r, move_c);
      }
      gameover = gameOver();
      turncheck = (turncheck == 'X') ? 'O' : 'X';
    }
  } else {
    char choice;
    do {
      cout << "Pick a player (enter X or O): ";
      cin >> choice;
    } while (choice != 'X' && choice != 'O');
    turncheck = choice;
    Player* player = (choice == 'X') ? black : red;
    Player* cpu = (choice == 'X') ? red : black;
    while (!gameover) {
      updateBoard();
      showBoard();
      clearMoves();
      generateMoves();
      if (turncheck == choice) {
        cout << "YOUR turncheck\n";
        player->printPieces();
        player->printMoves();
        do {
          cout << "Enter move coordinates:\n";
          cout << "Chosen piece (enter row column): ";
          cin >> piece_r >> piece_c;
          cout << "Piece destination (enter row column): ";
          cin >> move_r >> move_c;
        } while (!(player->inList(piece_r, piece_c, move_r, move_c)));
        // black->makeMove(piece_r, piece_c, move_r, move_c);
        makeMove(piece_r, piece_c, move_r, move_c);
      } else {
        cout << "CPU turncheck\n";
        cpu->printMoves();
        moveCPU(cpu);
      }
      gameover = gameOver();
      turncheck = turncheck == 'X' ? 'O' : 'X';
    }
  }
  if (black->pieces == nullptr) {
    cout << "Red player won!\n";
  } else if (red->pieces == nullptr) {
    cout << "Black player won!\n";
  } else if (black->moves == nullptr && red->moves == nullptr) {
    cout << "Draw!\n";
  }
}

void Board::moveCPU(Player* cpu) {
  // Make the first move in the list
  Move* first_move = cpu->moves;
  int r1, c1, r2, c2;
  if (first_move) {
    r1 = first_move->r1;
    c1 = first_move->c1;
    r2 = first_move->r2;
    c2 = first_move->c2;
    cout << "***CPU moving R" << r1 << " C" << c1;
    cout << " to R" << r2 << " C" << c2 << endl;
    cout << "Making move\n";
    makeMove(r1, c1, r2, c2);
  } else {
    cout << "CPU has no possible moves\n";
  }
}

bool Board::gameOver() {
  if (black->pieces == nullptr || red->pieces == nullptr ||
         black->moves == nullptr && red->moves == nullptr){
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
  if (board[r1][c1]->color == 'X') {
    if (r3 < r1) turncheck = false;
    if (board[r2][c2]->color != 'O') turncheck = false;
    turncheck = true;
  } else {
    if (r3 > r1) turncheck = false;
    if (board[r2][c2]->color != 'X') turncheck = false;
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
      if (board[r][c]->color == 'X') {
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

  // If no black jumps are possible
  if (!black->moves) {
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (!board[r][c]) continue;
        if (board[r][c]->color == 'X') {
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
        if (board[r][c]->color == 'O') {
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
  // If move is a jump
  cout << "*******Entering make move function\n\n\n";
  if (r1 + 2 == r3 || r1 - 2 == r3) {
    cout << "****Attempting to make a jump move\n";
    int r2 = (r1 + r3) / 2;
    int c2 = (c1 + c3) / 2;
    if (board[r1][c1]->color == 'X') {
      red->deletePiece(r2, c2);
    } else if (board[r1][c1]->color == 'O') {
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
