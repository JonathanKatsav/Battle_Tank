#pragma once

#include <iostream>
#include "utils.h"

class Point {
	int x = 1, y = 1;
	char ch = '*';
	enum { MIN_X = 0, MIN_Y = 0, MAX_X = 79, MAX_Y = 24};
public:
	void set(int x1, int y1) {
		x = x1;
		y = y1;
	}
	void setChar(char c) {
		ch = c;
	}
	void draw(char ch) {
		gotoxy(x, y);
		std::cout << ch;
	}
	void draw() {
		draw(ch);
	}
	void erase() {
		draw(' ');
	}
	void move(Direction d);
};

