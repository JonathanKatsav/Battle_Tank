#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <cstdlib> 

constexpr char shellChar = '*';
constexpr char explosionChar = '+';
constexpr char playerChar = 'O';
constexpr char canonUp = '|';
constexpr char canonLeanRight = '/';
constexpr char canonLeanLeft = '\\';
constexpr char canonLean = '-';
constexpr char emptyChar = ' ';


enum Players {
	First,
	Second,
};

enum CanonDirection {
	Up,
	UpRight,
	Right,
	DownRight,
	Down,
	DownLeft,
	Left,
	UpLeft,
};

enum Rotation {
	Clockwise,
	ClockwiseFast,
	CounterClockwise,
	CounterClockwiseFast,
};

enum TrackStatus {
	Forward,
	Backward,
	Stop,
};


void gotoxy(int x, int y);
void printToScreen(int x, int y, char c, bool isBoard = false);
void changeColor(bool isWhite, bool isBoard = false);
void ShowConsoleCursor(bool showFlag);
void clearConsole();
