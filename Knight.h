#ifndef Knight_h
#define Knight_h
#include "Piece.h"
#include <vector>
#include <string>
#include "Location.h"


class Knight : public Piece {

 public:
  Knight(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

  PieceType getPieceType() const override { return PieceType::Knight; }

  private:
   static PieceType pieceType;

};

#endif // Knight_h
