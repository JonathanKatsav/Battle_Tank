#pragma once

#include "utils.h"
#include "Menu.h"


// Forward declarations
class Tank;
class shellManager;
class Entity;



class Board {
public:
	static constexpr int screenX = 80; // Width of the console screen
	static constexpr int screenY = 25; // Height of the console screen

	static constexpr char strongWall = '#'; // Represents a wall with 2 lifes
	static constexpr char weakWall = 'H'; // Represents a wall with 1 life
	static constexpr char empty = ' '; // Represents empty space

	int P1startingX = 0;
	int P1startingY = 0;
	bool isTherePlayer1 = false;

	int P2startingX = 0;
	int P2startingY = 0;
	bool isTherePlayer2 = false;


	bool load(const std::string& filename, Tank& player1, Tank& player2);
	void reset();

private:
	char originalBoard[screenY][screenX + 1]; // +1 for null terminator
	char currentBoard[screenY][screenX + 1]; // +1 for null terminator

	//void fixStartingPosition(Tank& player1, Tank& player2);

public:
	void print() const;

	char getChar(int x, int y) const {
		if (x <= screenX - 1 && x >= 0 && y <= screenY - 1 && y >= 0)
			return currentBoard[y][x];
		return emptyChar;
	}

	char getOriginalChar(int x, int y) const {
		if (x <= screenX - 1 && x >= 0 && y <= screenY - 1 && y >= 0)
			return originalBoard[y][x];

		return emptyChar;
	}

	bool isWall(char c) const {
		return c == Board::strongWall || c == Board::weakWall;
	}
};

