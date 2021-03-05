#ifndef ChessBoard_h
#define ChessBoard_h
#include "Move.h"
#include "Square.h"
#include "Piece.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>

enum class BoardError {
  MoveNotPossible,
  FriendlyFire,
  IncorrectColor,
};

bool operator==(const PieceType& pieceType, const Piece& piece);

class ChessBoard {

    friend std::ostream& operator<<(std::ostream&, const ChessBoard&);

 public:
  ChessBoard ();

   /**
    * Checks to make sure the preposed move is valid relative to the current board setup.
    * It will cout a error message into the terminal the move is unvalid.
    */
   void isValidMove(Move);

   /**
    * Actually exacutes the preposed move.
    */
   void executeMove(Move);

  /**
   * Give the character string for each piece to the ostream operator.
   * |NullPiece|s character string is just " ".
   */
   std::string displayPiece(uint8_t, uint8_t) const;

   /**
    * Changes whos turn it is to play.
    */
   void switchSides();

   /**
    * Returns enum |White| if its whites turn and |Black| if its blacks turn.
    */
   Color whosTurn();

 private:
  /**
   * Checks to see if the new location and piece match up.
   */
   bool correctPiece(Move);

   /**
    * Checks to see if the new moves location is occupied by another piece.
    */
   bool friendlyFire(Move);

  /**
   * Checks to make sure the correct side is playing the game.
   */
  bool correctColor(Move);

   /**
    * Checks to make sure the new move doesn't put you in check.
    */
   bool movePutsInCheck(Move);

   /**
    * Checks to see if you are currently in check, if so it makes sure your next move protects
    * the king.
    */
   bool mustMoveOutOfCheck(Move);

   /**
    * This puts the opponent in check.
    */
   void inCheck(Move);

   /**
    * This puts the opponent in checkmate.
    */
   void inCheckMate(Move);


  Square board[8][8];
  Color turnColor = Color(Color::White);
  bool checkMate = false;
  bool whiteCheck = false;
  bool blackCheck = false;
  King whiteKing = King(Color::White);
  King blackKing = King(Color::Black);
  Queen whiteQueen = Queen(Color::White);
  Queen blackQueen = Queen(Color::Black);
  Rook whiteRookA = Rook(Color::White);
  Rook whiteRookB = Rook(Color::White);
  Rook blackRookA = Rook(Color::Black);
  Rook blackRookB = Rook(Color::Black);
  Bishop whiteBishopA = Bishop(Color::White);
  Bishop whiteBishopB = Bishop(Color::White);
  Bishop blackBishopA = Bishop(Color::Black);
  Bishop blackBishopB = Bishop(Color::Black);
  Knight whiteKnightA = Knight(Color::White);
  Knight whiteKnightB = Knight(Color::White);
  Knight blackKnightA = Knight(Color::Black);
  Knight blackKnightB = Knight(Color::Black);
  Pawn whitePawns[8] {
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
    Pawn(Color::White),
  };

  Pawn blackPawns[8] {
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
    Pawn(Color::Black),
  };

};

#endif // ChessBoard_h
