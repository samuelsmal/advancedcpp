#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <vector>
#include <tuple>

#include "player.h"
#include "playfield.h"

class computerPlayer : public player {
 public:
    computerPlayer() : weighted_cols{} {}; // Initializing to zero.

    int play(const playfield &field);
 private:
    int width_of_field {playfield::width};
    int height_of_field {playfield::height};

    int weightOfPlace(int x, int y, int colour, const playfield& field);
    int measureDirection(int x, int y,
                         int delta_x, int delta_y,
                         int colour, const playfield& field);

    int colour_of_player;
    int colour_of_opponent;

    bool first_round {true};
    int countOnes(const playfield& field);

    // First:  Weight for player
    // Second: Weight for opponent
    // Third:  Column
    using weight = std::tuple<int, int, int>;
    std::vector<weight> weighted_cols;
};
#endif // COMPUTERPLAYER_H
