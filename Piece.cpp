#include "Piece.h"
std::ostream& operator<<(std::ostream& stream, const PieceType& pieceType) {
  switch (pieceType) {
    case PieceType::King:   return stream << "King";
    case PieceType::Queen:  return stream << "Queen";
    case PieceType::Rook:   return stream << "Rook";
    case PieceType::Bishop: return stream << "Bishop";
    case PieceType::Knight: return stream << "Knight";
    case PieceType::Pawn:   return stream << "Pawn";
  }
  return stream;
}

Color Piece::getColor() const {
  return color;
}