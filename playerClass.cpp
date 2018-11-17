#include
#include <string.h>
#include "GameBoardclass.h"

using namespace std;

class Player
{
public:
struct Space
{
bool isComputer;
Node move_list;
char player;
bool isKing;
int xCoord, Ycoord;
} Space, *SpacePtr;

struct Node
{
    struct node* next;
    int x, y;
    int isKing;
} Node, *NodePtr;


void makeMove(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom);
//x and y are starting coordinates
//isJump tells it to remove the peice between the coordinate pairs
//cp is current player, op is opposing player
};
