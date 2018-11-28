#ifndef CLASSES_H
#define CLASSES_H

struct CheckerPiece {
  int row, column;
  char color;
  bool king;
  CheckerPiece* next;
};

struct Move {
  int rowloc, columnloc, newrowloc, newcolumnloc, value;
  int r1, r2, c1, c2;
  Move* next;
};

class Player {
private:
  char playercolor;
public:
  CheckerPiece* pieces;
  Move* moves;
  Player(char);
  void add(int, int);
  void plusMove(int, int, int, int, int);
  void generateMoves();
  bool inList(int, int, int, int);
  void printPieces();
  void printMoves();
  void clearMoves();
  void deletePiece(int, int);
};

class Board {
private:
  Player* black;
  Player* red;
  CheckerPiece* board[8][8];
  bool gameover;
  bool CPU;
  char turncheck;
  

public:
  Board();
  void CPUPlayer(bool);
  bool jumpPossible(int, int, int, int, int, int);
  bool movePossible(int, int, int, int);
  void makeMove(int, int, int, int);
  void generateMoves();
  void clearMoves();
  void updateBoard();
  void showBoard();
  void gameLoop();
  bool gameOver();
  void moveCPU(Player*);
  int minimax();

};

#endif
