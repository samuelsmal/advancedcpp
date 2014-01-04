/*
 * MyPlayfield.h
 *
 *  Created on: 18.12.2013
 *      Author: CT
 */

#ifndef MYPLAYFIELD_H_
#define MYPLAYFIELD_H_

#include "playfield.h"
#include <vector>

class MyPlayfield : public playfield {

protected:
	// the internal representation of the field -- may be changed
	char rep[playfield::height][playfield::width];

public:
	MyPlayfield();
	MyPlayfield(const playfield &field);

	int stoneat(int x, int y) const;
	void ResetBoard();
	void PrintBoard();
	int Victory();
	void PutStone(int col);
	void RemoveStone(int col);

	std::vector<int>* GetMoves();

	int myTurn = 1;
	int myPlayer = 1;
	int otherPlayer = 2;

};

#endif /* PLAYFIELD_H__ */
