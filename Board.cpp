/*
 * Board.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: jacobadamsky
 */

#include "Board.h"

namespace std {
	Board::~Board() {
	}

#define CARRIER 5
#define BATTLESHIP 4
#define DESTROYER 3
#define SUBMARINE 2
#define PATROL 1

	template<class T>
	int Board::vectorSize(vector<T> vector) {
		int size = 0;
		for (T _ : vector) {
			size++;
		}
		return size;
	}

	void Board::startGame() {
		printf("%s%s%s%s", "Welcome to Battleship! You will be prompted to input coordinates for each ship. Input your coordinates \n",
			"individually (i.e press 1, then enter, press 2, then enter, then V or H for vertical or horizontal). \n",
			"You will then be prompted to input coordinates to shoot at. A miss is represented by O and a hit by X.\n",
			"Press any key to continue or ESC to exit.\n");
		switch (getch()) {
		case 27:
			return;
		default:
			printBoard(this->playerBoard, false);
			getPlayerCoords(1);
			break;
		}
	}

	void Board::getPlayerCoords(int i) {
		string xstr, ystr, orientation;
		int xcor, ycor, size;
		switch (i) {
		case 1:
			printf("\nInput coordinates for Patrol Ship:\n");
			getline(cin, xstr);
			getline(cin, ystr);
			getline(cin, orientation);
			xcor = (int)strtol(xstr.c_str(), NULL, 10);
			ycor = (int)strtol(ystr.c_str(), NULL, 10);
			size = 2;
			break;
		case 2:
			printf("\nInput coordinates for Submarine:\n");
			getline(cin, xstr);
			getline(cin, ystr);
			getline(cin, orientation);
			xcor = (int)strtol(xstr.c_str(), NULL, 10);
			ycor = (int)strtol(ystr.c_str(), NULL, 10);
			size = 3;
			break;
		case 3:
			printf("\nInput coordinates for Destroyer:\n");
			getline(cin, xstr);
			getline(cin, ystr);
			getline(cin, orientation);
			xcor = (int)strtol(xstr.c_str(), NULL, 10);
			ycor = (int)strtol(ystr.c_str(), NULL, 10);
			size = 3;
			break;
		case 4:
			printf("\nInput coordinates for Battleship:\n");
			getline(cin, xstr);
			getline(cin, ystr);
			getline(cin, orientation);
			xcor = (int)strtol(xstr.c_str(), NULL, 10);
			ycor = (int)strtol(ystr.c_str(), NULL, 10);
			size = 4;
			break;
		case 5:
			printf("\nInput coordinates for Carrier:\n");
			getline(cin, xstr);
			getline(cin, ystr);
			getline(cin, orientation);
			xcor = (int)strtol(xstr.c_str(), NULL, 10);
			ycor = (int)strtol(ystr.c_str(), NULL, 10);
			size = 5;
			break;
		}
		if (i != 6) {
			if (xcor == 0 || ycor == 0) {
				printf("Those are not valid coordinates for this ship, try again\n");
				getPlayerCoords(i);
				return;
			}
			if (orientation == "V" || orientation == "v") {
				if (10 - size + 1 >= ycor) {
					if (10 - size + 1 >= xcor) {
						Ship* ship = new Ship(i, xcor, ycor, true);
						for (Ship plrShip : this->playerShips) {
							if (plrShip.intersecting(*(ship))) {
								printf("Your ships cannot overlap, try again.\n");
								getPlayerCoords(i);
								return;
							}
						}
						this->playerShips.push_back(*(ship));
						addShip(ship);
						printBoard(this->playerBoard, false);
						getPlayerCoords(i + 1);
						return;
					}
					else {
						printf("Those are not valid coordinates for this ship, try again.\n");
						getPlayerCoords(i);
						return;
					}
				}
				else {
					printf("Those are not valid coordinates for this ship, try again.\n");
					getPlayerCoords(i);
					return;
				}
			}
			else if (orientation == "H" || orientation == "h") {
				if (10 - size + 1 >= xcor) {
					if (10 - size + 1 >= ycor) {
						Ship* ship = new Ship(i, xcor, ycor, false);
						for (Ship plrShip : this->playerShips) {
							printf("Your ships cannot overlap, try again.\n");
							if (plrShip.intersecting(*(ship))) {
								getPlayerCoords(i);
								return;
							}
						}
						this->playerShips.push_back(*(ship));
						addShip(ship);
						printBoard(this->playerBoard, false);
						getPlayerCoords(i + 1);
						return;
					}
					else {
						printf("Those are not valid coordinates for this ship, try again.\n");
						getPlayerCoords(i);
						return;
					}
				}
				else {
					printf("Those are not valid coordinates for this ship, try again.\n");
					getPlayerCoords(i);
					return;
				}
			}
			else {
				printf("Those are not valid inputs, try again.\n");
				getPlayerCoords(i);
				return;
			}
		}
		else {
			srand(0);
			genCompShips(1);
		}
	}

