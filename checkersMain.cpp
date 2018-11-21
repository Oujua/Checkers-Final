#include <iostream>
#include "checkersClasses.h"

using namespace std;

int main()
{

    cout << "Welcome to Human vs Computer Checkers!" << endl
         << endl;

    string name;
    cout << "Please enter your name: " << endl
         << endl;
    cin >> name;
    cout << "Good Luck " << name << "!" << endl;

    Player U; //User
    Player C; //Computer
    Board thisBoard;

    thisBoard.displayBoard();

    bool on; // game on
    int moves = 0;

    while (moves <= 32)
    {
        U.minimax();
        U.makeMove();
        thisBoard.checkMove();
        moves++;
        C.minimax();
        C.makeMove();
        thisBoard.checkMove();
        moves++;
        thisBoard.checkStatus();
    }

    // basic flow of how this will work
    // this will be more intricate once functions are built

    return 0;
}