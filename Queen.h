#ifndef Queen_h
#define Queen_h
#include <vector>
#include <string>
#include "Piece.h"
#include "Location.h"


class Queen : public Piece {

 public:
  Queen(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

  PieceType getPieceType() const override { return PieceType::Queen; }

 private:
  /**
   * Helper function that virtually moves the piece.
   */
  Location movePiece(uint8_t, uint8_t, uint8_t) override;

};

#endif // Queen_h
