#ifndef Parser_h
#define Parser_h
#include "Move.h"
#include "Piece.h"
#include "Location.h"
#include <vector>

enum class ParseError {
  InvalidPiece,
  InvalidLocation,

};

std::ostream& operator<<(std::ostream& stream, const ParseError& err);

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

  static PieceType parsePieceType(const std::string&);

  static Location parseLocation(const std::string&);

 private:
  static std::string toLower(const std::string&);

};

#endif // Parser_h
