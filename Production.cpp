/*
 * Production.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: jacobadamsky
 */

#include "Production.h"
#include "Ship.h"
#include "Test.h"
#include "Board.h"

template<class T>
int vectorSize(std::vector<T> vector) {
	int size = 0;
	for (T _ : vector) {
		size++;
	}
	return size;
}
namespace std {

	Production::Production() {

	}

	Production::~Production() {
	}
}

void printCoords(std::Ship ship) {
	printf("Coords for Ship:\n");
	for (std::Pair pair : ship.coords) {
		printf("%d, %d\n", pair.x, pair.y);
	}
}

void welcomeScreen() {
	char box = (char)219u;
	std::cout << box << box << box << box << box << ' ' << ' ' << ' ' << box << box << box << box << ' ' << ' ' << box << box << box << box
		<< box << box << ' ' << box << box << box << box << box << box << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << ' ' << box
		<< box << box << box << box << box << ' ' << ' ' << box << box << box << box << box << ' ' << box << box << ' ' << ' ' << box
		<< box << ' ' << box << box << ' ' << box << box << box << box << box << "\n"; //done

	std::cout << box << box << ' ' << ' ' << box << box << ' ' << box << box << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box
		<< ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << ' ' << box
		<< box << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << box
		<< box << ' ' << box << box << ' ' << box << box << ' ' << box << box << "\n";

	std::cout << box << box << box << box << box << ' ' << ' ' << box << box << box << box << box << box << ' ' << ' ' << ' ' << box << box
		<< ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << ' ' << box
		<< box << box << box << box << box << ' ' << ' ' << box << box << box << box << box << ' ' << box << box << box << box << box
		<< box << ' ' << box << box << ' ' << box << box << box << box << box << "\n";

	std::cout << box << box << ' ' << ' ' << box << box << ' ' << box << box << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box
		<< ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << ' ' << box
		<< box << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << box << box << ' ' << ' ' << box
		<< box << ' ' << box << box << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << "\n";

	std::cout << box << box << box << box << box << ' ' << ' ' << box << box << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box
		<< ' ' << ' ' << ' ' << ' ' << ' ' << box << box << ' ' << ' ' << ' ' << box << box << box << box << box << box << ' ' << box
		<< box << box << box << box << box << ' ' << ' ' << box << box << box << box << box << ' ' << box << box << ' ' << ' ' << box
		<< box << ' ' << box << box << ' ' << box << box << ' ' << ' ' << ' ' << ' ' << "\n";
}

int main() {
	printf("--- Running Tests... ---\n");
	std::Test* test = new std::Test(new std::Board(10, 10));
	test->runTests();
	printf("--- Tests Complete! ---\n");

	welcomeScreen();
	std::Board brd(10, 10);
	brd.startGame();
	return 0;
}
