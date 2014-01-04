/*
 * MiniMaxPlayer.h
 *
 *  Created on: 18.12.2013
 *      Author: CT
 */

#ifndef MINIMAXPLAYER_H_
#define MINIMAXPLAYER_H_

#include "MyPlayfield.h"
#include "Heuristics.h"
#include "MyPlayfield.h"

#include "player.h"
#include "playfield.h"


class MiniMaxPlayer : public player {

public:
	int play(const playfield &field);

	float RateCol(MyPlayfield &p, int Move, int deep);

	static const int strength = 2;
	static const int MAX_DEEP = 3;
	Heuristics heuristics;

};

#endif
