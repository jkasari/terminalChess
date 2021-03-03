#ifndef Rook_h
#define Rook_h
#include <vector>
#include <string>
#include "Piece.h"

using Location = std::pair<int8_t, int8_t>;

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

};

#endif // Rook_h
