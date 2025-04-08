#include "utils.h"
#include "Game.h"

void gotoxy(int x, int y) {
    std::cout.flush();
    COORD coord; // Create a COORD structure
    coord.X = x; // Set the X coordinate
    coord.Y = y; // Set the Y coordinate
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Move the cursor
}

void changeColor(bool isWhite, bool isBoard) {
    HANDLE h2sout = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!isWhite) {
        if (Menu::useColor) {
            if (isBoard)
                SetConsoleTextAttribute(h2sout, FOREGROUND_BLUE);
            else
                SetConsoleTextAttribute(h2sout, FOREGROUND_RED);
        }
    }
    else {
        //return color to white
        if (Menu::useColor) {
            SetConsoleTextAttribute(h2sout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
}

void printToScreen(int x, int y, char c, bool isBoard) {

    changeColor(false, isBoard);
    
    // Check if the coordinates are within the screen bounds
    if (x <= Board::screenX - 1 && x >= 0 && y <= Board::screenY - 1 && y >= 0) {
        gotoxy(x, y);
        std::cout << c;
        
    }
}

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void clearConsole() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}
