#include "Square.h"

Square::Square() {
  //currentPiece = newPiece;
}

void Square::newPiece(Piece newPiece) { currentPiece = newPiece; }

std::string Square::getPieceDisplay(void) const { return currentPiece.getTerminalDisplay(); }
