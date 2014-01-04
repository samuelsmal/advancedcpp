#include <stdexcept>
#include <algorithm>

int AIV2::play(const playfield& field) {
  if (first_round) {
    determineColours(field);
    first_round = false;
  }
  
  //
  // Setup for the new round:
  //
  initVirtualPlayfields(field);
  
  measuredColumns.clear();
  
  //
  // Place on stone of the players colour and measure the column:
  //
  
  // Insert player stone:
  for (int col {0}; col < width_of_field; ++col) {
    if (virtual_playfields.at(col).stoneat(col, 0) == 0) {
      insertStone(virtual_playfields.at(col), col, virtual_colour_of_player);
    } else {
      virtual_playfields.erase(virtual_playfields.begin() + col);
    }
  }
  
  // Insert opponent stones:
//  for (auto itr = virtual_playfields.begin(); itr != virtual_playfields.end(); ++itr) {
//    for (int col {0}; col < width_of_field; ++col) {
//      if (itr->stoneat(col, 0) == 0) {
//        insertStone(*itr, col, virtual_colour_of_opponent);
//      }
//    }
//  }
  
  // Measure the playfields columns:
  for (auto itr = virtual_playfields.begin(); itr != virtual_playfields.end(); ++itr) {
    measuredColumns.emplace_back(measurePlayfield(*itr));
  }
  
  std::sort(measuredColumns.begin(), measuredColumns.end(),
            [](const ColumnWeight& a, const ColumnWeight& b){
              return a.opponent < b.opponent;
            });
  
  std::stable_sort(measuredColumns.begin(), measuredColumns.end(),
                   [](const ColumnWeight& a, const ColumnWeight& b){
                     return a.player < b.player;
                   });
  
  for (ColumnWeight c : measuredColumns) {
    std::cout << "    column: " << c.column << ": (" << c.player << ", " << c.opponent << ")\n";
  }
  
  return measuredColumns.end()->column;
}

void AIV2::initVirtualPlayfields(const AI_playfield& field) {
  virtual_playfields.clear();
  
  for (int i {0}; i < width_of_field; ++i) {
    virtual_playfields.emplace_back(field);
  }
}

void AIV2::insertStone(AI_playfield& field, int column, colour_t colour) {
  if (field.stoneat(column, 0) != 0)
    throw std::logic_error("Already full");
  
  int tmp_y {height_of_field - 1};
  
  while (field.stoneat(column, tmp_y) != 0)
    --tmp_y;
  
  field.insertStone(column, tmp_y, colour);
}

ColumnWeight AIV2::measurePlayfield(AI_playfield& field) {
  ColumnWeight weight;
  colour_t current_stone;
  for (int i {0}; i < width_of_field; ++i) {
    for (int j {0}; j < height_of_field; ++j) {
      current_stone = field.stoneat(i, j);
      if (current_stone == virtual_colour_of_player)
        weight = measureColumn(field, i);
    }
  }
  
  return weight;
}

ColumnWeight AIV2::measureColumn(AI_playfield& field, int column) {
  ColumnWeight weight(column);
  colour_t current_stone;
  
  // measure row
  for (int row {0}; row < height_of_field; ++row) {
    current_stone = field.stoneat(column, row);
    
    if (current_stone == virtual_colour_of_player) {
      weight.player = measureStone(field, column, row, current_stone);
    } else if (current_stone == virtual_colour_of_opponent) {
      weight.opponent = measureStone(field, column, row, current_stone);
    }
  }
  
  field.print();
  std::cout <<  weight.player << ", " << weight.opponent << std::endl;
  
  return weight;
}

int AIV2::measureStone(AI_playfield& field, int x, int y, colour_t colour) {
  int measure {0};
  for (int d_x {-1}; d_x < 2; ++d_x) {
    for (int d_y {-1}; d_y < 2; ++d_y) {
      if (d_x != -1 && d_y != -1)
        measure = std::max(measure, measureDirection(field, x, y, d_x, d_y, colour));
    }
  }
  return measure;
}

int AIV2::measureDirection(AI_playfield& field,
                              int x, int y,
                              int d_x, int d_y,
                              colour_t colour) {
  int measure {1}; // The first stone is already of the correct type.
  colour_t stone;
  for (int steps {0}; steps < 4; ++steps, x += d_x, y += d_y) {
    stone = field.stoneat(x, y);
    if (stone == colour) {
      ++measure;
    } else if (stone != 0) {
      break;
    }
  }
  
  return measure;
}

void AIV2::determineColours(const AI_playfield& field) {
  if (countOnes(field) == 0) {
    real_colour_of_opponent = 2;
    real_colour_of_player = 1;
    
    virtual_colour_of_player = 3;
    virtual_colour_of_opponent = 4;
  } else {
    real_colour_of_player = 2;
    real_colour_of_opponent = 1;
    
    virtual_colour_of_player = 4;
    virtual_colour_of_opponent = 3;
  }
}

int AIV2::countOnes(const AI_playfield& field) {
  int num_of_stones {0};
  
  for (int x {0}; x < width_of_field; ++x) {
    for (int y {0}; y < height_of_field; ++y) {
      if (field.stoneat(x, y) == 1)
        ++num_of_stones;
    }
  }
  return num_of_stones;
}