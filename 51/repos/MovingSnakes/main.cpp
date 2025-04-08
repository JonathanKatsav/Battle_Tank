#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Point.h"
#include "Snake.h"
#include "utils.h"

constexpr char keys[] = {'w', 'a', 'x', 'd', 's'};
constexpr int num_keys = sizeof(keys) / sizeof(keys[0]);

int charToDirIndex(char key) {
    int index = 0;
    for (char k : keys) {
        if (key == k) return index;
        ++index;
    }
    return index;
}

Direction dirIndexToDir(int index) {
    return (Direction)index;
}

int main() {
    hideCursor();
    Snake s1, s2;
    Point p;
    p.set(10, 10);
    s2.setPos(p);
    Direction d = Direction::STAY;
    while (true) {
        Sleep(50);
        if (_kbhit()) {
            char key = _getch();
            if (key == Keys::ESC) break;
            int index = charToDirIndex(key);
            if (index < num_keys) {
                d = dirIndexToDir(index);
            }
        }
        s1.move(d);
        s2.move(d);
    }
}
