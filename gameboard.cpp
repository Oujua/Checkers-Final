#include
#include <string.h>
#include "playerClass.h"
#include "GameBoardclass.h"
using namespace std;

BoardPtr GameBoard::drawBoard(LinkedListPtr p1, LinkedListPtr p2)
{

BoardPtr board;
int x = 0;
int y = 0;
int i = 1;

board = (BoardPtr)malloc(64 * sizeof(Space));

p1->player = 'x';
p2->player = 'o';
p1->head = NULL;
p2->head = NULL;
p1->numPieces = 0;
p2->numPieces = 0;

p2 = addPiece(p2, board, 1, 0, 0);
p2 = addPiece(p2, board, 3, 0, 0);
p2 = addPiece(p2, board, 5, 0, 0);
p2 = addPiece(p2, board, 7, 0, 0);
p2 = addPiece(p2, board, 0, 1, 0);
p2 = addPiece(p2, board, 2, 1, 0);
p2 = addPiece(p2, board, 4, 1, 0);
p2 = addPiece(p2, board, 6, 1, 0);
p2 = addPiece(p2, board, 1, 2, 0);
p2 = addPiece(p2, board, 3, 2, 0);
p2 = addPiece(p2, board, 5, 2, 0);
p2 = addPiece(p2, board, 7, 2, 0);

p1 = addPiece(p1, board, 0, 5, 0);
p1 = addPiece(p1, board, 2, 5, 0);
p1 = addPiece(p1, board, 4, 5, 0);
p1 = addPiece(p1, board, 6, 5, 0);
p1 = addPiece(p1, board, 1, 6, 0);
p1 = addPiece(p1, board, 3, 6, 0);
p1 = addPiece(p1, board, 5, 6, 0);
p1 = addPiece(p1, board, 7, 6, 0);
p1 = addPiece(p1, board, 0, 7, 0);
p1 = addPiece(p1, board, 2, 7, 0);
p1 = addPiece(p1, board, 4, 7, 0);
p1 = addPiece(p1, board, 6, 7, 0);

while (y < 8)
{
    while (x < 8)
    {
        board->spaces[x][y] = (SpacePtr)malloc(sizeof(Space));
        board->spaces[x][y]->Xcoord = x;
        board->spaces[x][y]->Ycoord = y;
        board->spaces[x][y]->player = ' '; //this makes it empty
        board->spaces[x][y]->isKing = 0;
        x++;
    }
    x = 0;
    y++;
}
return board;
}

void GameBoard::displayBoard(BoardPtr board, Print *top, Print *bottom)
{
consoleSelect(top);
consoleClear();

printf("    0   1   2   3   4   5   6   7  \n");
printf("  ---------------------------------");
printf("\n");

printf("0 | %c | %c | %c | %c", board->spaces[0][0]->player, board->spaces[1][0]->player,
       board->spaces[2][0]->player, board->spaces[3][0]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][0]->player, board->spaces[5][0]->player,
       board->spaces[6][0]->player, board->spaces[7][0]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("1 | %c | %c | %c | %c", board->spaces[0][1]->player, board->spaces[1][1]->player,
       board->spaces[2][1]->player, board->spaces[3][1]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][1]->player, board->spaces[5][1]->player,
       board->spaces[6][1]->player, board->spaces[7][1]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("2 | %c | %c | %c | %c", board->spaces[0][2]->player, board->spaces[1][2]->player,
       board->spaces[2][2]->player, board->spaces[3][2]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][2]->player, board->spaces[5][2]->player,
       board->spaces[6][2]->player, board->spaces[7][2]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("3 | %c | %c | %c | %c", board->spaces[0][3]->player, board->spaces[1][3]->player,
       board->spaces[2][3]->player, board->spaces[3][3]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][3]->player, board->spaces[5][3]->player,
       board->spaces[6][3]->player, board->spaces[7][3]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("4 | %c | %c | %c | %c", board->spaces[0][4]->player, board->spaces[1][4]->player,
       board->spaces[2][4]->player, board->spaces[3][4]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][4]->player, board->spaces[5][4]->player,
       board->spaces[6][4]->player, board->spaces[7][4]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("5 | %c | %c | %c | %c", board->spaces[0][5]->player, board->spaces[1][5]->player,
       board->spaces[2][5]->player, board->spaces[3][5]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][5]->player, board->spaces[5][5]->player,
       board->spaces[6][5]->player, board->spaces[7][5]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("6 | %c | %c | %c | %c", board->spaces[0][6]->player, board->spaces[1][6]->player,
       board->spaces[2][6]->player, board->spaces[3][6]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][6]->player, board->spaces[5][6]->player,
       board->spaces[6][6]->player, board->spaces[7][6]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");

printf("7 | %c | %c | %c | %c", board->spaces[0][7]->player, board->spaces[1][7]->player,
       board->spaces[2][7]->player, board->spaces[3][7]->player);
printf(" | %c | %c | %c | %c |", board->spaces[4][7]->player, board->spaces[5][7]->player,
       board->spaces[6][7]->player, board->spaces[7][7]->player);
printf("\n");
printf("  ---------------------------------");
printf("\n");
consoleSelect(bottom);
}

void GameBoard::refresh(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom)
{
system("cls");
updateBoard(board, p1, p2);
displayBoard(board, top, bottom);
}

