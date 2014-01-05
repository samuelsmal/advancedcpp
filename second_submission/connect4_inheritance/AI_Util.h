//
//  AI_Util.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 30.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef connect4_inheritance_AI_Util_h
#define connect4_inheritance_AI_Util_h

#include "AI_playfield.h"

namespace AI_Util {
  typedef int colour_t;
  
  double measureDirection(const AI_playfield& field, int x, int y, int d_x, int d_y, colour_t colour);
  
  double measureStone(const AI_playfield& field, int x, int y, colour_t colour);
  
  double playfieldEvaluation(const AI_playfield& field, colour_t colour);
  
  // Checks if anybody has won.
  bool terminalPlayfield(const AI_playfield& pf, colour_t firstPlayerColour, colour_t secondPlaycerColour);
}
#endif
