#include "Move.h"


Move::Move(PieceType pieceToMoveInput, Location fromLocationInput, Location toLocationInput) {
    pieceToMove = pieceToMoveInput;
    moveFromLocation = fromLocationInput;
    moveToLocation = toLocationInput;
}

Location Move::getToLocation() const {
    return moveToLocation;
}

Location Move::getFromLocation() const {
    return moveFromLocation;
}


PieceType Move::getPiece() const {
  return pieceToMove;
}
