#pragma once
#include "utils.h"
#include "Board.h"
#include "Menu.h"

class Entity {
public:
	struct Direction {
		int x, y;
	};

	static constexpr Direction directions[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, 0} };

protected:

	Direction dir{ 0, 0 };
	char ch = emptyChar;
	Board* pBoard = nullptr;

	bool pointErased = false;

	int x = 0, y = 0;

	int erasedPositionX = 0;
	int erasedPositionY = 0;

	int newXPosition = 0;
	int newYPosition = 0;

	int startingPositionX = 0;
	int startingPositionY = 0;

	void restoreErasedPoints();

	void draw(char c) {
		restoreErasedPoints();
		printToScreen(x, y, c);
	}

public:
	Entity() = default;

	Entity(Board* board, char ch, int startingX, int startingY) {
		setBoard(*board);
		setChar(ch);
		setStartingPosition(startingX, startingY);
	}

	Entity(Board* board, char ch) {
		setBoard(*board);
		setChar(ch);
	}

	virtual void move();

	void setChar(char c) { ch = c; }
	void setBoard(Board& board) { pBoard = &board; }
	void setXValue(int newX) { x = newX; }
	void setYValue(int newY) { y = newY; }

	int getX() const { return x; }
	int getY() const { return y; }

	//TODO
	//int getDirX() const { return dir.x; }
	//int getDirY() const { return dir.y; }
	//Direction getDirection() const { return dir; }

	char getChar() const { return ch; }
	int getStartingPositionX() const { return startingPositionX; }
	int getStartingPositionY() const { return startingPositionY; }


	virtual void setStartingPosition(int x, int y) {
		startingPositionX = x;
		startingPositionY = y;

		this->x = startingPositionX;
		this->y = startingPositionY;
	}
	void setnewXPosition(int x) { newXPosition = x; }
	void setnewYPosition(int y) { newYPosition = y; }
	Direction getDirection() const { return dir; }

	virtual void draw() {
		restoreErasedPoints();
		printToScreen(x, y, ch);
	}

	virtual void erase() {
		printToScreen(x, y, emptyChar);
	}

	bool touchingWalls();

};

