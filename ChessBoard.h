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

 private:
  /**
   * Checks to see if the new location and piece match up.
   */
   bool correctPiece(Move);

   /**
    * Checks to see if the new moves location is occupied by a piece of the same color.
    */
   bool friendlyFire(Move);

   /**
    * Checks to make sure the new move doesn't put you in check.
    */
   bool movePutsInCheck(Move);

   /**
    * Captures a piece.
    */
   void capturePiece(Move);

  Square board[8][8];
  bool checkMate = false;

};

#endif // ChessBoard_h
