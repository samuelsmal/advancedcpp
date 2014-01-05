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
  
  vector<AI_playfield> children (playfield::width, ai_pf);
  vector<WeightedColumn> weights (playfield::width, {-1, std::numeric_limits<double>::min()});
  
  // Adding a heuristic value specific to the column.
  // 0  1   2   3   4   5   6
  // 0 0.1 0.2 0.3 0.2 0.1  0
  weights.at(0).weight = 0;
  weights.at(1).weight = 0.1;
  weights.at(2).weight = 0.2;
  weights.at(3).weight = 0.3;
  weights.at(4).weight = 0.2;
  weights.at(5).weight = 0.1;
  weights.at(6).weight = 0;
  
  
  auto itr_weights = begin(weights);
  auto itr_children = begin(children);
  
  for (int col {0}; col < playfield::width; ++col, ++itr_children, ++itr_weights) {
    if (pf.stoneat(col, 0) == 0) {
      itr_children->insertStone(col, colour_player);
      
      itr_weights->column = col;
      itr_weights->weight += alphaBetaEvaluation(*itr_children, max_depth, std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), true);
    } else {
      weights.erase(itr_weights);
      children.erase(itr_children);
    }
  }
  
  std::sort(begin(weights), end(weights),
            [](const WeightedColumn& a, const WeightedColumn& b) {
              return a.weight < b.weight;
            });
  
  for (auto w : weights) {
    std::cout << w.weight << " " << w.column << std::endl;
  }
  
  
  return weights.back().column;
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

double AI_AlphaBetaPruning::heuristicEvaluation(const AI_playfield &pf, bool maximizingPlayer) {
  // Count the patterns. "x_xx" => 3, "xxx_xx" => 5, but "xoxx" => 2,...
  if (maximizingPlayer) {
    return AI_Util::playfieldEvaluation(pf, colour_player);
  } else {
    return AI_Util::playfieldEvaluation(pf, colour_opponent);
  }
}

double AI_AlphaBetaPruning::alphaBetaEvaluation(const AI_playfield &pf, int depth, double alpha, double beta, bool maximizingPlayer) {
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