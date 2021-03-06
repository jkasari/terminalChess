#include "King.h"

  std::vector<Location> King::potentialMoves(Location location) {
    std::vector<Location> moves;
    Location potentialMove = location;
    uint8_t boardLimit = location.row;
    for(int moveIndex = 0; moveIndex < 8; ++moveIndex) {
      moves.push_back(potentialMove);
      potentialMove = movePiece(moveIndex, potentialMove);
      moves.push_back(potentialMove);
      potentialMove = location;
    }
    if (canCastle) {
      uint8_t row = location.row;
      uint8_t col = location.col;
      moves.push_back(Location(row, col + 2));
      moves.push_back(Location(row, col - 2));
    }
    return moves;
  }

  std::string King::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9A";
    } else {
      return "\xE2\x99\x94";
    }
  }

  Location King::movePiece(uint8_t direction, Location location) {
    uint8_t row = location.row;
    uint8_t col = location.col;
    if(direction > 7) {
      return location;
    }
    switch(direction) {
     case 0: return Location(row + 1, col + 1);
     case 1: return Location(row + 1, col - 1);
     case 2: return Location(row - 1, col + 1);
     case 3: return Location(row - 1, col - 1);
     case 4: return Location(row, col + 1);
     case 5: return Location(row, col - 1);
     case 6: return Location(row + 1, col);
     case 7: return Location(row - 1, col);
    }
    return location;
  }