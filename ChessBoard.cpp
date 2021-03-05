#include "ChessBoard.h"


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


void ChessBoard::isValidMove(Move nextMove) {}

void ChessBoard::executeMove(Move nextMove) {
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

void ChessBoard::switchSides(void) {}

bool ChessBoard::correctPiece(Move nextMove) {}

bool ChessBoard::friendlyFire(Move nextMove) {}

bool ChessBoard::movePutsInCheck(Move nextMove) {}

bool ChessBoard::moveOutOfCheck(Move nextMove) {}

void ChessBoard::canCapturePiece(Move nextMove) {}

void ChessBoard::inCheck(Move nextMove) {}

void ChessBoard::inCheckMate(Move nextMove) {}



