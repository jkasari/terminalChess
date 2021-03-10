#include "Rook.h"


  std::vector<Location> Rook::potentialMoves(Location location) {
    std::vector<Location> moves;
    Location potentialMove = location;
    uint8_t boardLimit = location.row;
    for(int moveIndex = 0; moveIndex < 4; ++moveIndex) {
      while(0 <= boardLimit && boardLimit < 8) {
        moves.push_back(potentialMove);
        potentialMove = movePiece(moveIndex, potentialMove);
        boardLimit = potentialMove.row;
      }
      potentialMove = location;
    }
    return moves;
  }

  std::string Rook::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9C";
    } else {
      return "\xE2\x99\x96";
    }
  }


  Location Rook::movePiece(uint8_t direction, Location location) {
    uint8_t row = location.row;
    uint8_t col = location.col;
    if(direction > 3) {
      return Location(0, 0);
    }
    switch(direction) {
     case 0: return Location(row + 1, col);
     case 1: return Location(row, col - 1);
     case 2: return Location(row - 1, col);
     case 3: return Location(row, col - 1);
    }
    return Location(0, 0);
  }
