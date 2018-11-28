#include "Classes.h"
#include "Player.cpp"
#include "Board.cpp"

using namespace std;

int main() {
  Board game;
  bool on = true;
  cout << "Welcome to ASCII checkers! ";
  while (on){
  game.CPUPlayer(true);
  game.gameLoop();
  }
  return 0;
}
