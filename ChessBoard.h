#ifndef ChessBoard_h
#define ChessBoard_h
#include "Move.h"
#include "Square.h"

class ChessBoard {

 public:
   /**
    * Checks to make sure the preposed move is valid relative to the current board setup.
    * It will cout a error message into the terminal the move is unvalid.
    */
   void isValidMove(Move);

   /**
    * Actually exacutes the preposed move.
    */
   void exacuteMove(Move);

  /**
   * Displays a the actually |ChessBoard| in the terminal.
   */
   void displayBoard(void);

   /**
    * Changes whos turn it is to play.
    */
   void switchSides(void);

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
    * Checks to make sure the new move doesn't put you in check.
    */
   bool movePutsInCheck(Move);

   /**
    * Checks to see if you are currently in check, if so it makes sure your next move protects
    * the king.
    */
   bool moveOutOfCheck(Move);

   /**
    * Checks to see if the new move falls on an enemys piece, if it does
    * it removes the piece from the board.
    */
   void canCapturePiece(Move);

   /**
    * This puts the opponent in check.
    */
   void inCheck(Move);

   /**
    * This puts the opponent in checkmate.
    */
   void inCheckMate(Move);


  Square board[8][8];
  bool whitesTurn = true;
  bool checkMate = false;
  bool whiteCheck = false;
  bool blackCheck = false;

};

#endif // ChessBoard_h
