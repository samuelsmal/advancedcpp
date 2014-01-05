#include <iostream>

#include "connectFour.h"
#include "humanPlayer.h"
#include "playfield.h"

#include "AI_AlphaBetaPruning.h"
#include "MiniMaxPlayer.h"
#include "computerPlayer.h"
#include "computerPlayer.cpp"

#include "testField.h"

void runTests() {
  testField tf;
  
  tf.runTests();
}

int main() {
  runTests();
  
  connectFour<humanPlayer, AI_AlphaBetaPruning> game{};
  game.startGame();
}
