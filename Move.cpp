#include "Move.h"


Move::Move(std::string terminalCommand) {
    pieceToMove = extractPieceName(terminalCommand);
    moveToLocation = extractFirstLocation(terminalCommand);
    moveFromLocation = extractSecondLocation(terminalCommand);
}

Location Move::getMoveToLocation(void) {
    return moveToLocation;
}

Location Move::getMoveFromLocation(void) {
    return moveFromLocation;
}


std::string Move::getPiece(void) {
  return pieceToMove;
}

std::string Move::extractPieceName(std::string terminalCommand) {
    int32_t index = 0;
    std::string pieceName;
    while(terminalCommand[index] != ' ') {
        pieceName += terminalCommand[index];
        index++;
    }
    return pieceName;
}

Location Move::notationToLocation(std::string locationString) {
    uint8_t row = locationString[0] - 'A';
    uint8_t col = locationString[1] - '0';
    Location location(row, col);
    return location;
}

Location Move::extractFirstLocation(std::string terminalCommand) {
    int32_t index = 0;
    std::string firstLocation;
    while(terminalCommand[index] != ' ') {
        index++;
    }
    firstLocation += terminalCommand[index + 1];
    firstLocation += terminalCommand[index + 2];
    return notationToLocation(firstLocation);
}

Location Move::extractSecondLocation(std::string terminalCommand) {
    int32_t index = terminalCommand.size();
    std::string secondLocation;
    secondLocation += terminalCommand[index - 2];
    secondLocation += terminalCommand[index - 1];
    return notationToLocation(secondLocation);
}

