#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "Move.h"
#include "Parser.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("Parser") {
    Parser parsy;
    unit_test("Valid Parse") may_throw({
      Move move1 = parsy.parseMove("Knight A1 A2");
      assert_eq(PieceType::Knight, move1.getPiece());
      assert_eq(7, move1.getFromLocation().row);
      assert_eq(0, move1.getFromLocation().col);
      assert_eq(6, move1.getToLocation().row);
      assert_eq(0, move1.getToLocation().col);
    })
    unit_test("Invalid Piece") {
      try {
        Move move1 = parsy.parseMove("Kite A1 A2");
        fail_test("Expected throw");
      } catch(const ParseError& parseError) {
        assert_eq(parseError, ParseError::InvalidPiece);
      }
    }
  }

  summary();
}

