//
//  AI_Util.cpp
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 30.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include "AI_Util.h"

namespace AI_Util {
  typedef int colour_t;
  
  int measureDirection(const AI_playfield& field,
                       int x, int y,
                       int d_x, int d_y,
                       colour_t colour) {
    int measure {0};
    colour_t stone;
    for (int steps {0};
         steps < 4 && x >= 0 && x < AI_playfield::width &&
         y >= 0 && y < AI_playfield::height;
         ++steps, x += d_x, y += d_y) {
      stone = field.stoneat(x, y);
      if (stone == colour) {
        ++measure;
      } else if (stone != 0) {
        break;
      }
    }
    
    return measure;
  }
  
  int measureStone(const AI_playfield& field, int x, int y, colour_t colour) {
    int measure {0};
    for (int d_x {-1}; d_x < 2; ++d_x) {
      for (int d_y {-1}; d_y < 2; ++d_y) {
        if (!(d_x == 0 && d_y == 0) && !(d_x == 0 && d_y == -1))
          measure = std::max(measure, measureDirection(field, x, y, d_x, d_y, colour));
      }
    }
    return measure;
  }
  
  int playfieldEvaluation(const AI_playfield& field, colour_t colour) {
    int weight {0};
    
    for (int row {0}; row < AI_playfield::height; ++row) {
      for (int col {0}; col < AI_playfield::width; ++col) {
        std::cout << "(" << field.stoneat(col, row) << ")" << measureStone(field, col, row, colour) << " ";
        weight = std::max(weight, measureStone(field, col, row, colour));
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    
    return weight;
  }
  
  // Checks if anybody has won.
  bool terminalPlayfield(const AI_playfield& pf,
                         colour_t firstPlayerColour,
                         colour_t secondPlaycerColour) {
    if (playfieldEvaluation(pf, firstPlayerColour) >= 4 ||
        playfieldEvaluation(pf, secondPlaycerColour) >= 4) {
      return true;
    } else {
      return false;
    }
  }
}
