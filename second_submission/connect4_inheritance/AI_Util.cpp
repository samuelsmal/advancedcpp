//
//  AI_Util.cpp
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 30.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include "AI_Util.h"

namespace AI_Util {
  using namespace std;
  typedef int colour_t;
  
  double measureDirection(const AI_playfield& field,
                       int x, int y,
                       int d_x, int d_y,
                       colour_t colour) {
    double measure {0};
    colour_t stone;
    int hole_counter {0};
    for (int steps {0};
         steps < 4 && x >= 0 && x < AI_playfield::width &&
         y >= 0 && y < AI_playfield::height;
         ++steps, x += d_x, y += d_y) {
      stone = field.stoneat(x, y);
      if (stone == colour) {
        switch (hole_counter) {
          case 0:
            measure += 1.5;
            break;
          case 1:
            measure += 1.4;
            break;
          default:
            measure += 1.0;
            break;
        }
      } else if (stone == 0) {
        hole_counter++;
      } else {
        break;
      }
    }
    
    return measure;
  }
  
  double measureStone(const AI_playfield& field, int x, int y, colour_t colour) {
    double measure {0};
    
    if (y + 1 < AI_playfield::height && field.stoneat(x, y + 1) == 0)
      return 0.0;
    
    for (int d_x {-1}; d_x < 2; ++d_x) {
      for (int d_y {-1}; d_y < 2; ++d_y) {
        if (!(d_x == 0 && d_y == 0) && !(d_x == 0 && d_y == -1))
          measure = std::max(measure, measureDirection(field, x, y, d_x, d_y, colour));
      }
    }
    return measure;
  }
  
  double playfieldEvaluation(const AI_playfield& field, colour_t colour) {
    double weight {0.0};
    
    cout.precision(2);
    
    //field.print();
    
    for (int row {0}; row < AI_playfield::height; ++row) {
      for (int col {0}; col < AI_playfield::width; ++col) {
        weight = std::max(weight, measureStone(field, col, row, colour));
        //cout << measureStone(field, col, row, colour) << " ";
      }
      //cout << endl;
    }
    //cout << endl;
    
    return weight;
  }
  
  // Checks if anybody has won.
  bool terminalPlayfield(const AI_playfield& pf,
                         colour_t firstPlayerColour,
                         colour_t secondPlaycerColour) {
    if (playfieldEvaluation(pf, firstPlayerColour) >= 6.0 ||
        playfieldEvaluation(pf, secondPlaycerColour) >= 6.0) {
      return true;
    } else {
      return false;
    }
  }
}
