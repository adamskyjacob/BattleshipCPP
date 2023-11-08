/*
 * Test.cpp
 *
 *  Created on: Feb 28, 2022
 *      Author: jacobadamsky
 */

#include "Test.h"

namespace std {

	Test::~Test() {
	}

	void Test::runTests() {
		testCheckWinner();
		testMakeShip();
		testShipIntersecting();
	}

	void Test::testMakeShip() {
		Ship* ship = new Ship(5, 5, 5, true);
		Pair expected = { 5, 5 };
		if ((ship->len == 5) && (ship->start == expected) && (ship->vert == true)) {
			printf("new Ship(id, x, y, vert) working properly.\n");
		}
		else {
			printf("new Ship(id, x, y, vert) not working properly.\n");
		}
	}

	void Test::testShipIntersecting() {
		bool ship11, ship12, ship13, ship14, ship15, ship23;
		Ship* ship1 = new Ship(1, 5, 5, true);
		Ship* ship2 = new Ship(2, 2, 2, true);
		Ship* ship3 = new Ship(3, 1, 3, false);
		Ship* ship4 = new Ship(4, 5, 9, false);
		Ship* ship5 = new Ship(5, 5, 5, false);
		ship11 = ship1->intersecting(*(ship1)); //true
		ship12 = ship1->intersecting(*(ship2)); //false
		ship13 = ship1->intersecting(*(ship3)); //false
		ship14 = ship1->intersecting(*(ship4)); //false
		ship15 = ship1->intersecting(*(ship5)); //true
		ship23 = ship2->intersecting(*(ship3)); //true
		if (ship11 == true && ship12 == false && ship13 == false && ship14 == false && ship15 == true && ship23 == true) {
			printf("Ship intersecting() working properly.\n");
		}
		else {
			printf("Ship intersecting() not working properly.\n");
		}
	}

	void Test::testCheckWinner() {
		if (this->board->checkWinner() == 1) {
			printf("checkWinner working properly.\n");
			return;
		}
		else {
			printf("checkWinner not working properly.\n");
			return;
		}
	}
}
