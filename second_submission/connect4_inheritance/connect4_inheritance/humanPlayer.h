#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"
#include <iostream>

class humanPlayer : public player {
 public:
  int play(const playfield &field) {
    std::cout << "Your move? ";
    int move;
    std::cin >> move;
    return move;
  }
 private:
};

#endif // HUMANPLAYER_H