	void Board::addShip(Ship* ship) {
		if (ship->vert) {
			if (ship->name.compare("PATROL") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 1;
				}
			}
			else if (ship->name.compare("SUBMARINE") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 2;
				}
			}
			else if (ship->name.compare("DESTROYER") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 3;
				}
			}
			else if (ship->name.compare("BATTLESHIP") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 4;
				}
			}
			else if (ship->name.compare("CARRIER") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 5;
				}
			}
		}
		else {
			if (ship->name.compare("PATROL") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 1;
				}
			}
			else if (ship->name.compare("SUBMARINE") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 2;
				}
			}
			else if (ship->name.compare("DESTROYER") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 3;
				}
			}
			else if (ship->name.compare("BATTLESHIP") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 4;
				}
			}
			else if (ship->name.compare("CARRIER") == 0) {
				for (Pair pair : ship->coords) {
					*(playerBoard + pair.x - 1 + (10 * (pair.y - 1))) = 5;
				}
			}
		}
	}

	void Board::compShoot() {
		int x = std::rand() % 10 + 1;
		int y = std::rand() % 10 + 1;
		Pair shot = { x, y };
		for (Pair pair : compGuessed) {
			if (pair == shot) {
				compShoot();
				return;
			}
		}
		compGuessed.push_back(shot);
		switch (*(playerBoard + shot.x - 1 + (10 * (shot.y - 1)))) {
		case 0:
			*(playerBoard + shot.x - 1 + (10 * (shot.y - 1))) = 8;
			break;
		default:
			*(playerBoard + shot.x - 1 + (10 * (shot.y - 1))) = 9;
			break;
		}
		if (checkWinner() == -1) {
			printf("Computer wins!");
			return;
		}
		else {
			printBoard(playerBoard, false);
			playerShoot();
		}
		return;
	}

	void Board::playerShoot() {
		string xstr, ystr;
		getline(cin, xstr);
		getline(cin, ystr);
		int xcor = (int)strtol(xstr.c_str(), NULL, 10);
		int ycor = (int)strtol(ystr.c_str(), NULL, 10);
		Pair shot = { xcor, ycor };
		if (xcor > 10 || ycor > 10) {
			printf("Those are not valid coordinates, try again!\n");
			playerShoot();
			return;
		}
		for (Pair pair : playerGuessed) {
			if (pair == shot) {
				printf("You already shot there, shoot again!\n");
				playerShoot();
				return;
			}
		}
		printf("Shooting at coordinates %d, %d!\n", xcor, ycor);
		playerGuessed.push_back(shot);
		switch (*(compBoard + shot.x - 1 + (10 * (shot.y - 1)))) {
		case 0:
			*(compBoard + shot.x - 1 + (10 * (shot.y - 1))) = 8;
			printf("%d, %d was a miss.\n", xcor, ycor);
			break;
		default:
			*(compBoard + shot.x - 1 + (10 * (shot.y - 1))) = 9;
			printf("%d, %d was a hit!\n", xcor, ycor);
			break;
		}
		if (checkWinner() == 1) {
			printf("You win!\n");
			return;
		}
		else {
			printBoard(compBoard, false); //set to true for no cheating
			printf("\n");
			compShoot();
		}
		return;
	}

	template<class T>
	int vectorcount(vector<T> vector, T check) {
		int count = 0;
		for (T val : vector) {
			if (val == check) {
				count++;
			}
		}
		return count;
	}

	int Board::checkWinner() {
		vector<int> player;
		vector<int> comp;
		WinPTS win;
		for (int i = 0; i < 100; i++) {
			player.push_back(*(playerBoard + i));
			comp.push_back(*(compBoard + i));
		}
		//player wins?
		if ((vectorcount(comp, 0) + vectorcount(comp, 8) + vectorcount(comp, 9)) == 100) {
			return 1;
		}
		//computer wins?
		if ((vectorcount(player, 0) + vectorcount(player, 8) + vectorcount(player, 9)) == 100) {
			return -1;
		}
		int compCount = (vectorcount(comp, 0) + vectorcount(comp, 8) + vectorcount(comp, 9));
		int playerCount = (vectorcount(player, 0) + vectorcount(player, 8) + vectorcount(player, 9));
		printf("Computer Tiles Remaining: %d\n", 100 - compCount);
		printf("Player Tiles Remaining: %d\n", 100 - playerCount);
		return 0;
	}

	void Board::addCompShips(vector<Ship>& ships) {
		for (Ship ship : ships) {
			for (Pair pair : ship.coords) {
				*(compBoard + pair.x - 1 + (10 * (pair.y - 1))) = ship.id;
			}
		}
		printBoard(compBoard, true);
		if (rand() % 2 == 1) {
			compShoot();
			return;
		}
		playerShoot();
		return;
	}

	void Board::genCompShips(int shipNum) {
		bool vert = std::rand() % 2 == 1 ? true : false;
		int x = std::rand() % 10 + 1;
		int y = std::rand() % 10 + 1;
		if (10 - indToSize.find(shipNum)->second + 1 < y) {
			genCompShips(shipNum);
			return;
		}
		else if (10 - indToSize.find(shipNum)->second + 1 < x) {
			genCompShips(shipNum);
			return;
		}
		else if (shipNum == 1) {
			Ship ship(shipNum, x, y, vert);
			compShips.push_back(ship);
			genCompShips(shipNum + 1);
		}
		else if (shipNum != 5) {
			Ship* ship = new Ship(shipNum, x, y, vert);
			for (Ship compShip : compShips) {
				if (compShip.intersecting(*(ship))) {
					genCompShips(shipNum);
					return;
				}
				else {
					compShips.push_back(*(ship));
					genCompShips(shipNum + 1);
					return;
				}
			}
		}
		else if (shipNum == 5) {
			Ship ship(shipNum, x, y, vert);
			for (Ship compShip : compShips) {
				if (compShip.intersecting(ship)) {
					genCompShips(shipNum);
					return;
				}
				else {
					compShips.push_back(ship);
					addCompShips(compShips);
					return;
				}
			}
		}
	}

	void Board::printBoard(int* arr, bool comp) {
		if (comp) {
			printf("Computer Board\n");
		}
		else {
			printf("Your Board\n");
		}
		printf("    1 2 3 4 5 6 7 8 9 10\n   ---------------------\n");
		for (int i = 0; i < this->x; i++) {
			if (i == 9) {
				printf("%d| ", (i + 1));
			}
			else {
				printf("%d | ", (i + 1));
			}
			for (int j = 0; j < this->y; j++) {
				switch (*(arr + (j + (i * this->y)))) {
				case 0:
					printf(". ");
					break;
				case CARRIER:
					if (comp) {
						printf(". ");
						break;
					}
					printf("C ");
					break;
				case BATTLESHIP:
					if (comp) {
						printf(". ");
						break;
					}
					printf("B ");
					break;
				case DESTROYER:
					if (comp) {
						printf(". ");
						break;
					}
					printf("D ");
					break;
				case SUBMARINE:
					if (comp) {
						printf(". ");
						break;
					}
					printf("S ");
					break;
				case PATROL:
					if (comp) {
						printf(". ");
						break;
					}
					printf("P ");
					break;
				case 8:
					printf("O ");
					break;
				case 9:
					printf("X ");
					break;
				default:
					printf("? ");
					break;
				}
			}
			printf("\n");
		}
	}

} /* namespace std */
