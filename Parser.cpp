#include "Parser.h"

Move Parser::parseMove(const std::string& input) const {
    int32_t index = 0;
    std::string pieceName;
    while(input[index] != ' ') {
        pieceName += input[index];
        index++;
    }

    std::string fromLocation;
    fromLocation += input[index + 1];
    fromLocation += input[index + 2];

    std::string toLocation;
    toLocation += input[index + 4];
    toLocation += input[index + 5];


}