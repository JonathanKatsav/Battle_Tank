#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Point.h"
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
    Point p;
    Direction d = Direction::STAY;
    while (true) {
        p.draw();
        Sleep(50);
        p.erase();
        if (_kbhit()) {
            char key = _getch();
            if (key == Keys::ESC) break;
            int index = charToDirIndex(key);
            if (index < num_keys) {
                d = dirIndexToDir(index);
            }
        }
        p.move(d);
    }
}
