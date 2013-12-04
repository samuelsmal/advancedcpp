#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"
#include <iostream>

template<typename F>
class humanPlayer : public player<F> {
 public:
  int play(const F &field) {
    std::cout << "Your move? ";
    int move;
    std::cin >> move;
    return move;
  }
 private:
};

#endif // HUMANPLAYER_H
