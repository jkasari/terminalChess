#include "ChessBoard.h"

King* whiteKing = new King(Color::White);
King* blackKing = new King(Color::Black);
Queen* whiteQueen = new Queen(Color::White);
Queen* blackQueen = new Queen(Color::Black);
Rook* whiteRook = new Rook(Color::White);
Rook* blackRook = new Rook(Color::Black);
Bishop* whiteBishop = new Bishop(Color::White);
Bishop* blackBishop = new Bishop(Color::White);
Knight* whiteKnight = new Knight(Color::White);
Knight* blackKnight = new Knight(Color::Black);
Pawn* whitePawn = new Pawn(Color::White);
Pawn* blackPawn = new Pawn(Color::Black);

std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
    stream << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < 8; i++) {
        stream << "| ";
        for(int j = 0; j < 8; j++) {
            stream << chessBoard.displayPiece(i, j) << " | ";
        }
        if(i < 7) {
          stream << std::endl << "|---|---|---|---|---|---|---|---|" << std::endl;
        }
    }
    stream << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
    return stream;
}

ChessBoard::ChessBoard() {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            Square sqr;
            board[i][j] = sqr;
        }
    }
    board[7][4].newPiece(whiteKing);
    board[0][3].newPiece(blackKing);
    board[7][3].newPiece(whiteQueen);
    board[0][4].newPiece(blackQueen);

}

ChessBoard::~ChessBoard() {
  delete whiteKing;
  whiteKing = nullptr;
  delete blackKing;
  blackKing = nullptr;
  delete whiteQueen;
  whiteQueen = nullptr;
  delete blackQueen;
  blackQueen = nullptr;
  delete whiteRook;
  whiteRook = nullptr;
  delete blackRook;
  blackRook = nullptr;
  delete whiteBishop;
  whiteBishop = nullptr;
  delete blackBishop;
  blackBishop = nullptr;
  delete whiteKnight;
  whiteKnight = nullptr;
  delete whitePawn;
  whitePawn = nullptr;
  delete blackPawn;
  blackPawn = nullptr;
}

void ChessBoard::isValidMove(Move nextMove) {}

void ChessBoard::executeMove(Move nextMove) {}

std::string ChessBoard::displayPiece(uint8_t row, uint8_t col) const {
    return board[row][col].getPieceDisplay();
}

void ChessBoard::switchSides(void) {}

bool ChessBoard::correctPiece(Move nextMove) {}

bool ChessBoard::friendlyFire(Move nextMove) {}

bool ChessBoard::movePutsInCheck(Move nextMove) {}

bool ChessBoard::moveOutOfCheck(Move nextMove) {}

void ChessBoard::canCapturePiece(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}



