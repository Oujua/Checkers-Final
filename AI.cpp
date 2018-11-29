#include "AI.h"
#include <iostream>
using namespace std;

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
Player(string name, Side side);
virtual GameStats makeMove(Move move, Board board);
Side getSide();
AI(string name, Side side) : Player(name, side) { depth = 3; };
GameStats makeMove(Board board);
Move minimaxStart(Board board, Side side, bool maximing);
double minimax(Board board, Side side, bool maximing, int depth, int alpha, int beta);
double getHeuristicValues(Board board);
Side switchSide(Side side);

int main(){
    cout << " Welcome to AI Checkers! " << endl;
    char response;

    do {
        Game();
        do {
            cout << " Type [Yes] to keep playing. Type [No] to exit ";
            cin >> response;
        }   while (!(response == 'Yes' || response == 'No'));
    }   while (response == 'Yes');


    return 0;
}

void Game() {
    Side player = blackSide;
    Side cpu = whiteSide;
    string name;
    cout << " Enter your name: " << endl;
    cin >> name;
    Player first(name, player);
    AI second("cpu", cpu);

    bool playerTurn = true;
    Board board;
    GameStats message = complete;

    while (message != gameOver) {
        cout << endl << endl;
        
        board.drawBoard();
        if (!playerTurn) {
            system("pause");
        }

        if (playerTurn) {
            vector<Move> playerMoves;
            board.generateMoves(first.getSide(), playerMoves);
            if (playerMoves.empty()) {
                cout << " No possible moves, game over" << endl;
                break;
            } 
            else {
                int numOfMoves = playerMoves.size();
                cout << " Possible moves: " << endl;
                for (int i = 0; i < numOfMoves; i++) {
                    printMove(playerMoves[i]);
                }
                cout << endl << endl;
            }
            Move move;
            do {
                cout << " Enter desired move: x1_y1_x2_y2 " << endl;
                cin >> move.start.column >> move.start.row >> move.end.column >> move.end.row;
                message = first.makeMove(move, board);

                if (message == invalidDest) {
                    cout << "Invalid move" << endl;
                } else if (message != complete && message != gameOver);
                  playerTurn = !playerTurn;
            } else {
                vector<Move> minimaxMoves;
                board.generateMoves(second.getSide(), minimaxMoves);
                if (minimaxMoves.empty()) {
                    cout << "You win!" << endl;
                }
                message = first.makeMove(board);
                playerTurn = !playerTurn;
            }
        }
    }
}

void printMove(Move x) {
    cout << "Move: [" << x.start.column << ", " << x.start.row << "] " << " ---> [" << x.end.column << ", " << x.end.row << "]" << endl;
}

Side AI::switchSide(Side side) {
    if (side == blackSide) {
        return whiteSide;
    }
    return blackSide;
}

double AI::getHeuristicValues(Board board) {
    double kingWeight = 1.5;
    if (getSide() == blackSide) {
        return (kingWeight * board.getNumBlackKings() + board.getNumBlackPieces()) - (kingWeight * board.getNumWhiteKings() + board.getNumWhitePieces());
    }
    return (kingWeight * board.getNumWhiteKings() + board.getNumWhitePieces()) - (kingWeight * board.getNumBlackKings() + board.getNumBlackPieces());
}

double AI::minimax(Board board, Side side, bool maximing, int depth, int alpha, int beta) {
    if (depth == 0) {
        return getHeuristicValues(board);   // terminal condition
    }

    vector<Move> possibleMoves;
    board.generateMoves(side, possibleMoves);
    int n = possibleMoves.size();
    int init = 0;
    Board temp;

    if (maximing) {
        for (int i = 0; i < n; i++) {
            temp = *board.clone();
            GameStats status = temp.makeMove(possibleMoves[i], side);
            if (status != complete && status != gameOver) {
                continue;
            }
            int result = minimax(temp, switchSide(side), !maximing, depth - 1, alpha, beta);
            init = max(result, init);
            alpha = max(init, alpha);
            if (alpha > beta) {
                break;
            } 
        }
    } else {
        init = 1000;
        for (int i = 0; i < n: i++) {
            temp = *board.clone();
            GameStats status = temp.makeMove(possibleMoves[i], side);
            if (status != complete && status != gameOver) {
                continue;
            }
            int result = minimax(temp, switchSide(side), !maximing, depth - 1, alpha, beta);
            init = max(result, init);
            alpha = max(init, alpha);
            if (alpha > beta) {
                break;
        }
    }
}
    return init;
}


