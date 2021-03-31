#include "ChessBoard.h"

bool operator==(const Piece* piece, const PieceType& pieceType) {
  return pieceType == piece->getPieceType();
}

bool operator==(const Location location1, const Location location2) {
  return (location1.row == location2.row && location1.col == location2.col);
}

bool operator!=(const Location location1, const Location location2) {
  return (location1.row != location2.row || location1.col != location2.col);
}

std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
  stream << "  +---+---+---+---+---+---+---+---+" << std::endl;
  for (int i = 0; i < 8; i++) {
    stream << 8 - i << " | ";
    for (int j = 0; j < 8; j++) {
      stream << chessBoard.displayPiece(i, j) << " | ";
    }
    if (i < 7) {
      stream << std::endl << "  |---|---|---|---|---|---|---|---|" << std::endl;
    }
  }
  stream << std::endl << "  +---+---+---+---+---+---+---+---+";
  stream << std::endl << "    A   B   C   D   E   F   G   H" << std::endl;
  return stream;
}

ChessBoard::ChessBoard() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      Square sqr;
      board[i][j] = sqr;
    }
  }
  board[0][4].newPiece(&blackKing);
  board[0][3].newPiece(&blackQueen);
  board[0][5].newPiece(&blackBishopA);
  board[0][2].newPiece(&blackBishopB);
  board[0][6].newPiece(&blackKnightA);
  board[0][1].newPiece(&blackKnightB);
  board[0][7].newPiece(&blackRookA);
  board[0][0].newPiece(&blackRookB);

  board[7][4].newPiece(&whiteKing);
  board[7][3].newPiece(&whiteQueen);
  board[7][5].newPiece(&whiteBishopA);
  board[7][2].newPiece(&whiteBishopB);
  board[7][6].newPiece(&whiteKnightA);
  board[7][1].newPiece(&whiteKnightB);
  board[7][7].newPiece(&whiteRookA);
  board[7][0].newPiece(&whiteRookB);

  for (int i = 0; i < 8; ++i) {
    board[6][i].newPiece(&whitePawns[i]);
    board[1][i].newPiece(&blackPawns[i]);
  }
}

void ChessBoard::isValidMove(Move nextMove) {
  if (!correctPiece(nextMove)) {
    throw(BoardError::MoveNotPossible);
  }
  if (friendlyFire(nextMove)) {
    throw(BoardError::FriendlyFire);
  }
  if (!correctColor(nextMove)) {
    throw(BoardError::IncorrectColor);
  }
  if (pieceCantMoveThere(nextMove)) {
    throw(BoardError::PieceCantMoveThere);
  }
  if (movePutsInCheck(nextMove)) {
    throw(BoardError::PutsInCheck);
  }
}

void ChessBoard::executeMove(Move nextMove) {
  isValidMove(nextMove);
  uint8_t fromRow = nextMove.getFromLocation().row;
  uint8_t fromCol = nextMove.getFromLocation().col;
  uint8_t toRow = nextMove.getToLocation().row;
  uint8_t toCol = nextMove.getToLocation().col;

  board[toRow][toCol] = board[fromRow][fromCol];
  board[fromRow][fromCol].newPiece(nullptr);
}

std::string ChessBoard::displayPiece(uint8_t row, uint8_t col) const {
  return board[row][col].getPieceDisplay();
}

void ChessBoard::switchSides() {
  if (turnColor == Color::White) {
    turnColor = Color::Black;
  } else {
    turnColor = Color::White;
  }
}

Color ChessBoard::whosTurn() { return turnColor; }

bool ChessBoard::correctPiece(Move nextMove) {
  uint8_t row = nextMove.getFromLocation().row;
  uint8_t col = nextMove.getFromLocation().col;
  if (!board[row][col].getPiecePointer()) {
    return false;
  }
  return board[row][col].getPiecePointer() == nextMove.getPiece();
}

bool ChessBoard::friendlyFire(Move nextMove) {
  uint8_t row = nextMove.getToLocation().row;
  uint8_t col = nextMove.getToLocation().col;
  if (!board[row][col].getPiecePointer()) {
    return false;
  }
  return board[row][col].getPiecePointer()->getColor() == turnColor;
}
bool ChessBoard::correctColor(Move nextMove) {
  uint8_t row = nextMove.getFromLocation().row;
  uint8_t col = nextMove.getFromLocation().col;
  if (!board[row][col].getPiecePointer()) {
    return true;
  }
  return board[row][col].getPiecePointer()->getColor() == turnColor;
}

