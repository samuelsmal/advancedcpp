//
//  testField.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 28.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __connect4_inheritance__testField__
#define __connect4_inheritance__testField__

#include "AI_playfield.h"
#include "AI_Util.h"

class testField {
  int checkPlayfield(playfield);
  int checkPlayfieldBlock(int, int, int, int, playfield);
public:
  void testHorizontal();
  void testVertical();
  void testDiagonal();
  
  void testMeasure();
  
  void runTests() {
    try {
      testHorizontal();
      testVertical();
      testDiagonal();
      
      testMeasure();
      
      std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
  }
};

#endif /* defined(__connect4_inheritance__testField__) */
