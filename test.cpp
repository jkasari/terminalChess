#include <iostream>
#include "nuttiest/nuttiest.hpp"
#include "Move.h"

using namespace std;
using namespace nuttiest;

int main() {
  section("Making Moves Player!!") {
    unit_test("Making Moves") {
      std::string terminalCommand = ("Knight A1 A2");
      Move move1(terminalCommand);
      assert_eq("Knight", move1.getPiece());
      assert_eq(0, move1.getMoveToLocation().row);
      assert_eq(0, move1.getMoveToLocation().col);
    }
  }

  summary();
}

