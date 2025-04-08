#include "Point.h"

void Point::move(Direction d) {
	switch (d) {
	case Direction::UP:
		y = (MAX_Y + (y - 1)) % MAX_Y;
		break;
	case Direction::LEFT:
		x = (MAX_X + (x - 1)) % MAX_X;
		break;
	case Direction::DOWN:
		y = (y + 1) % MAX_Y;
		break;
	case Direction::RIGHT:
		x = (x + 1) % MAX_X;
		break;
	}
}
