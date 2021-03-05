#ifndef Location_h
#define Location_h
#include <string>

struct Location {

  Location() {}

  Location(uint8_t row, uint8_t col) {
      this->row = row;
      this->col = col;
  }

  uint8_t row = 0;
  uint8_t col = 0;

};

#endif // Location_h
