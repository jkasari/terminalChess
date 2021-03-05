#ifndef Move_h
#define Move_h
#include <string>
#include "Location.h"

class Move {

 public:
 Move() {}
  /**
   * Creates a move based on a piece and preposed location.
   * This takes the locations in chess notation. It stores them as a |Location|.
   */
  Move(std::string);

  /**
   * Returns the |Location| that the |Piece| is moving to.
   */
  Location getMoveToLocation();

  /**
   * Returns the |Location| that the |Piece| is moving from.
   */
  Location getMoveFromLocation();

  /**
   * Returns the |Piece| in the next move.
   */
  std::string getPiece();

 private:
  /**
   * Breaks of the name of the |Piece| off of the string used to create the |Move|.
   */
  std::string extractPieceName(std::string);

  /**
   * Takes a string of two chars representing chessnotation and returns a |Location|.
   */
  Location notationToLocation(std::string);

  /**
   * Pulls the second argument out of a string. This argument needs to be chess notation.
   * Such as "E4" or "B7".
   */
  Location extractFirstLocation(std::string);

  /**
   * Pulls the second argument out of a string. This argument needs to be in chess notation.
   * Such as "E4" or "B7".
   */
  Location extractSecondLocation(std::string);

  std::string pieceToMove;
  Location moveToLocation;
  Location moveFromLocation;

};

#endif // Move_h
