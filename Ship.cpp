/*
 * Ship.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: jacobadamsky
 */

#include "Ship.h"
#include <algorithm>

namespace std {

	Ship::~Ship() {
	}

	void Ship::print() {
		printf("ID: %d, start: < %d, %d >, verical: %s, length: %d", this->id, this->start.x, this->start.y, vert ? "vertical" : "horizontal",
			this->len);
	}

	bool Ship::intersecting(Ship ship) {
		if (this->start == ship.start) {
			return true;
		}
		if (this->end == ship.end) {
			return true;
		}
		if (this->vert == ship.vert) {
			if (this->vert) {
				if (this->start.x == ship.start.x) {
					if (this->end.y < ship.end.y && this->end.y >= ship.start.y) {
						return true;
					}
				}
				else if (ship.start.x != this->start.x) {
					return false;
				}
			}
			if (!this->vert) {
				if (this->start.y == ship.start.y) {
					if (this->end.x < ship.end.x && this->end.x >= ship.start.x) {
						return true;
					}
				}
				else if (ship.start.y != this->start.y) {
					return false;
				}
			}
		}
		else {
			if (this->vert) {
				if (this->start.x >= ship.start.x) {
					if (this->start.x <= ship.end.x) {
						if (this->end.y >= ship.end.y) {
							return true;
						}
					}
				}
			}
			else {
				if (this->start.y >= ship.start.y) {
					if (this->start.y <= ship.end.y) {
						if (this->end.x >= ship.end.x) {
							return true;
						}
					}
				}
			}
			for (std::Pair pair1 : ship.coords) {
				for (std::Pair pair2 : this->coords) {
					if (pair1 == pair2) {
						return true;
					}
				}
			}
		}
		return false;
	}
} /* namespace std */
