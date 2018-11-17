#include
#include <string.h>
#include "playerClass.h"
#include "GameBoardclass.h"
using namespace std;

void Player::makeMove(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom)
{

int ui = 2;
int a, b, c, d, isJump;
isJump = checkLegal(board, cp, x, y, dir, isKing);
removePiece(cp, board, i, j, isKing); //take piece
addPiece(cp, board, i, j, isKing); //update the location

if(isJump == 2)
    removePiece(op, (x+i)/2, (y+j)/2);

if(j == 0 || j == 7 || isKing){
    removePiece(cp, i, j);
    addPiece(cp, board, i, j, 1);
}

refresh(board, p1, p2, top, bottom);
}
