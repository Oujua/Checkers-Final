#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Classes.h"

#include <iostream>

using namespace std;

Player::Player(char c) {
  pieces = nullptr;
  moves = nullptr;
  playercolor = c;
}

void Player::printMoves() {
  Move* current = moves;
  cout << "Possible moves (Player "  << playercolor <<  ")\n";
  while (current) {
    cout << "Move: Row" << current->rowloc << " Column" << current->columnloc << " ";
    cout << "to Row" << current->newrowloc << " Column" << current->newcolumnloc;
    cout << " (" << current->value << " points)\n";
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
    return;
  }
  Move* prev = nullptr;
  Move* current = moves;
  while (current) {
    if (prev->value > current->value) break;
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
      return true;
    }
    current = current->next;
  }
  return false;
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
  cout << "Pieces for (Player " << playercolor << ")\n";
  while (current) {
    cout << current->color << " piece location: Row" << current->row << " Column" << current->column << endl;
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

#endif