int GameBoard::checkMove(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, int x, int y, int dir, bool isKing)
{
NodePtr tempNode = player->head;
char tempChar;
if (player->player == "x" || player->player == "X")
{ // if the passed player is p1
// check orientation (forward is up)
if (tempNode->next != null)
{
while (tempNode->x != &&tempNode->y != y)
tempNode = tempNode->next;
isKing = tempNode->isKing;

        if (tolower(board->spaces[x][y]->player) != tolower(player->player) || tolower(board->spaces[x][y]->player) != tolower(player->player))
        {
            cout << "Invalid move, please try again." << endl;
            return 0;
        }

        // check surroundings
        switch (dir)
        {
        case 1: // up - left
            if (isOut(x - 1, y - 1))
                return 0;                                                                //illegal direction; out of bounds
            if (tolower(board->spaces[x - 1][y - 1]->player) == tolower(player->player)) //also might fail with the current king implementation
                return 0;                                                                //illegal move; blocked by own piece
            if (tolower(board->spaces[x - 1][y - 1]->player) == ' ')
                return 1; //legal move
            else          //if this line is reached, the space is occupied by an enemy piece
                if (isOut(x - 2, y - 2))
                return 0; //illegal jump; out of bounds
            if (tolower(board->spaces[x - 2][y - 2]->player) == ' ')
                return 2; //legal jump; the move_() function is responsible for chaining jumps
            else
                return 0; //illegal jump; blocked by another piece
            break;

        case 2: //up-right or NE
            if (isOut(x + 1, y - 1))
                return 0;                                                                //illegal direction; out of bounds
            if (tolower(board->spaces[x + 1][y - 1]->player) == tolower(player->player)) //also might fail with the current king implementation
                return 0;                                                                //illegal move; blocked by own piece
            if (tolower(board->spaces[x + 1][y - 1]->player) == ' ')
                return 1; //legal move
            else          //if this line is reached, the space is occupied by an enemy piece
                if (isOut(x + 2, y - 2))
                return 0; //illegal jump; out of bounds
            if (tolower(board->spaces[x + 2][y - 2]->player) == ' ')
                return 2; //legal jump; the move_() function is responsible for chaining jumps
            else
                return 0; //illegal jump; blocked by another piece
            break;
        case 3: //down-left or SW
            if (isOut(x - 1, y + 1))
                return 0; //illegal direction; out of bounds
            if (isKing)
            {
                if (tolower(board->spaces[x - 1][y + 1]->player) == tolower(player->player)) //also might fail with the current king implementation
                    return 0;                                                                //illegal move; blocked by own piece
                if (tolower(board->spaces[x - 1][y + 1]->player) == ' ')
                    return 1; //legal move
                else          //if this line is reached, the space is occupied by an enemy piece
                    if (isOut(x - 2, y + 2))
                    return 0; //illegal jump; out of bounds
                if (tolower(board->spaces[x - 2][y + 2]->player) == ' ')
                    return 2; //legal jump; the move_() function is responsible for chaining jumps
                else
                    return 0; //illegal jump; blocked by another piece
            }
            else
                return 0; //kings can't move backwards
            break;
        case 4: //down-right or SE
            if (isOut(x + 1, y + 1))
                return 0; //illegal direction; out of bounds
            if (isKing)
            {
                if (tolower(board->spaces[x + 1][y + 1]->player) == tolower(player->player)) //also might fail with the current king implementation
                    return 0;                                                                //illegal move; blocked by own piece
                if (tolower(board->spaces[x + 1][y + 1]->player) == ' ')
                    return 1; //legal move
                else          //if this line is reached, the space is occupied by an enemy piece
                    if (isOut(x + 2, y + 2))
                    return 0; //illegal jump; out of bounds
                if (tolower(board->spaces[x + 2][y + 2]->player) == ' ')
                    return 2; //legal jump; the move_() function is responsible for chaining jumps
                else
                    return 0; //illegal jump; blocked by another piece
            }
            else
                return 0; //kings can't move backwards
            break;
        }
    }
    //end of p1-case
    //beginning of p2-case (now 'forward' is down)
    else if (player->player == 'o' || player->player == 'O')
    {
        if (tempNode->next != NULL)
            while (tempNode->x != x && tempNode->y != y)
                tempNode = tempNode->next;
        isKing = tempNode->isKing;
        //first, check that the player owns the piece
        if (tolower(board->spaces[x][y]->player) != tolower(player->player) || tolower(board->spaces[x][y]->player) != tolower(player->player))
        { //this prob won't work with kings if we're still using capitals
            printf("That's not your piece to move!\n");
            return 0;
        }
    }
}
}

int GameBoard::isOut(int x, int y)
{
if (x < 0 || x > 7 || y < 0 || y > 7)
return 1;
return 0;
}

void Gameboard::refresh(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, Print *top, Print *bottom)
{
system("cls");
updateBoard(board, p1, p2);
displayBoard(board, top, bottom);
}

void Gameboard::updateBoard(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2)
{
NodePtr tempNode;

int x, y;

for (y = 0; y < 8; y++)
{
    for (x = 0; x < 8; x++)
    {
        board->spaces[x][y]->player = ' ';
    }
}

tempNode = p1->head;

while (tempNode != null)
{
    board->spaces[tempNode->x][tempNode->y]->player = p1->player;
    if (tempNode->isKing == 1)
    {
        board->spaces[tempNode->x][tempNode->y]->player = 'X';
    }
    tempNode = tempNode->next;
}

tempNode = p2->head;

while (tempNode != null)
{
    board->spaces[tempNode->x][tempNode->y]->player = p2->player;
    if (tempNode->isKing == 1)
    {
        board->spaces[tempNode->x][tempNode->y]->player = 'O';
    }
    tempNode = tempNode->next;
}

return;
}
