#ifndef Square_h
#define Square_h
#include <string>
#include "Piece.h"

class Square {

 public:
  Square() {}

  /**
   * Changes the piece on a Square.
   */
  void newPiece(Piece*);

  /**
   * Returns the character string for the current |Piece| on the |Square|.
   */
  std::string getPieceDisplay(void) const;

  Piece* getPiecePointer();

 private:
  Piece* currentPiece = nullptr;

};

#endif // Square_h
