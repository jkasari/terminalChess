#include "Bishop.h"


  std::vector<Location> Bishop::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string Bishop::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9D";
    } else {
      return "\xE2\x99\x97";
    }
  }