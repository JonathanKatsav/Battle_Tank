#pragma once

#include <iostream>
#include "utils.h"

class Point {
	int x = 1, y = 1;
	int dir_x = 1, dir_y = 1;
	enum { MIN_X = 0, MIN_Y = 0, MAX_X = 79, MAX_Y = 24};
public:
	void draw(char ch = '*') {
		gotoxy(x, y);
		std::cout << ch;
	}
	void erase() {
		draw(' ');
	}
	void move();
};

