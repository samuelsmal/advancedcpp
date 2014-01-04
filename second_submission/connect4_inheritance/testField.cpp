//
//  testField.cpp
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 28.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include <assert.h>

#include "testField.h"

int testField::checkPlayfieldBlock(int x, int y, int delta_x, int delta_y, playfield pf) {
  int ret_val {0}, player {1};
  
  while(!ret_val && player < 3) {
    for(int steps = 0; steps < 4; ++steps, x += delta_x, y += delta_y) {
      if (pf.stoneat(x, y) != player) {
        ret_val = 0;
        break;
      } else {
        ret_val = player;
      }
    }
    
    ++player;
  }
  
  return ret_val;
}

int testField::checkPlayfield(playfield p) {
  int block_value;
  
  // Checks from top to down.
  
  for (int x = 0; x < playfield::width; ++x) {
    for (int y = 0; y < playfield::height; ++y) {
      // Horizontal
      if (x < 4) {
        block_value = testField::checkPlayfieldBlock(x, y, 1, 0, p);
        if (block_value) return block_value;
      }
      // Vertical
      if (y < 3) {
        block_value = testField::checkPlayfieldBlock(x, y, 0, 1, p);
        if (block_value) return block_value;
      }
      
      // Diagonal, in both directions.
      if (y < 4) {
        if (x < 4) {
          block_value = testField::checkPlayfieldBlock(x, y, 1, 1, p);
          if (block_value) return block_value;
        }
        
        if (x > 2) {
          block_value = testField::checkPlayfieldBlock(x, y, -1, 1, p);
          if (block_value) return block_value;
        }
        
      }
    }
  }
  
  return 0;
}

void testField::testHorizontal() {
  playfield p, p2, p3, p4;
  
  p.insertStone(0, 0, 1);
  p.insertStone(0, 1, 1);
  p.insertStone(0, 2, 1);
  p.insertStone(0, 3, 1);
  
  assert(checkPlayfield(p) == 1);

  p2.insertStone(0, 2, 2);
  p2.insertStone(0, 3, 2);
  p2.insertStone(0, 4, 2);
  p2.insertStone(0, 5, 2);
  
  
  assert(checkPlayfield(p2) == 2);

  p3.insertStone(3, 2, 1);
  p3.insertStone(3, 3, 1);
  p3.insertStone(3, 4, 1);
  p3.insertStone(3, 5, 1);

  
  assert(checkPlayfield(p3) == 1);
  
  p4.insertStone(6, 2, 2);
  p4.insertStone(6, 3, 2);
  p4.insertStone(6, 4, 2);
  p4.insertStone(6, 5, 2);

  assert(checkPlayfield(p4) == 2);
}

void testField::testVertical() {
  playfield p, p2, p3, p4;
  
  p.insertStone(0, 0, 1);
  p.insertStone(1, 0, 1);
  p.insertStone(2, 0, 1);
  p.insertStone(3, 0, 1);
  
  assert(checkPlayfield(p) == 1);
  
  p2.insertStone(2, 2, 2);
  p2.insertStone(3, 2, 2);
  p2.insertStone(4, 2, 2);
  p2.insertStone(5, 2, 2);
  
  
  assert(checkPlayfield(p2) == 2);
  
  p3.insertStone(2, 6, 1);
  p3.insertStone(3, 6, 1);
  p3.insertStone(4, 6, 1);
  p3.insertStone(5, 6, 1);
  
  
  assert(checkPlayfield(p3) == 1);
  
  p4.insertStone(3, 0, 2);
  p4.insertStone(4, 0, 2);
  p4.insertStone(5, 0, 2);
  p4.insertStone(6, 0, 2);
  
  assert(checkPlayfield(p4) == 2);
}

void testField::testDiagonal() {
  playfield p, p2, p3, p4, p5;
  
  p.insertStone(0, 0, 1);
  p.insertStone(1, 1, 1);
  p.insertStone(2, 2, 1);
  p.insertStone(3, 3, 1);
  
  assert(checkPlayfield(p) == 1);
  
  p2.insertStone(0, 4, 2);
  p2.insertStone(1, 3, 2);
  p2.insertStone(2, 2, 2);
  p2.insertStone(3, 1, 2);
  
  
  assert(checkPlayfield(p2) == 2);
  
  p3.insertStone(6, 5, 1);
  p3.insertStone(5, 4, 1);
  p3.insertStone(4, 3, 1);
  p3.insertStone(3, 2, 1);
  
  assert(checkPlayfield(p3) == 1);
  
  p4.insertStone(3, 6, 2);
  p4.insertStone(4, 5, 2);
  p4.insertStone(5, 4, 2);
  p4.insertStone(6, 3, 2);
  
  assert(checkPlayfield(p4) == 2);
  
  p5.insertStone(2, 5, 2);
  p5.insertStone(3, 4, 2);
  p5.insertStone(4, 3, 2);
  p5.insertStone(5, 2, 2);
  
  assert(checkPlayfield(p5) == 2);
}

void testField::testMeasure() {
  AI_playfield ai_p;
  
  ai_p.insertStone(0, 5, 1);
  
  assert(AI_Util::measureStone(ai_p, 0, 5, 1) == 1);
  
  /*
   
   %
   % _ _ _
   % _ * _
   % x _ _
   % % % % %
   
   */
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1, -1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1,  0, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1,  1, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  0,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1,  0, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1, -1, 1) == 0);

  
  assert(AI_Util::measureStone(ai_p, 1, 4, 1) == 1);
  
  /*
   
   %
   % _ _ _
   % _ _ _
   % x * _
   % % % % %
   
   */
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1, -1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1,  0, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  0,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  0, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  1, 1) == 0);
  

  assert(AI_Util::measureStone(ai_p, 1, 5, 1) == 1);
  
  // 2. Stone
  
  ai_p.insertStone(1, 4, 1);
  
  /*
   
   %
   % _ _ _
   % _ x _
   % x * _
   % % % % %
   
   */
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1, -1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1,  0, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 5, -1,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  0,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  1, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  0, 1) == 0);
  assert(AI_Util::measureDirection(ai_p, 1, 5,  1,  1, 1) == 0);
  
  
  assert(AI_Util::measureStone(ai_p, 1, 5, 1) == 1);
  
  /*
   
   %
   % _ _ _
   % _ x*_
   % x _ _
   % % % % %
   
   */
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1, -1, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1,  0, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4, -1,  1, 1) == 2);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  0,  1, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1,  1, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1,  0, 1) == 1);
  assert(AI_Util::measureDirection(ai_p, 1, 4,  1, -1, 1) == 1);
  
  
  assert(AI_Util::measureStone(ai_p, 1, 4, 1) == 2);
  
  //
  // 2. Case
  //
  
  AI_playfield ai_p2;
  
  ai_p2.insertStone(3, 5, 1);
  ai_p2.insertStone(4, 5, 1);
  ai_p2.insertStone(5, 5, 1);
  
  assert(AI_Util::measureStone(ai_p2, 3, 5, 1) == 3);
  
  ai_p2.insertStone(6, 5, 1);
  
  assert(AI_Util::measureStone(ai_p2, 6, 5, 1) == 4);
  
  //
  // 3. Case
  //
  
  AI_playfield ai_p3;
  
  
}

