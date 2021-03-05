#ifndef Rook_h
#define Rook_h
#include <vector>
#include <string>
#include "Piece.h"
#include "Location.h"


class Rook : public Piece {

 public:
  Rook(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

  PieceType getPieceType() const override { return PieceType::Rook; }

 private:
  /**
   * Helper function that virtually moves the piece.
   */
  Location movePiece(uint8_t, uint8_t, uint8_t) override;


};

#endif // Rook_h
