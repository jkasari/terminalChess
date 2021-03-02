#include "ChessBoard.h"


std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
    stream << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < 8; i++) {
        stream << "| ";
        for(int j = 0; j < 8; j++) {
        //    stream << std::setfill('0') << std::setw(2);
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
            Square sqr(true);
            board[i][j] = sqr;
        }
    }
}

void ChessBoard::isValidMove(Move nextMove) {}

void ChessBoard::exacuteMove(Move nextMove) {}

std::string ChessBoard::displayPiece(uint8_t row, uint8_t col) const {
    return " ";
}

void ChessBoard::switchSides(void) {}

bool ChessBoard::correctPiece(Move nextMove) {}

bool ChessBoard::friendlyFire(Move nextMove) {}

bool ChessBoard::movePutsInCheck(Move nextMove) {}

bool ChessBoard::moveOutOfCheck(Move nextMove) {}

void ChessBoard::canCapturePiece(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}



