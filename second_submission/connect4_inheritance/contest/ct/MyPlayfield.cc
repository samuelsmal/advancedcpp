/*
 * playfield.cc
 *
 *  Created on: 03.11.2013
 *      Author: CT
 */

#include "MyPlayfield.h"
#include "playfield.h"
#include <iostream>
#include <string.h>

MyPlayfield::MyPlayfield() {};

MyPlayfield::MyPlayfield(const playfield &field) {
	for (int i = 0; i < playfield::playfield::height; ++i) {
		for (int j = 0; j < playfield::playfield::width; ++j) {
			rep[i][j] = field.stoneat(j, i);
		}
	}
}

void MyPlayfield::ResetBoard() {
	memset(rep, 0, sizeof rep);
}

void MyPlayfield::PrintBoard() {
	for (int i = 0; i < height; ++i) {
		std::cout << i + 1 << "| ";
		for (int j = 0; j < width; ++j) {
			switch (rep[i][j]) {
			case 0:
				std::cout << "  ";
				break;
			case 1:
				std::cout << "X ";
				break;
			case 2:
				std::cout << "O ";
				break;
			}
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	std::cout << "   ";
	for (int i = 0; i < width; ++i)
		std::cout << i + 1 << " ";

	std::cout << "\n";
}

void MyPlayfield::PutStone(int col) {
	int k = 0;
	if (rep[k++][col] != 0 || col >= playfield::width || col < 0) {
		std::cerr << "Column full!" << std::endl;
		return;
	}
	while (rep[k][col] == 0 && k < playfield::height)
		++k;
	rep[k - 1][col] = (myTurn == myPlayer) ? myPlayer : otherPlayer;
	myTurn = (myTurn == otherPlayer) ? myPlayer : otherPlayer;
	//PrintBoard();
}

void MyPlayfield::RemoveStone(int col) {
	int i = 0;
	if (rep[playfield::height - 1][col] == 0 || col >= playfield::width
			|| col < 0) {
		std::cerr << "Column empty!" << std::endl;
		return;
	}
	while (rep[i][col] == 0 && i < playfield::height)
		++i;
	rep[i][col] = 0;
	myTurn = (myTurn == otherPlayer) ? myPlayer : otherPlayer;
}

int MyPlayfield::Victory() {
	// horizontal rows
	for (int row = 0; row < playfield::height; row++)
		for (int col = 0; col < playfield::width - 3; col++)
			if (rep[row][col] != 0 && rep[row][col] == rep[row][col + 1]
					&& rep[row][col] == rep[row][col + 2]
					&& rep[row][col] == rep[row][col + 3])
				return rep[row][col];
	// vertical columns
	for (int col = 0; col < playfield::width; col++)
		for (int row = 0; row < playfield::height - 3; row++)
			if (rep[row][col] != 0 && rep[row][col] == rep[row + 1][col]
					&& rep[row][col] == rep[row + 2][col]
					&& rep[row][col] == rep[row + 3][col])
				return rep[row][col];
	// diagonal lower left to upper right
	for (int row = 0; row < playfield::height - 3; row++)
		for (int col = 0; col < playfield::width - 3; col++)
			if (rep[row][col] != 0 && rep[row][col] == rep[row + 1][col + 1]
					&& rep[row][col] == rep[row + 2][col + 2]
					&& rep[row][col] == rep[row + 3][col + 3])
				return rep[row][col];
	// diagonal upper left to lower right
	for (int row = playfield::height - 1; row >= 3; row--)
		for (int col = 0; col < playfield::width - 3; col++)
			if (rep[row][col] != 0 && rep[row][col] == rep[row - 1][col + 1]
					&& rep[row][col] == rep[row - 2][col + 2]
					&& rep[row][col] == rep[row - 3][col + 3])
				return rep[row][col];
	std::vector<int>* still = GetMoves();
	if (still->size() == 0){
		delete still;
		return -1; //draw
	}
	delete still;
	return 0;
}

int MyPlayfield::stoneat(int x, int y) const {
	return rep[y][x];
}

std::vector<int>* MyPlayfield::GetMoves() {
	std::vector<int>* posMoves = new std::vector<int>;
	for (int i = 0; i < playfield::playfield::width; ++i) {
		if (!rep[0][i])
			posMoves->push_back(i);
	}
	return posMoves;
}
