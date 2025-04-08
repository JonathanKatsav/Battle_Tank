#include "Snake.h"

void Snake::move()
{
	body[Size - 1].erase();
	for (int i = Size - 1; i > 0; --i) {
		body[i] = body[i - 1];
	}
	body[0].move(dir);
	body[0].draw();
}

void Snake::keyPressed(char c) {
    int index = 0;
    for (char k : keys) {
		if (c == k) {
			dir = (Direction)index;
		}
		++index;
    }
}
