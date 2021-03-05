#include "Queen.h"


  std::vector<Location> Queen::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string Queen::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9B";
    } else {
      return "\xE2\x99\x95";
    }
  }

  Location Queen::movePiece(uint8_t dirction, uint8_t row, uint8_t col) {}