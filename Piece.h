#ifndef Piece_h
#define Piece_h
#include <vector>
#include <string>
#include "Location.h"
#include <iostream>


enum class Color {
  Black,
  White,
};

enum class PieceType {
  King,
  Queen,
  Rook,
  Bishop,
  Knight,
  Pawn,
};
std::ostream& operator<<(std::ostream& stream, const PieceType& pieceType);


class Piece {

 public:

  Piece() : Piece(Color::White) {}

  Piece(Color color) : color(color) {}

  Color getColor() const;

  /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  virtual std::vector<Location> potentialMoves(Location) = 0;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  virtual std::string getTerminalDisplay() const = 0;

  /**
   * Returns the |PieceType|.
   */
  virtual PieceType getPieceType() const = 0;

 protected:
  /**
   * Helper function that virtually moves the piece.
   */
  virtual Location movePiece(uint8_t, Location) = 0;

 private:
  Color color;


};

#endif // Piece_h
