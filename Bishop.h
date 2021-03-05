#ifndef Bishop_h
#define Bishop_h
#include "Piece.h"
#include <vector>
#include <string>
#include "Location.h"


class Bishop : public Piece {

 public:
  Bishop(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

  PieceType getPieceType() const override { return PieceType::Bishop; }

 private:
  Location movePiece(uint8_t, uint8_t, uint8_t) override;

};

#endif // Bishop_h
