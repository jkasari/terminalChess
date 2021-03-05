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

  cout << board << endl;

  while(1) {

    try {
      if(board.whosTurn() == Color::White) {
        cout << "Your move white:" << endl;
      } else {
        cout << "Your move black:" << endl;
      }
      getline(cin, moveInput);

      nextMove = parsy.parseMove(moveInput);
      board.executeMove(nextMove);

      // This just clears the terminal for the next board to be broadcasted.
      for(int i = 0; i < 100; ++i) {
        cout << endl;
      }

      cout << board << endl;
      board.switchSides();
    } catch(const ParseError& parseError) {
      switch (parseError) {
        case ParseError::InvalidPiece: cout << endl << "!!! Invalid Piece !!!" << endl; break;
        case ParseError::InvalidLocation: cout << endl << "!!! Invalid Location !!!" << endl; break;
      }
      cout << endl << "Moves must be on the board and in the following form:" << endl << endl;
      cout << "     \"Piece A1 A2\"" << endl << endl;
    } catch (const BoardError& boardError) {
      switch (boardError) {
        case BoardError::MoveNotPossible: cout << endl << "!!! This Move is not Possible !!!"; break;
        case BoardError::FriendlyFire: cout << endl << "!!! Friendly Fire !!!"; break;
        case BoardError::IncorrectColor: cout << endl << "!!! Piece Must be your Color !!!"; break;
      }
      cout << endl << endl;
    }

  }
  return 0;
}
