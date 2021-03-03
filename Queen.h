#ifndef Queen_h
#define Queen_h
#include <vector>
#include <string>
#include "Piece.h"

using Location = std::pair<int8_t, int8_t>;

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

 private:
  const std::string terminalDisplay = {"\xE2\x99\x9B"};

};

#endif // Queen_h
