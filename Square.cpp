#include "Square.h"

void Square::newPiece(Piece* newPiece) { currentPiece = newPiece; }

std::string Square::getPieceDisplay(void) const {
  if(currentPiece) {
    return currentPiece->getTerminalDisplay();
  } else {
    return " ";
  }
}
