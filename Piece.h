#ifndef Piece_h
#define Piece_h
#include <vector>

using Location = std::pair<int8_t, int8_t>

class Piece {

 public:
  /**
  * Returns the phsical moves a piece can make. This does factor in the board, but not other peices.
  */
  std::vector<Location> potentialMoves(Location);


 private:
  bool Color;

};

#endif // Piece_h
