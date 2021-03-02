#ifndef Referee_h
#define Referee_h
#include <vector>

struct Referee {

  /**
   * Checks to make sure you typed the correct amount of arguments.
   */
  bool correctNumberOfArgs(uint8_t);

  /**
   * Makes sure the first argument is a valid piece to move.
   */
  bool validPieceCheck(char[6]);

  /**
   * Makes sure the second two arguments are valid locations.
   */
  bool validLocationCheck(char[2], char[2]);

};

#endif // Referee_h
