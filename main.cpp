#include <iostream>
#include "ChessBoard.h"
#include "Move.h"
#include "Parser.h"

using namespace std;

int main() {
  ChessBoard board;
  Parser parsy;
  Move nextMove;
  string moveInput;
  uint32_t cycle = 0;

  while(1) {
  for(int i = 0; i < 100; ++i) {
    cout << endl;
  }
  cout << board << endl;

  if(cycle % 2 == 0) {
    cout << "Your move white:" << endl;
  } else {
    cout << "Your move black:" << endl;
  }
  getline(cin, moveInput);
  nextMove = parsy.parseMove(moveInput);
  board.executeMove(nextMove);
  cycle++;
  }


  return 0;
}
