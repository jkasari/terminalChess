#include "Square.h"



Square::Square(bool white, Piece newPiece) : isWhite(white) {
  currentPiece = newPiece;
}

void Square::newPiece(Piece newPiece) { currentPiece = newPiece; }

std::string Square::getPiece(void) { return " "; }
