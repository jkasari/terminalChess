#include "Bishop.h"


  std::vector<Location> Bishop::potentialMoves(Location location) {
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

  std::string Bishop::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9D";
    } else {
      return "\xE2\x99\x97";
    }
  }

Location Bishop::movePiece(uint8_t direction, Location location) {
  uint8_t row = location.row;
  uint8_t col = location.col;
  if(direction > 3) {
    return Location(0, 0);
  }
  switch(direction) {
   case 0: return Location(row + 1, col + 1);
   case 1: return Location(row + 1, col - 1);
   case 2: return Location(row - 1, col + 1);
   case 3: return Location(row - 1, col - 1);
  }
  return Location(0, 0);
}