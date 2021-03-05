#include "Parser.h"

Move Parser::parseMove(const std::string& input) const {
    int32_t index = 0;
    std::string pieceTypeInput;
    while(input[index] != ' ') {
        pieceTypeInput += input[index];
        index++;
    }
    PieceType pieceType = parsePieceType(pieceTypeInput);

    std::string fromLocationInput;
    fromLocationInput += input[index + 1];
    fromLocationInput += input[index + 2];

    Location fromLocation = parseLocation(fromLocationInput);

    std::string toLocationInput;
    toLocationInput += input[index + 4];
    toLocationInput += input[index + 5];

    Location toLocation = parseLocation(toLocationInput);

    return Move(
        pieceType,
        fromLocation,
        toLocation
    );

}

PieceType Parser::parsePieceType(const std::string& str) {
    std::string loweredStr = toLower(str);
    if (loweredStr == "king")   { return PieceType::King;   }
    if (loweredStr == "queen")  { return PieceType::Queen;  }
    if (loweredStr == "rook")   { return PieceType::Rook;   }
    if (loweredStr == "bishop") { return PieceType::Bishop; }
    if (loweredStr == "knight") { return PieceType::Knight; }
    if (loweredStr == "pawn")   { return PieceType::Pawn;   }

    throw ParseError::InvalidPiece;
}

std::string Parser::toLower(const std::string& str) {
  std::string lowered;
  for(const char c : str) {
     lowered += tolower(c);
  }
  return lowered;
}

Location Parser::parseLocation(const std::string& str) {
    if (str.length() != 2) {
        throw ParseError::InvalidLocation;
    }

    std::string loweredStr = toLower(str);

    if ('a' > loweredStr[0] || loweredStr[0] > 'h') {
        throw ParseError::InvalidLocation;
    }

    if ('1' > loweredStr[1] || loweredStr[1] > '8') {
        throw ParseError::InvalidLocation;
    }

    return Location(
        loweredStr[0] - 'a',
        loweredStr[1] - '0'
    );

}
