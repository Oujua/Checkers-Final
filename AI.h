#ifndef AI_H
#define AI_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int row;
    int column;
};

struct Move
{
    Point start;
    Point end;
};

enum Type
{
    nul,
    black,
    white,
    blackKing,
    whiteKing
};

enum Side
{
    blackSide,
    whiteSide
};

enum GameStats
{
    complete,
    invalidPiece,
    invalidDest,
    gameOver
};

class Board
{
  private:
    int numBlack;
    int numWhite;
    int numBlackKings;
    int numWhiteKings;
    Type **board;

  public:
    Board();
    Board(Type **board);
    Board *clone();
    int getNumBlackPieces();
    int getNumWhitePieces();
    int getNumBlackKings();
    int getNumWhiteKings();
    bool isOpp(Side side, Type);
    bool isOwn(int row, int column, Side side);
    bool movesEqual(Move firstMove, Move secondMove);
    void drawBoard();
    void generateMoves(Side side, vector<Move> &moves);
    void generateJumpMoves(int row, int column, Side side, vector<Move> &moves);
    void generateValidMoves(int row, int column, Side side, vector<Move> &moves);
    Type getPiece(int i, int j);
    Type getPiece(Point point);
    Point getMiddleSquare(Move move);
    GameStats makeMove(Move move, Side side);
};

class Player
{
  public:
    Side side;
    string name;

  public:
    Player(string name, Side side);
    virtual GameStats makeMove(Move move, Board board);
    Side getSide();
};

class AI : public Player
{
  private:
    int depth;

  public:
    AI(string name, Side side) : Player(name, side) { depth = 3; };
    GameStats makeMove(Board board);
    Move minimaxStart(Board board, Side side, bool maximing);
    double minimax(Board board, Side side, bool maximing, int depth, int alpha, int beta);
    double getHeuristicValues(Board board);
    Side switchSide(Side side);
};

#endif