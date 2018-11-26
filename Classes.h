#ifndef CLASSES_H
#define CLASSES_H

struct Move {
  int rowloc, columnloc, newrowloc, newcolumnloc, value;
  Move* next;
};

struct CheckerPiece {
  int row, column;
  char color;
  bool king;
  CheckerPiece* next;
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
  bool jumpPossible(int, int, int, int, int, int);
  bool movePossible(int, int, int, int);
  void makeMove(int, int, int, int);
  bool gameOver();
  void generateMoves();
  void clearMoves();
  void updateBoard();
  void showBoard();
  void game();
  void CPUPlayer(bool);
  void moveCPU(Player*);
};


#endif
