//
//  AI_AlphaBetaPruning.h
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 29.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __connect4_inheritance__AI_AlphaBetaPruning__
#define __connect4_inheritance__AI_AlphaBetaPruning__

#include <limits>

#include "player.h"
#include "playfield.h"
#include "AI_playfield.h"

class AI_AlphaBetaPruning : public player {
  struct WeightedColumn {
    int column;
    double weight;
  };
  
  using colour_t = int;
  
  colour_t colour_player;
  colour_t colour_opponent;
  
  const int max_depth {0}; // Should be set to what not. 42? Much to slow...
  
  bool first_round {true};
  void initColours(const playfield&);
  
  bool terminalPlayfield(const AI_playfield& pf);
  double heuristicEvaluation(const AI_playfield&, bool);
  double alphaBetaEvaluation(const AI_playfield& pf, int depth, double alpha, double beta, bool maximizingPlayer);
  
public:
  AI_AlphaBetaPruning(){}
  int play(const playfield&);
};

#endif /* defined(__connect4_inheritance__AI_AlphaBetaPruning__) */
