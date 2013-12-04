#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <vector>
#include <tuple>

#include "player.h"


struct {
    bool operator()(const std::tuple<int,int,int> &left, const std::tuple<int,int,int> &right) {
        return std::get<0>(left) < std::get<0>(right);
    }
} sort_first;

struct {
    bool operator()(const std::tuple<int,int,int> &left, const std::tuple<int,int,int> &right) {
        return std::get<1>(left) < std::get<1>(right);
    }
} sort_second;

export
template <typename F>
class computerPlayer : public player<F> {
 public:
    computerPlayer() : weighted_cols{} {};

    int play(const F &field);
 private:
    int width_of_field {F::width};
    int height_of_field {F::height};

    int weightOfPlace(int x, int y, int colour, const F& field);
    int numberOfNeighboors(int x, int y, int delta_x, int delta_y, int colour, const F& field);

    int colour_of_player;
    int colour_of_opponent;

    bool first_round {true};
    int countOnes(const F& field);

    // First: Weight for player
    // Second: Weight for opponent
    // Third: Column
    std::vector<std::tuple<int, int, int>> weighted_cols;
};

#include "_computerPlayer.impl"
#endif // COMPUTERPLAYER_H
