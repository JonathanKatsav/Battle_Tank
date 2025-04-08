#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Point.h"

int main() {
    hideCursor();
    Point p;
    while (!_kbhit()) {
        p.draw();
        Sleep(50);
        p.erase();
        p.move();
    }
}
