#pragma once

#include "Point.h"

class Snake {
	static constexpr int Size = 5;
	Point body[Size];
public:
	void setPos(const Point& p) {
		for (auto& b : body) {
			b = p;
		}
	}
	void move(Direction d);
};

