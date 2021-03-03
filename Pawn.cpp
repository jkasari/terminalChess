#include "Pawn.h"


  std::vector<Location> Pawn::potentialMoves(Location) {

  }

  std::string Pawn::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9F";
    } else {
      return "\xE2\x99\x99";
    }
  }