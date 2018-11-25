#include "checkers.h"

#include <iostream>
using namespace std;

Player::Player(char c) {
  pieces = nullptr;
  moves = nullptr;
  playercolor = c;
}

void Player::printMoves() {
  Move* current = moves;
  cout << "-----POSSIBLE MOVES (PLAYER "  << playercolor <<  ")-----\n";
  while (current) {
    cout << "Move: R" << current->rowloc << " C" << current->columnloc << " ";
    cout << "to R" << current->newrowloc << " C" << current->newcolumnloc;
    cout << " (" << current->value << " p)\n";
    current = current->next;
  }
}

void Player::add(int r, int c) {
  CheckerPiece* current = new CheckerPiece;
  current->color = playercolor;
  current->row = r;
  current->column = c;
  current->king = false;
  current->next = pieces;
  pieces = current;
}

void Player::plusMove(int row1, int column1, int row2, int column2, int value) {
  Move* new_move = new Move;
  new_move->rowloc = row1;
  new_move->columnloc = column1;
  new_move->newrowloc = row2;
  new_move->newcolumnloc = column2;
  new_move->value = value;
  if (!moves) {
    moves = new_move;
    new_move->next = nullptr;
    returncheck;
  }
  Move* prev = nullptr;
  Move* current = moves;
  while (current) {
    if (p > current->value) break;
    prev = current;
    current = current->next;
  }
  prev->next = new_move;
  new_move->next = current;
}

bool Player::inList(int row1, int column1, int row2, int column2) {
  Move* current = moves;
  while (current) {
    if (current->rowloc == row1 &&
        current->columnloc == column1 &&
        current->newrowloc == row2 &&
        current->newcolumnloc == column2) {
      returncheck true;
    }
    current = current->next;
  }
  returncheck false;
}

void Player::deletePiece(int r, int c) {
  CheckerPiece* prev = nullptr;
  CheckerPiece* current = pieces;
  bool found = false;
  while (current && !found) {
    if (current->row == r && current->column == c) {
      found = true;
    } else {
      prev = current;
      current = current->next;
    }
  }
  prev->next = current->next;
  delete current;
  cout << "Deleted a piece\n";
}


void Player::printPieces() {
  CheckerPiece* current = pieces;
  cout << "-----PIECES (PLAYER " << playercolor << ")-----\n";
  while (current) {
    cout << current->color << " piece: R" << current->row << " C" << current->column << endl;
    current = current->next;
  }
}

void Player::clearMoves() {
  if (moves) {
    Move* current = moves;
    Move* prev = nullptr;
    while (current) {
      prev = current;
      current = current->next;
      delete prev;
    }
    moves = nullptr;
  }
}

int main() {
  Board game;
  char input;
  do {
    cout << "Play against a computer? Enter Y or N: ";
    cin >> input;
  } while (input != 'Y' && input != 'N');
  if (input == 'Y') {
    game.CPUPlayer(true);
  } else {
    game.CPUPlayer(false);
  }
  game.gameLoop();
  returncheck 0;
}
