#include "Snake.h"

void Snake::move(Direction d)
{
	body[Size - 1].erase();
	for (int i = Size - 1; i > 0; --i) {
		body[i] = body[i - 1];
	}
	body[0].move(d);
	body[0].draw();
}
