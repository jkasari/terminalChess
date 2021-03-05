#ifndef Piece_h
#define Piece_h
#include <vector>
#include <string>
#include "Location.h"


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

class Piece {

 public:

  Piece() : Piece(Color::White) {}

  Piece(Color color) : color(color) {}

  Color getColor() const;

  /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  virtual std::vector<Location> potentialMoves(Location) { return std::vector<Location>(); };

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  virtual std::string getTerminalDisplay() const { return " "; }

  /**
   * Returns the |PieceType|.
   */
  virtual PieceType getPieceType() const {
    return PieceType::King;
  }

 private:
  Color color;


};

#endif // Piece_h
