#ifndef Square_h
#define Square_h
#include <string>
#include "Piece.h"

class Square {

 public:
  Square();
  /**
   * Creates a Square, based on it's color and the current |Piece| it holds.
   */
  Square(bool);

  /**
   * Changes the piece on a Square.
   */
  void newPiece(Piece);

  /**
   * Returns the character string for the current |Piece| on the |Square|.
   */
  std::string getPiece(void);

 private:
  bool isWhite;
  Piece currentPiece;

};

#endif // Square_h
