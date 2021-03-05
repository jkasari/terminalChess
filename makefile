main: ChessBoard Move Parser Square Piece King Queen Rook Bishop Knight Pawn
	g++ -std=c++17 main.cpp ChessBoard.o Move.o Parser.o Square.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o run

test: ChessBoard Move Parser Square Piece King Queen Rook Bishop Knight Pawn
	g++ -std=c++17 test.cpp ChessBoard.o Move.o Parser.o Square.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o -o test
	./test

ChessBoard:
	g++ -std=c++17 ChessBoard.cpp -c

Move:
	g++ -std=c++17 Move.cpp -c

Parser:
	g++ -std=c++17 Parser.cpp -c

Square:
	g++ -std=c++17 Square.cpp -c

Piece:
	g++ -std=c++17 Piece.cpp -c

King:
	g++ -std=c++17 King.cpp -c

Queen:
	g++ -std=c++17 Queen.cpp  -c

Rook:
	g++ -std=c++17 Rook.cpp -c

Bishop:
	g++ -std=c++17 Bishop.cpp -c

Knight:
	g++ -std=c++17 Knight.cpp -c

Pawn:
	g++ -std=c++17 Pawn.cpp -c

clean:
	rm -rf run test *.o
	
.PHONY: main test clean Pawn Bishop Rook Queen Piece Square Parser ChessBoard
