#include "King.h"

  std::vector<Location> King::potentialMoves(Location) {

  }

  std::string King::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9A";
    } else {
      return "\xE2\x99\x94";
    }
  }
