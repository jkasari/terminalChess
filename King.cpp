#include "King.h"

  std::vector<Location> King::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string King::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9A";
    } else {
      return "\xE2\x99\x94";
    }
  }

  Location King::movePiece(uint8_t direction, Location location) {}