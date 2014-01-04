//
//  AI_playfield.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 29.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef connect4_inheritance_AI_playfield_h
#define connect4_inheritance_AI_playfield_h

#include "playfield.h"

class AI_playfield : public playfield {
  
public:
  AI_playfield() : playfield() {}
  AI_playfield(const playfield& field) {
    for (int i = 0; i < width; ++i) {
      for (int j = 0; j < height; ++j) {
        rep[i][j] = field.stoneat(i, j);
      }
    }
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
  
  virtual void insertStone(int col, int player_colour) {
    int row {0};
    
    while (row < playfield::height - 1 && rep[col][row + 1] == 0) {
      row++;
    }
    
    insertStone(col, row, player_colour);
  }
};

#endif
