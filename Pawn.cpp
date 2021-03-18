#include "Pawn.h"

  std::vector<Location> Pawn::potentialMoves(Location location) {
    std::vector<Location> moves;
    Location potentialMove = location;
    uint8_t boardLimit = location.row;
    for(int moveIndex = 0; moveIndex < 4; ++moveIndex) {
        moves.push_back(potentialMove);
        potentialMove = movePiece(moveIndex, potentialMove);
        moves.push_back(potentialMove);
        potentialMove = location;
      }
    return moves;
  }

  std::string Pawn::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9F";
    } else {
      return "\xE2\x99\x99";
    }
  }

  Location Pawn::movePiece(uint8_t direction, Location location) {
    uint8_t row = location.row;
    uint8_t col = location.col;
    if(direction > 7) {
      return Location(0, 0);
    }
    if(getColor() == Color::White) {
      switch(direction) {
       case 0: return Location(row - 1, col);
       case 1: return Location(row - 2, col);
       case 2: return Location(row - 1, col + 1);
       case 3: return Location(row - 1, col - 1);
      }
    } else {
      switch(direction) {
        case 0: return Location(row + 1, col);
        case 1: return Location(row + 2, col);
        case 2: return Location(row + 1, col + 1);
        case 3: return Location(row + 1, col - 1);
      }
    }
    return Location(0, 0);
  }