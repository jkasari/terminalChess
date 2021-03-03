#include "Knight.h"


  std::vector<Location> Knight::potentialMoves(Location) {

  }

  std::string Knight::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9E";
    } else {
      return "\xE2\x99\x98";
    }
  }