bool ChessBoard::movePutsInCheck(Move nextMove) {
  if (nextMove.getPiece() == PieceType::King) {
    std::vector<Location> enemyMoves;
    Color enemyColor;
    if (turnColor == Color::White) {
      enemyColor = Color::Black;
    } else if (turnColor == Color::Black) {
      enemyColor = Color::White;
    }
    //enemyMoves = getSquaresUnderAttack(enemyColor);

    //for(int i = 0; i < enemyMoves.size(); ++i) {
    //  if (nextMove.getToLocation() == enemyMoves[i]) {
    //    return true;
    //  }
    //}
  }
  return false;
}

std::vector<Location> ChessBoard::getSquaresUnderAttack(Color color) {
  std::vector<Location> pieceMoves;
  std::vector<Location> squaresUnderAttack;

  for(int i = 0; i < 8; ++i) {
    for(int j = 0; j < 8; ++j) {
      if (board[i][j].getPiecePointer()->getColor() != color) {
        pieceMoves = getLivePieceMoves(board[i][j].getPiecePointer()->getPieceType(), Location(i, j));
        for(int i = 0; i < pieceMoves.size(); ++i) {
          squaresUnderAttack.push_back(pieceMoves[i]);
        }
      }
    }
  }
  return squaresUnderAttack;
}

bool ChessBoard::pieceCantMoveThere(Move nextMove) {
  std::vector<Location> validMoves;
  Location currentLocation = nextMove.getFromLocation();
  Location futureLocation = nextMove.getToLocation();
  PieceType piece = nextMove.getPiece();

  validMoves = getLivePieceMoves(piece, currentLocation);

  for(int i = 0; i < validMoves.size(); ++i) {
    if (futureLocation == validMoves[i]) {
      return false;
    }
  }
  return true;
}

bool ChessBoard::mustMoveOutOfCheck(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}

std::vector<Location> ChessBoard::livePawnMoves(
    std::vector<Location> potentialMoves) {
  Location currentLocation = potentialMoves[0];
  uint8_t row = currentLocation.row;
  uint8_t col = currentLocation.col;
  uint8_t right = col + 1;
  uint8_t left = col - 1;
  if (turnColor == Color::White) {
    row -= 1;
  } else {
    row += 1;
  }
  if (board[row][col].getPiecePointer()) {
    potentialMoves[1] = currentLocation;
    potentialMoves[3] = currentLocation;
  }
  if (board[row][left].getPiecePointer()) {
    potentialMoves.push_back(Location(row, left));
  }
  if (board[row][right].getPiecePointer()) {
    potentialMoves.push_back(Location(row, right));
  }
  return (potentialMoves);
}

std::vector<Location> ChessBoard::livePieceMoves(
    std::vector<Location> potentialMoves) {
  Location currentLocation = potentialMoves[0];
  for (int i = 0; i < potentialMoves.size(); ++i) {
    uint8_t row = potentialMoves[i].row;
    uint8_t col = potentialMoves[i].col;
    if (board[row][col].getPiecePointer() &&
        potentialMoves[i] != currentLocation) {
      i++;
      while (potentialMoves[i] != currentLocation) {
        potentialMoves[i] = currentLocation;
        i++;
        if (i > potentialMoves.size()) {
          break;
        }
      }
    }
  }
  return potentialMoves;
}


std::vector<Location> ChessBoard::getLivePieceMoves(PieceType piece, Location location) {
  std::vector<Location> validMoves;
  switch (piece) {
    case PieceType::Knight:
      validMoves = whiteKnightA.potentialMoves(location);
      break;
    case PieceType::Pawn:
      if (turnColor == Color::White) {
        validMoves =
            livePawnMoves(whitePawns[0].potentialMoves(location));
        break;
      } else {
        validMoves =
            livePawnMoves(blackPawns[0].potentialMoves(location));
        break;
      }
    default:
      uint8_t row = location.row;
      uint8_t col = location.col;
      validMoves = livePieceMoves(
          board[row][col].getPiecePointer()->potentialMoves(location));
  }
  return validMoves;
}
