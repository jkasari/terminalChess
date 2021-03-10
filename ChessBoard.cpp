#include "ChessBoard.h"



bool operator==(const Piece* piece, const PieceType& pieceType) {
    return pieceType == piece->getPieceType();
}

bool operator==(const Location location1, const Location location2) {
    return (location1.row == location2.row && location1.col == location2.col);
}

std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
    stream << "  +---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < 8; i++) {
        stream << 8 - i << " | ";
        for(int j = 0; j < 8; j++) {
            stream << chessBoard.displayPiece(i, j) << " | ";
        }
        if(i < 7) {
          stream << std::endl << "  |---|---|---|---|---|---|---|---|" << std::endl;
        }
    }
    stream << std::endl << "  +---+---+---+---+---+---+---+---+";
    stream << std::endl << "    A   B   C   D   E   F   G   H" << std::endl;
    return stream;
}

ChessBoard::ChessBoard() {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            Square sqr;
            board[i][j] = sqr;
        }
    }
    board[0][3].newPiece(&blackKing);
    board[0][4].newPiece(&blackQueen);
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


    for(int i = 0; i < 8; ++i) {
        board[6][i].newPiece(&whitePawns[i]);
        board[1][i].newPiece(&blackPawns[i]);
    }

}


void ChessBoard::isValidMove(Move nextMove) {
    if(!correctPiece(nextMove))      { throw(BoardError::MoveNotPossible);    }
    if(friendlyFire(nextMove))       { throw(BoardError::FriendlyFire);       }
    if(!correctColor(nextMove))      { throw(BoardError::IncorrectColor);     }
    if(pieceCantMoveThere(nextMove)) { throw(BoardError::PieceCantMoveThere); }
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
    if(turnColor == Color::White) {
        turnColor = Color::Black;
    } else {
        turnColor = Color::White;
    }
}

Color ChessBoard::whosTurn() {
   return turnColor;
}

bool ChessBoard::correctPiece(Move nextMove) {
    uint8_t row = nextMove.getFromLocation().row;
    uint8_t col = nextMove.getFromLocation().col;
    if(!board[row][col].getPiecePointer()) {
        return false;
    }
    return board[row][col].getPiecePointer() == nextMove.getPiece();
}

bool ChessBoard::friendlyFire(Move nextMove) {
    uint8_t row = nextMove.getToLocation().row;
    uint8_t col = nextMove.getToLocation().col;
    if(!board[row][col].getPiecePointer()) {
        return false;
    }
    return board[row][col].getPiecePointer()->getColor() == turnColor;
}
bool ChessBoard::correctColor(Move nextMove) {
    uint8_t row = nextMove.getFromLocation().row;
    uint8_t col = nextMove.getFromLocation().col;
    if(!board[row][col].getPiecePointer()) {
        return true;
    }
    return board[row][col].getPiecePointer()->getColor() == turnColor;
}

bool ChessBoard::movePutsInCheck(Move nextMove) {
    std::vector<Location> movesOnBoard;
    // go across the rows of squares
      // go down the cols of squares
        // check if their are any pieces of the opposing color
        // if there are, then push_back their moves.
    // then run a loop through ever one of those moves
    // check to see your king shares a location with any of them!
}

bool ChessBoard::pieceCantMoveThere(Move nextMove) {
    std::vector<Location> validMoves;
    Location currentLocation = nextMove.getFromLocation();
    Location futureLocation = nextMove.getToLocation();
    PieceType nextPiece = nextMove.getPiece();

    if (
        nextPiece == PieceType::King ||
        nextPiece == PieceType::Bishop ||
        nextPiece == PieceType::Rook ||
        nextPiece == PieceType::Queen ||
        nextPiece == PieceType::Knight
    ) {
    switch(nextMove.getPiece()) {
      case PieceType::King:
        validMoves = whiteKing.potentialMoves(currentLocation);
        break;
      case PieceType::Queen:
        validMoves = whiteQueen.potentialMoves(currentLocation);
        break;
      case PieceType::Bishop:
        validMoves = whiteBishopA.potentialMoves(currentLocation);
        break;
      case PieceType::Knight:
        validMoves = whiteKnightA.potentialMoves(currentLocation);
        break;
      case PieceType::Rook:
        validMoves = whiteRookA.potentialMoves(currentLocation);
        break;
    }
    for(int i = 0; i < validMoves.size(); ++i) {
       if(futureLocation == validMoves[i]) {
            return false;
        }
    }
    return true;
    }
    return false;
}

bool ChessBoard::mustMoveOutOfCheck(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}



