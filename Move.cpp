#include "Move.h"


Move::Move(PieceType pieceToMoveInput, Location fromLocationInput, Location toLocationInput) {
    pieceToMove = pieceToMoveInput;
    moveFromLocation = fromLocationInput;
    moveToLocation = toLocationInput;
}

Location Move::getMoveToLocation() const {
    return moveToLocation;
}

Location Move::getMoveFromLocation() const {
    return moveFromLocation;
}


PieceType Move::getPiece() const {
  return pieceToMove;
}
