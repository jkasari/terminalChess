#ifndef Piece_h
#define Piece_h
#include <vector>

using Location = std::pair<int8_t, int8_t>;

class Piece {

 public:
  /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location);

  /**
   * Returns how the piece would like to be displayed in the terminal.
   */
  char* getTerminalDisplay(void);

 private:
  bool Color;
  char terminalDisplay[10];

};

#endif // Piece_h
