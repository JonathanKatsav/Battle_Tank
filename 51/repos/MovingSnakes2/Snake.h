#pragma once

#include <string>

#include "Point.h"

class Snake {
	static constexpr int Size = 5;
	Point body[Size];
	Direction dir = Direction::STAY;
	std::string keys = "";
public:
	void setPos(const Point& p) {
		for (auto& b : body) {
			b = p;
		}
	}
	void setChar(char c) {
		body[0].setChar(c);
	}
	void setKeys(const char* karr) {
		keys = karr;
	}
	void move();
	void keyPressed(char c);
};

