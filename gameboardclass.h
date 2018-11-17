#include
#include <string.h>
#include "playerClass.h"

using namespace std;

class GameBoard : public Player {

public:
    struct Board
{
    SpacePtr spaces[8][8];
} Board, *BoardPtr;

    struct LinkedList
{
    NodePtr head;
    char Player;
    int numPieces;
} LinkedList, *LinkedListPtr;

BoardPtr drawBoard(LinkedListPtr p1, LinkedListPtr p2);

void displayBoard(BoardPtr board, Print *top, Print *bottom);

void refresh(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom);

int checkMove(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, int x, int y, int dir, bool isKing);
//check that a specific makeMove call is legal
//1 is legal, 0 is illegal

int isOut(int x, int y);
//1 is out of bounds

LinkedListPtr addPiece(LinkedListPtr Player, BoardPtr board, int x, int y, bool isKing);

LinkedListPtr removePiece(LinkedListPtr Player, BoardPtr board, int x, int y, bool isKing);

void updateBoard(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2);

int takeTurn(BoardPtr board, char* player, LinkedListPtr currentPlayer, LinkedListPtr waitingPlayer, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom);
