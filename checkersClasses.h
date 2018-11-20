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
        node *next;
    };
    Node *NodePtr;
    void makeMove();
    bool isComputer;
    void computerLogic(); // possibly not needed b/c of minimax
};

class Board : public Player
{
  public:
    struct BoardStruct
    {
        SpacePtr spaces[8][8];
    };
    BoardStruct *Board;

    struct LinkedList
    {
        NodePtr head;
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
    double minimax();
    void checkStatus();
};