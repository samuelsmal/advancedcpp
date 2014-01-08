#include <algorithm>

#include "computerPlayer.h"

int computerPlayer::measureDirection(int x, int y, int delta_x, int delta_y, int colour, const playfield& field) {
  int found {0};

  x += delta_x; y += delta_y;

  for (int steps {0};
       steps < 3 && x < width_of_field && x >= 0
         && y < height_of_field && y >= 0;
       x += delta_x, y += delta_y, ++steps)
  {
    int stone = field.stoneat(x, y);
    if (stone == colour) {
      ++found;
    } else if (stone != 0){
      break;
    }
  }
  return found;
}

int computerPlayer::weightOfPlace(int x, int y, int colour, const playfield& field) {
  int weight {0}, current_weight {0};

  for (int i_x {-1}; i_x < 2; ++i_x) {
    for (int i_y {-1}; i_y < 2; ++i_y) {
      current_weight = measureDirection(x, y, i_x, i_y, colour, field);
      if (current_weight > weight) weight = current_weight;
    }
  }

  if (y < height_of_field - 1) {
    if (field.stoneat(x, y + 1) == 0 && colour == colour_of_opponent)
      weight *= -1;
  } else if (y < height_of_field - 2) {
    if (field.stoneat(x, y + 2) == 0 && colour == colour_of_player)
      weight *= -1;
  }
  return weight;
}

int computerPlayer::countOnes (const playfield& field) {
  int num_of_stones {0};

  for (int x {0}; x < width_of_field; ++x) {
    for (int y {0}; y < height_of_field; ++y) {
      if (field.stoneat(x, y) == 1)
        ++num_of_stones;
    }
  }
  return num_of_stones;
}

int computerPlayer::play(const playfield& field) {
  if (first_round) {
    if (countOnes(field) == 0) {
      colour_of_opponent = 2;
      colour_of_player = 1;
    } else {
      colour_of_opponent = 1;
      colour_of_player = 2;
    }
    first_round = false;
  }
  weighted_cols.clear();

  for (int x = 0; x < width_of_field; ++x) {
    // Only if column isn't full.
    if (field.stoneat(x, 0) == 0) {
      int max_of_column_player {0}, max_of_column_opponent {0};

      for (int y = 0; y < height_of_field; ++y) {
        if (field.stoneat(x, y) == 0) {
          max_of_column_player = std::max(max_of_column_player,
                                          weightOfPlace(x, y, colour_of_player, field));
          max_of_column_opponent = std::max(max_of_column_opponent,
                                            weightOfPlace(x, y, colour_of_opponent, field));
        }
      }

      if (max_of_column_player >= 3 || max_of_column_opponent >= 3) return x;

      weighted_cols.push_back(
         std::make_tuple(max_of_column_player, max_of_column_opponent, x));
    }
  }

  std::random_shuffle(begin(weighted_cols), end(weighted_cols));
  
  std::stable_sort(begin(weighted_cols), end(weighted_cols),
            [](const weight &left, const weight &right)
              {return std::get<0>(left) < std::get<0>(right);});
  
  std::stable_sort(begin(weighted_cols), end(weighted_cols),
                   [](const weight &left, const weight &right)
                      {return std::get<1>(left) < std::get<1>(right);});

  return std::get<2>(weighted_cols.back());
}