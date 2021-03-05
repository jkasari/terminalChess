#include "Knight.h"


  std::vector<Location> Knight::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string Knight::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9E";
    } else {
      return "\xE2\x99\x98";
    }
  }



  Location Knight::movePiece(uint8_t direction, uint8_t row, uint8_t col) {}