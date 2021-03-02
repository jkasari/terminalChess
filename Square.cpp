#include "Square.h"

Square::Square() {
  isWhite = true;
}

Square::Square(bool white) {
  isWhite = white;
  //currentPiece = newPiece;
}

void Square::newPiece(Piece newPiece) { currentPiece = newPiece; }

std::string Square::getPieceDisplay(void) const { return currentPiece.getTerminalDisplay(); }
