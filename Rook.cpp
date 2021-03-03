#include "Rook.h"


  std::vector<Location> Rook::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string Rook::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9C";
    } else {
      return "\xE2\x99\x96";
    }
  }