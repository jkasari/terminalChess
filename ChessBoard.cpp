#include "ChessBoard.h"


std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
    stream << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < 8; i++) {
        stream << "| ";
        for(int j = 0; j < 8; j++) {
            stream << "\xE2\x99\x9B" << " | ";
        //    stream << chessBoard.displayPiece(i, j) << " | ";
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
            Square sqr(true);
            board[i][j] = sqr;
        }
    }
}

void ChessBoard::isValidMove(Move nextMove) {}

void ChessBoard::exacuteMove(Move nextMove) {}

char* ChessBoard::displayPiece(uint8_t row, uint8_t col) const {
    board[row][col].getPieceDisplay();
}

void ChessBoard::switchSides(void) {}

bool ChessBoard::correctPiece(Move nextMove) {}

bool ChessBoard::friendlyFire(Move nextMove) {}

bool ChessBoard::movePutsInCheck(Move nextMove) {}

bool ChessBoard::moveOutOfCheck(Move nextMove) {}

void ChessBoard::canCapturePiece(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}



