#include <iostream>
#include "connectFour.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "playfield.h"

int main() {
  humanPlayer<playfield> p1, p2;
  connectFour<humanPlayer<playfield>, computerPlayer<playfield>> game{};
  game.startGame();
}
