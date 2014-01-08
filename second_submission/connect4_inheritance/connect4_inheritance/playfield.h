#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <stdexcept>
#include <iostream>

class playfield {
  public:
// the size of the field
    const static int width=7;
    const static int height=6;

    const static int none=0;
    const static int player1=1;
    const static int player2=2;
  protected:
// the internal representation of the field -- may be changed
    int rep[playfield::width][playfield::height];
  public:
    playfield () {
      for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
          rep[i][j] = 0;
        }
      }
    }

// return the stone (none/player1/player2) at the position(x,y)
// 0 <= x < width
// 0 <= y < height
// stoneat(0,0) ................ top left
// stoneat(width-1,height-1) ... bottom right
// if we insert a stone in a new game in column i,
// it lands at (i,height-1)
// implementation may be changed, interface not
    int stoneat(int x, int y) const {
      return rep[x][y];
    }

    virtual void insertStone(int x, int y, int player) {
      if (x < 0 || x >= width || y < 0 || y > height) {
        throw std::out_of_range("No such place in playfield!");
      }

      if (player != 1 && player != 2) {
        throw std::logic_error("No such player");
      }

      rep[x][y] = player;
    }

    void print() {
      for (int i{0}; i < height; ++i) {
        std::cout << " | ";
        for (int j{0}; j < width; ++j) {
          std::cout << rep[j][i] << " | ";
        }
        std::cout << std::endl;
      }

      std::cout << "  ";
      for (int i{0}; i < width - 1; ++i) {
        std::cout << "====";
      }
      std::cout << "===" << std::endl;

      std::cout << " | ";
      for (int i{0}; i < width; ++i) {
        std::cout << i << " | ";
      }
      std::cout << std::endl;
    }
  
    void print() const {
      for (int i{0}; i < height; ++i) {
        std::cout << " | ";
        for (int j{0}; j < width; ++j) {
          std::cout << rep[j][i] << " | ";
        }
        std::cout << std::endl;
      }
      
      std::cout << "  ";
      for (int i{0}; i < width - 1; ++i) {
        std::cout << "====";
      }
      std::cout << "===" << std::endl;
      
      std::cout << " | ";
      for (int i{0}; i < width; ++i) {
        std::cout << i << " | ";
      }
      std::cout << std::endl;
    }
};

#endif // PLAYFIELD_H
