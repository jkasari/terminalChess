#ifndef King_h
#define King_h
#include "Piece.h"
#include <vector>
#include <string>
#include "Location.h"



class King : public Piece {

 public:
  King(Color color) : Piece(color) {}
    /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location) override;

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  std::string getTerminalDisplay(void) const override;

};

#endif // King_h
