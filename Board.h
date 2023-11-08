/*
 * Board.h
 *
 *  Created on: Feb 27, 2022
 *      Author: jacobadamsky
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <sys/time.h>
#include <chrono>
#include <thread>

namespace std {

	struct WinPTS {
		vector<int> pts = { 0, 8, 9 };
		bool contains(int check) {
			for (int num : pts) {
				if (num == check) {
					return true;
				}
			}
			return false;
		}
	};

	class Board {
	public:
		Board(int ROWS, int COLS) :
			x(ROWS), y(COLS), playerBoard((int*)malloc(ROWS* COLS * sizeof(int))), compBoard((int*)malloc(ROWS* COLS * sizeof(int))) {
			for (int num = 0; num < ROWS * COLS; num++) {
				*(playerBoard + num) = 0;
				*(compBoard + num) = 0;
			}
		}
		virtual ~Board();
		int x, y;
		WinPTS winPTS;
		int* playerBoard;
		int* compBoard;
		void printBoard(int*, bool comp);
		void startGame();
		map<int, int> indToSize = { { 1, 2 }, { 2, 3 }, { 3, 3 }, { 4, 4 }, { 5, 5 } };
		std::vector<Pair> compPoints;
		std::vector<Pair> playerGuessed;
		std::vector<Pair> compGuessed;
		std::vector<Ship> playerShips;
		std::vector<Ship> compShips;
		void getPlayerCoords(int i);
		void addShip(Ship* ship);
		void addCompShips(vector<Ship>& ships);
		void genCompShips(int);
		void setupCompShips();
		void playerShoot();
		void compShoot();
		int checkWinner();

		template<class T>
		int vectorSize(vector<T> vector);
	};

} /* namespace std */

#endif /* BOARD_H_ */
