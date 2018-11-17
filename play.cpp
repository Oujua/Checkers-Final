#include
#include <string.h>
#include "playerClass.h"
#include "GameBoardclass.h"

using namespace std;

int main (){

BoardPtr board;
    NodePtr temp;
    int x, y, ext;
LinkedListPtr p1, p2;

p1 = (LinkedListPtr)malloc(sizeof(LinkedList));
p2 = (LinkedListPtr)malloc(sizeof(LinkedList));

board = initBoard(p1, p2);
system("cls");
updateBoard(board, p1, p2);
displayBoard(board, top, bottom);

while()


return 0;
}
