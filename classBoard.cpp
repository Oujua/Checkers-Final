#include <iostream>
#include "checkersClasses.h"
using namespace std;

Board::Board()
{
    // draw the board;
    cout << "I initialize the board" << endl;
}

Board::~Board()
{
    // free up space;
    cout << "I destruct the board and free up memory" << endl;
}

void Board::displayBoard()
{
    // display the board;
    cout << "I display the board" << endl;
}

void Board::checkMove()
{
    // input validation of each move;
    isOut();
    cout << "I check a player/computer's move" << endl;
}

bool isOut()
{
    // check if a move is out of bounds;
    cout << "Move is out of bounds" << endl;
}

void Board::removePiece()
{
    // Remove jumped peices;
    cout << "I remove jumped pieces" << endl;
}

void Board::updateBoard()
{
    // update the board as the game progresses;
    cout << "I update the board as the game progresses" << endl;
}
void Player::makeMove()
{
    // make a players move;
    cout << "I allow players to make a move." << endl;
}
double Board::minimax()
{
    // minimax algo to maximize players chances while minimizing opponents chances
    cout << "I am minimax" << endl;
}
void Board::checkStatus(){
    // check the status of the game
    // such as piece count
    // number of kings, etc
    cout << "Status update" << endl;
}