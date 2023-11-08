/*
 * Ship.h
 *
 *  Created on: Feb 27, 2022
 *      Author: jacobadamsky
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <vector>
#include <string>

namespace std {

#define CARRIER 5
#define BATTLESHIP 4
#define DESTROYER 3
#define SUBMARINE 2
#define PATROL 1

	struct Pair {
		int x, y;
		bool operator==(const Pair& rhs) {
			return (this->x == rhs.x) && (this->y == rhs.y);
		}
	};

	class Ship {
	public:
		Pair start;
		bool vert;
		int len;
		int id;
		Ship(int id, int x, int y, bool vertical) :
			start({ x, y }), vert(vertical), id(id) {
			switch (id) {
			case PATROL:
				len = 2;
				name = std::string("PATROL");
				break;
			case SUBMARINE:
				len = 3;
				name = std::string("SUBMARINE");
				break;
			case DESTROYER:
				len = 3;
				name = std::string("DESTROYER");
				break;
			case BATTLESHIP:
				len = 4;
				name = std::string("BATTLESHIP");
				break;
			default:
				len = 5;
				name = std::string("CARRIER");
				break;
			}
			if (vertical) {
				end = { start.x, start.y + len - 1 };
				for (int i = 0; i < len; i++) {
					Pair ins = { start.x, start.y + i };
					coords.push_back(ins);
				}
			}
			else if (!vertical) {
				end = { start.x + len, start.y };
				for (int i = 0; i < len; i++) {
					Pair ins = { start.x + i, start.y };
					coords.push_back(ins);
				}
			}
		}
		;
		virtual ~Ship();
		bool intersecting(Ship ship);
		string name;
		Pair end;
		std::vector<Pair> coords;
		void print();
		bool operator==(const Ship& ship) {
			return ((this->id == ship.id) && (this->vert == ship.vert) && (this->len == ship.len) && (this->start == ship.start));
		}
	};

} /* namespace std */

#endif /* SHIP_H_ */
