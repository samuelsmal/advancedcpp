//
//  AIV2.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 07.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//
//  This is my go at a second 'connect four computer player'.
//    I called it AI since I like big names. Not that it would be classified
//    'intelligent' by me. It doesn't learn for starters.
//
//  I place a virtual stone at each place and check if the computer can win.
//    If he doesn't check if the opponent can win.
//    If neither is the case for all columns, then select the column
//    with the best result for the player and the worst result for the opponent.
//    And prefer the worst result for the opponent over the best result of the
//    player.
//
//  For each column where a stone could be placed there's a corresponding
//    ColumnWeight.
//
//  The measuring is done via a pattern matching.
//    The maximum would be 6 (xxx_xxx) and the minimum 0 (**o_o**).
//
//  Work not finished. Will not continue. Idea doesn't work.


#ifndef connect4_inheritance_AIV2_h
#define connect4_inheritance_AIV2_h

#include <vector>

#include "AI_playfield.h"

#include "player.h"

struct ColumnWeight {
  int player, opponent, column;
  
  ColumnWeight() : player{0}, opponent{0}, column{0} {}
  ColumnWeight(int col) : player{0}, opponent{0}, column{col} {}
};

class AIV2 : public player{

  using colour_t = int;
  
public:
  AIV2()
  : width_of_field {playfield::width}
  , height_of_field {playfield::height}
  , virtual_playfields(width_of_field)
  , measuredColumns(width_of_field)
  {};
  
  int play(const playfield& field); // API Function
private:
  const int width_of_field;
  const int height_of_field;
  
  //  To determine the colour of the player and his opponent.
  bool first_round {true};
  int  countOnes(const AI_playfield&);
  void determineColours(const AI_playfield&);
  
  colour_t real_colour_of_player;
  colour_t real_colour_of_opponent;
  colour_t virtual_colour_of_player;
  colour_t virtual_colour_of_opponent;
  
  //  The real stuff
  std::vector<AI_playfield> virtual_playfields;
  std::vector<ColumnWeight> measuredColumns;
  
  void initVirtualPlayfields(const AI_playfield& field);
  void insertStone(AI_playfield& field, int column, colour_t colour);
  
  ColumnWeight measurePlayfield(AI_playfield& field);
  ColumnWeight measureColumn(AI_playfield& field, int column);
  int measureStone(AI_playfield& field, int x, int y, colour_t colour);
  int measureDirection(AI_playfield& field,
                       int x, int y,
                       int d_x, int d_y,
                       colour_t colour);
};
#endif
