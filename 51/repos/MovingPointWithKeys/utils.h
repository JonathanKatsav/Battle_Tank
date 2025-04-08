#pragma once

void gotoxy(int x, int y);
void hideCursor();

enum class Direction {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    STAY
};

enum Keys {ESC = 27};

