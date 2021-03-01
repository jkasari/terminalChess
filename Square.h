#ifndef Square_h
#define Square_h
#include "Piece.h"

class Square {

 public:
  /**
   * Creates a Square, based on it's color and the current |Piece| it holds.
   */
  Square(bool, Piece);

  /**
   * Changes the piece on a Square.
   */
  void newPiece(Piece);

 private:
  const bool isWhite;
  Piece currentPiece;

};

#endif // Square_h
