main: ChessBoard
	g++ -std=c++17 main.cpp ChessBoard.o Referee.o Square.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o run

test: ChessBoard
	g++ -std=c++17 test.cpp ChessBoard.o Referee.o Square.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o test
	./test

ChessBoard: Referee
	g++ -std=c++17 ChessBoard.cpp -c

Referee: Square
	g++ -std=c++17 Referee.cpp -c

Square: Piece
	g++ -std=c++17 Square.cpp -c

Piece: King
	g++ -std=c++17 Piece.cpp -c

King: Queen
	g++ -std=c++17 King.cpp -c

Queen: Rook
	g++ -std=c++17 Queen.cpp  -c

Rook: Bishop
	g++ -std=c++17 Rook.cpp -c

Bishop: Knight
	g++ -std=c++17 Bishop.cpp -c

Knight: Pawn
	g++ -std=c++17 Knight.cpp -c

Pawn:
	g++ -std=c++17 Pawn.cpp -c

clean:
	rm -rf run test *.o
	
.PHONY: main test clean Pawn Bishop Rook Queen Piece Square Referee ChessBoard
