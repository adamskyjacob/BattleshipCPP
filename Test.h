/*
 * Test.h
 *
 *  Created on: Feb 28, 2022
 *      Author: jacobadamsky
 */

#ifndef TEST_H_
#define TEST_H_

#include "Board.h"
#include "Ship.h"

namespace std {

	class Test {
	public:
		Test(Board* brd) :
			board(brd) {
		}
		virtual ~Test();
		void runTests();
		void testCheckWinner();
		void testMakeShip();
		void testShipIntersecting();
		Board* board;
	};

} /* namespace std */

#endif /* TEST_H_ */
