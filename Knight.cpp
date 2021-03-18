#include "Knight.h"


  std::vector<Location> Knight::potentialMoves(Location location) {
    std::vector<Location> moves;
    Location potentialMove = location;
    uint8_t boardLimit = location.row;
    for(int moveIndex = 0; moveIndex < 8; ++moveIndex) {
      moves.push_back(potentialMove);
      potentialMove = movePiece(moveIndex, potentialMove);
      moves.push_back(potentialMove);
      potentialMove = location;
    }
    return moves;
  }

  std::string Knight::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9E";
    } else {
      return "\xE2\x99\x98";
    }
  }



  Location Knight::movePiece(uint8_t direction, Location location) {
    uint8_t row = location.row;
    uint8_t col = location.col;
    if(direction > 7) {
      return Location(0, 0);
    }
    switch(direction) {
     case 0: return Location(row + 2, col + 1);
     case 1: return Location(row + 2, col - 1);
     case 2: return Location(row - 2, col + 1);
     case 3: return Location(row - 2, col - 1);
     case 4: return Location(row + 1, col + 2);
     case 5: return Location(row - 1, col + 2);
     case 6: return Location(row + 1, col - 2);
     case 7: return Location(row - 1, col - 2);
    }
    return Location(0, 0);
  }