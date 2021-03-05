#ifndef Move_h
#define Move_h
#include <string>
#include "Location.h"
#include "Piece.h"

class Move {

 public:
 Move() {}
  /**
   */
  Move(PieceType, Location, Location);

  /**
   * Returns the |Location| that the |Piece| is moving to.
   */
  Location getToLocation() const;

  /**
   * Returns the |Location| that the |Piece| is moving from.
   */
  Location getFromLocation() const;

  /**
   * Returns the |Piece| in the next move.
   */
  PieceType getPiece() const;

 private:
  PieceType pieceToMove;
  Location moveToLocation;
  Location moveFromLocation;

};

#endif // Move_h
