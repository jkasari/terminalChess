#ifndef Parser_h
#define Parser_h
#include "Move.h"
#include <vector>

class Parser {

 public:
  Move parseMove(const std::string&) const;


 private:
  /**
   * Makes sure the first argument is a valid piece to move.
   */
  bool validPieceCheck(char[6]);

  /**
   * Makes sure the second two arguments are valid locations.
   */
  bool validLocationCheck(char[2], char[2]);

};

#endif // Parser_h
