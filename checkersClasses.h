#ifndef CHECKERSCLASSES_H
#define CHECKERSCLASSES_H

#include <iostream>
using namespace std;

class Player
{  
  public:
    struct Space
    {
        char player;
        bool isKing;
        int xCoord, yCoord;
    };
    Space *SpacePtr;

    struct Node
    {
        int x, y;
        int isKing;
        Node *next;
    };
    Node *NodePtr;
    void makeMove();
    bool isComputer;
    void computerLogic(); // possibly not needed b/c of minimax
    double minimax(); 
};

class Board : public Player
{
  public:
    struct BoardStruct
    {
        Space spaces[8][8];
    };
    Board *board;

    struct LinkedList
    {
        Node head;
        char Player;
        int pieceNum;
    };
    LinkedList *LinkedPtr;

    Board();
    ~Board();
    void displayBoard();
    void checkMove();
    void removePiece();
    void updateBoard();
    void checkStatus();
};

#endif