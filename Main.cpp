#include "Classes.h"
#include "Player.cpp"
#include "Board.cpp"

using namespace std;

int main() {
  Board game;
  char input;
  while (input != 'Y' && input != 'N') {
    cout << "Would you like to play against a CPU? Y/N\n";
    cin >> input;
  }
  if (input == 'Y') {
    game.CPUPlayer(true);
  } else {
    game.CPUPlayer(false);
  }
  game.game();
  return 0;
}
