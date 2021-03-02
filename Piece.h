#ifndef Piece_h
#define Piece_h
#include <vector>
#include <string>

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
  std::string getTerminalDisplay(void) const;

 private:
  bool Color;
  char* terminalDisplay = {"\xE2\x99\x9B"};

};

#endif // Piece_h
