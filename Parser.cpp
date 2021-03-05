#include "Parser.h"

std::ostream& operator<<(std::ostream& stream, const ParseError& err) {
  switch (err) {
    case ParseError::InvalidPiece: return stream << "InvalidPiece";
    case ParseError::InvalidLocation: return stream << "InvalidLocation";
  }
  return stream;
}

Move Parser::parseMove(const std::string& input) const {
    if(input.empty()) {
        throw ParseError::InvalidPiece;
    }
    size_t index = 0;
    size_t lastIndex = input.length() - 1;
    std::string pieceTypeInput;
    while(index <= lastIndex && input[index] != ' ') {
        pieceTypeInput += input[index];
        index++;
    }
    index++;
    PieceType pieceType = parsePieceType(pieceTypeInput);

    std::string fromLocationInput;
    while(index <= lastIndex && input[index] != ' ') {
        fromLocationInput += input[index];
        index++;
    }
    index++;
    Location fromLocation = parseLocation(fromLocationInput);

    std::string toLocationInput;
    while(index <= lastIndex) {
        toLocationInput += input[index];
        index++;
    }
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
        loweredStr[1] = '8' - loweredStr[1],
        loweredStr[0] - 'a'
    );

}
