main: ChessBoard
	g++ -std=c++17 test.cpp ChessBoard.o Referee.o Square.o Piece.o NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o run

test: ChessBoard
	g++ -std=c++17 test.cpp ChessBoard.o Referee.o Square.o Piece.o NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o test
	./test

ChessBoard: Referee
	g++ -std=c++17 ChessBoard.cpp Referee.o Square.o Piece.o NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

Referee: Square
	g++ -std=c++17 Referee.cpp Square.o Piece.o NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

Square: Piece
	g++ -std=c++17 Square.cpp Piece.o NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

Piece: NullPiece
	g++ -std=c++17 Piece.cpp NullPiece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

NullPiece: King
	g++ -std=c++17 NullPiece.cpp King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

King: Queen
	g++ -std=c++17 King.cpp Queen.o Rook.o Bishop.o Knight.o Pawn.o -c

Queen: Rook
	g++ -std=c++17 Queen.cpp Rook.o Bishop.o Knight.o Pawn.o -c

Rook: Bishop
	g++ -std=c++17 Rook.cpp Bishop.o Knight.o Pawn.o -c

Bishop: Knight
	g++ -std=c++17 Bishop.cpp Knight.o Pawn.o -c

Knight: Pawn
	g++ -std=c++17 Knight.cpp Pawn.o -c

Pawn:
	g++ -std=c++17 Pawn.cpp -c

clean:
	rm -rf run test *.o
	
.PHONY: main test clean Pawn Bishop Rook Queen Piece Square Referee ChessBoard
