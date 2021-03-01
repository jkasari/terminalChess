#ifndef Move_h
#define Move_h
#include "Piece.h"

using Location = std::pair<int8_t, int8_t>

class Move {

 public:
  /**
   * Creates a move based on a piece and preposed location.
   * This takes the locations in chess notation. It stores them as a |Location|.
   */
  Move(Piece, char[2], char[2]);

  /**
   * Returns the moves |Location|;
   */
  Location getLocation(void);

  /**
   * Returns the |Piece| in the next move.
   */
  Piece getPiece(void);

 private:
  Piece pieceToMove;
  Location newLocation;

};

#endif // Move_h
