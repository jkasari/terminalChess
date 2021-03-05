#include "Bishop.h"


  std::vector<Location> Bishop::potentialMoves(Location location) {
    uint8_t row = location.row;
    uint8_t col = location.col;
    std::vector<Location> moves;
    while(0 <= row && row < 8) {
      row++;
      col++;
    }
  }

  std::string Bishop::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9D";
    } else {
      return "\xE2\x99\x97";
    }
  }

Location Bishop::movePiece(uint8_t direction, uint8_t row, uint8_t col) {
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