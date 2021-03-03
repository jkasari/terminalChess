#include "ChessBoard.h"

King* whiteKing = new King(Color::White);
King* blackKing = new King(Color::Black);
Queen* whiteQueen = new Queen(Color::White);
Queen* blackQueen = new Queen(Color::Black);
Rook* whiteRookA = new Rook(Color::White);
Rook* whiteRookB = new Rook(Color::White);
Rook* blackRookA = new Rook(Color::Black);
Rook* blackRookB = new Rook(Color::Black);
Bishop* whiteBishopA = new Bishop(Color::White);
Bishop* whiteBishopB = new Bishop(Color::White);
Bishop* blackBishopA = new Bishop(Color::Black);
Bishop* blackBishopB = new Bishop(Color::Black);
Knight* whiteKnightA = new Knight(Color::White);
Knight* whiteKnightB = new Knight(Color::White);
Knight* blackKnightA = new Knight(Color::Black);
Knight* blackKnightB = new Knight(Color::Black);

Pawn* whitePawnA = new Pawn(Color::White);
Pawn* whitePawnB = new Pawn(Color::White);
Pawn* whitePawnC = new Pawn(Color::White);
Pawn* whitePawnD = new Pawn(Color::White);
Pawn* whitePawnE = new Pawn(Color::White);
Pawn* whitePawnF = new Pawn(Color::White);
Pawn* whitePawnG = new Pawn(Color::White);
Pawn* whitePawnH = new Pawn(Color::White);

Pawn* blackPawnA = new Pawn(Color::Black);
Pawn* blackPawnB = new Pawn(Color::Black);
Pawn* blackPawnC = new Pawn(Color::Black);
Pawn* blackPawnD = new Pawn(Color::Black);
Pawn* blackPawnE = new Pawn(Color::Black);
Pawn* blackPawnF = new Pawn(Color::Black);
Pawn* blackPawnG = new Pawn(Color::Black);
Pawn* blackPawnH = new Pawn(Color::Black);
Pawn* blackPawnI = new Pawn(Color::Black);

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
    board[0][3].newPiece(blackKing);
    board[0][4].newPiece(blackQueen);
    board[0][5].newPiece(blackBishopA);
    board[0][2].newPiece(blackBishopB);
    board[0][6].newPiece(blackKnightA);
    board[0][1].newPiece(blackKnightB);
    board[0][7].newPiece(blackRookA);
    board[0][0].newPiece(blackRookB);

    board[7][4].newPiece(whiteKing);
    board[7][3].newPiece(whiteQueen);
    board[7][5].newPiece(whiteBishopA);
    board[7][2].newPiece(whiteBishopB);
    board[7][6].newPiece(whiteKnightA);
    board[7][1].newPiece(whiteKnightB);
    board[7][7].newPiece(whiteRookA);
    board[7][0].newPiece(whiteRookB);

    board[1][0].newPiece(blackPawnA);
    board[1][1].newPiece(blackPawnB);
    board[1][2].newPiece(blackPawnC);
    board[1][3].newPiece(blackPawnD);
    board[1][4].newPiece(blackPawnE);
    board[1][5].newPiece(blackPawnF);
    board[1][6].newPiece(blackPawnG);
    board[1][7].newPiece(blackPawnH);

    board[6][0].newPiece(whitePawnA);
    board[6][1].newPiece(whitePawnB);
    board[6][2].newPiece(whitePawnC);
    board[6][3].newPiece(whitePawnD);
    board[6][4].newPiece(whitePawnE);
    board[6][5].newPiece(whitePawnF);
    board[6][6].newPiece(whitePawnG);
    board[6][7].newPiece(whitePawnH);



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

  delete whiteRookA;
  whiteRookA = nullptr;
  delete whiteRookB;
  whiteRookB = nullptr;
  delete blackRookA;
  blackRookA = nullptr;
  delete blackRookB;
  blackRookA = nullptr;
  delete whiteBishopA;
  whiteBishopA = nullptr;
  delete whiteBishopB;
  whiteBishopB = nullptr;
  delete blackBishopA;
  blackBishopA = nullptr;
  delete blackBishopB;
  blackBishopB = nullptr;
  delete whiteKnightA;
  whiteKnightA = nullptr;
  delete whiteKnightB;
  whiteKnightB = nullptr;

  delete whitePawnA;
  whitePawnA = nullptr;
  delete whitePawnB;
  whitePawnB = nullptr;
  delete whitePawnC;
  whitePawnC = nullptr;
  delete whitePawnD;
  whitePawnD = nullptr;
  delete whitePawnE;
  whitePawnE = nullptr;
  delete whitePawnF;
  whitePawnF = nullptr;
  delete whitePawnG;
  whitePawnG = nullptr;
  delete whitePawnH;
  whitePawnH = nullptr;

  delete blackPawnA;
  blackPawnA = nullptr;
  delete blackPawnB;
  blackPawnB = nullptr;
  delete blackPawnC;
  blackPawnC = nullptr;
  delete blackPawnD;
  blackPawnD = nullptr;
  delete blackPawnE;
  blackPawnE = nullptr;
  delete blackPawnF;
  blackPawnF = nullptr;
  delete blackPawnG;
  blackPawnG = nullptr;
  delete blackPawnH;
  blackPawnH = nullptr;
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



