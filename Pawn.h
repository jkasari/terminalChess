#ifndef Pawn_h
#define Pawn_h
#include "Piece.h"
#include <vector>
#include <string>
#include "Location.h"


class Pawn : public Piece {

 public:
  Pawn(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

  PieceType getPieceType() const override { return PieceType::Pawn; }

 private:
  /**
   * Helper function that virtually moves the piece.
   */
  Location movePiece(uint8_t, Location) override;

};

#endif // Pawn_h
