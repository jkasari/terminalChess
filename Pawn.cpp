#include "Pawn.h"

  std::vector<Location> Pawn::potentialMoves(Location) {
    return std::vector<Location>();
  }

  std::string Pawn::getTerminalDisplay(void) const {
    if(getColor() == Color::White) {
      return "\xE2\x99\x9F";
    } else {
      return "\xE2\x99\x99";
    }
  }

  Location Pawn::movePiece(uint8_t direction, uint8_t row, uint8_t col) {}