#ifndef AI_H
#define AI_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Point {
    int row;
    int col;
};

struct Move {
    Point start;
    Point end;
};

enum Side {
    blackSide,
    whiteSide
};

enum Type {
    empty,
    black,
    white,
    blackKing,
    whiteKing
};

enum Status {
    complete,
    invalidPiece,
    invalidDest,
    gameOver
};

class Failure {};

class Board {
private:
    Type** board;
    int numBlackPieces;
    int numWhitePieces;
    int numBlackKings;
    int numWhiteKings;
public:
    Board();
    Board(Type** b);
    bool isOpponentPiece(Side side, Type);
    bool isOwnPiece(int r, int c, Side side);
    bool movesEqual(Move one, Move two);
    int getNumBlack();
    int getNumWhite();
    int getNumBlackKings();
    int getNumWhiteKings();
    Board* clone();
    Type getPiece(int i, int j);
    Type getPiece(Point p);
    Point getMidSquare(Move move);
    Status makeMove(Move move, Side side);
    void drawBoard();
    void genAllMoves(Side side, vector<Move>& moves);
    void genValidJumpMoves(int r, int c, Side side, vector<Move>& moves);
    void genValidMoves(int r, int c, Side side, vector<Move>& moves);
    void setUpBoard();
};

class Player {
protected:
    Side side;
    string name;
public:
    Player(string n, Side s);
    Side getSide();
    virtual Status makeMove(Move move, Board b);
};

class AI : public Player {
private:
    int depth;
public:
    AI(string name, Side side) : Player(name, side){ depth = 3;};
    Status makeMove(Board board);
    Move minimaxStart(Board board, Side side, bool maximizing);
    double minimax(Board board, Side side, bool maximizing, int depth, int alpha, int beta);
    double getHeuristic(Board board);
    Side switchSide(Side side);
};

#endif