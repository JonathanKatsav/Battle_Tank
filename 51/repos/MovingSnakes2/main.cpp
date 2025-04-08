#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Point.h"
#include "Snake.h"
#include "utils.h"

int main() {
    hideCursor();
    Snake s1, s2;
    s1.setKeys("waxds");
    s2.setKeys("ijmlk");
    s1.setChar('@');
    Point p;
    p.set(10, 10);
    s2.setPos(p);
    bool esc_pressed = false;
    while (!esc_pressed) {
        s1.move();
        s2.move();
        for (int i = 0; i < 5; ++i) {
            Sleep(10);
            if (_kbhit()) {
                char key = _getch();
                if (key == Keys::ESC) {
                    esc_pressed = true;
                    break;
                }
                s1.keyPressed(key);
                s2.keyPressed(key);
            }
        }
    }
}
