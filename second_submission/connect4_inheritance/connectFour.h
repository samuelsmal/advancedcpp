#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "playfield.h"

template <typename PlayerOneType,   // PlayerOneType models the first player.
          typename PlayerTwoType>   // PlayerTwoType models the second player.
class connectFour {
 private:
  playfield pf;
  PlayerOneType playerOne;
  PlayerTwoType playerTwo;

  int checkPlayfield(); // Returns 0 if nobody won, 1 if playerOne or 2 if playerTwo has won.
  int checkPlayfieldBlock(int x, int y, int delta_x, int delta_y); // Same as checkPlayfield but for the internal block.
  bool tryMove(int x, int player);
  void printPlayfield();
 public:
  connectFour() : pf{} {};
  void startGame();
};

#include "_connectFour.impl"
#endif // CONNECTFOUR_H
