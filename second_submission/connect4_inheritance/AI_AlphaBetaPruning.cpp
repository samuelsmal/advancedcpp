//
//  AI_AlphaBetaPruning.cpp
//  connect4_inheritance
//
//  Created by Samuel von Bausznern on 29.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include <vector>

#include "AI_AlphaBetaPruning.h"

#include "AI_Util.h"

using namespace std;

int AI_AlphaBetaPruning::play(const playfield &pf) {
  if (first_round) {
    initColours(pf);
  }
  
  ai_pf = pf;
  
  vector<AI_playfield> children (playfield::width);
  vector<WeightedColumn> weights (playfield::width);
  
  for (int col {0}; col < playfield::width; ++col) {
    if (pf.stoneat(col, 0) == 0) {
      AI_playfield child (pf);
      child.insertStone(col, colour_player);
      children.at(col) = child;
      
      weights.at(col).column = col;
      weights.at(col).weight = alphaBetaEvaluation(child, max_depth, INT_MIN, INT_MAX, true);
    }
  }
  
  std::sort(weights.begin(), weights.end(),
            [](const WeightedColumn& a, const WeightedColumn& b) {
              return a.weight < b.weight;
            });
  return weights.end()->column;
}

void AI_AlphaBetaPruning::initColours(const playfield &pf) {
  int width {playfield::width};
  int height {playfield::height};
  
  colour_player = 2;
  colour_opponent = 1;
  
  while (width--) {
    while (height-- >= 0) {
      if (pf.stoneat(width, height)) {
        colour_player = 1;
        colour_opponent = 2;
        break;
      }
    }
  }
}

int AI_AlphaBetaPruning::heuristicEvaluation(const AI_playfield &pf, bool maximizingPlayer) {
  // Count the patterns. "x_xx" => 3, "xxx_xx" => 5, but "xoxx" => 2,...
  if (maximizingPlayer) {
    return AI_Util::playfieldEvaluation(pf, colour_player);
  } else {
    return AI_Util::playfieldEvaluation(pf, colour_opponent);
  }
}

int AI_AlphaBetaPruning::alphaBetaEvaluation(const AI_playfield &pf, int depth, int alpha, int beta, bool maximizingPlayer) {
  if (depth == 0 || AI_Util::terminalPlayfield(pf, colour_player, colour_opponent)) {
    return heuristicEvaluation(pf, maximizingPlayer);
  }
  
  if (maximizingPlayer) {
    for (int col {0}; col < playfield::width; ++col) {
      if (pf.stoneat(col, 0) == 0) {
        AI_playfield child (pf);
        child.insertStone(col, colour_player);
        alpha = std::max(alpha, alphaBetaEvaluation(child, max_depth - 1, alpha, beta, false));
        
        if (beta <= alpha)
          break;
      }
    }
    return alpha;
  } else {
    for (int col {0}; col < playfield::width; ++col) {
      if (pf.stoneat(col, 0) == 0) {
        AI_playfield child (pf);
        child.insertStone(col, colour_opponent);
        beta = std::min(beta, alphaBetaEvaluation(child, max_depth - 1, alpha, beta, true));
        
        if (beta <= alpha)
          break;
      }
    }
    return beta;
  }
}