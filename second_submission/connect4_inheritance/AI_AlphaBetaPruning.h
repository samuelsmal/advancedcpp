//
//  AI_AlphaBetaPruning.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 29.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __connect4_inheritance__AI_AlphaBetaPruning__
#define __connect4_inheritance__AI_AlphaBetaPruning__

#include <climits>

#include "player.h"
#include "playfield.h"
#include "AI_playfield.h"

class AI_AlphaBetaPruning : public player {
  struct WeightedColumn {
    int column {-1};
    int weight {INT_MIN};
  };
  
  using colour_t = int;
  
  colour_t colour_player;
  colour_t colour_opponent;
  
  const int max_depth {0}; // Should be set to what not. 42?
  
  bool first_round {true};
  void initColours(const playfield&);
  
  AI_playfield ai_pf;
  
  bool terminalPlayfield(const AI_playfield& pf);
  int heuristicEvaluation(const AI_playfield&, bool);
  int alphaBetaEvaluation(const AI_playfield& pf, int depth, int alpha, int beta, bool maximizingPlayer);
  
public:
  AI_AlphaBetaPruning(){}
  int play(const playfield&);
};

#endif /* defined(__connect4_inheritance__AI_AlphaBetaPruning__) */
