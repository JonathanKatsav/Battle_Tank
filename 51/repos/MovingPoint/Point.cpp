#include "Point.h"

void Point::move() {
	if (x + dir_x < MIN_X || x + dir_x > MAX_X) {
		dir_x = -dir_x;
	}
	if (y + dir_y < MIN_Y || y + dir_y > MAX_Y) {
		dir_y = -dir_y;
	}
	x += dir_x;
	y += dir_y;
}
