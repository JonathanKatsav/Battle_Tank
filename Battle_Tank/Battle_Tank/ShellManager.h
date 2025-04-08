#pragma once
#include "ObstaclesManager.h"
#include "utils.h"
#include "Shells.h"


class ShellManager : public ObstaclesManager<Shell> {

	std::vector<Shell> shells;
	std::vector<std::pair<int, int>> startingPositions;
	Board* pBoard = nullptr;

public:
	ShellManager(Board& board) {
		pBoard = &board;
	}

	bool checkCollisionWithPlayer(Tank& player) override;
	void add() override;
	void move() override;

	void addStartingPosition(int x, int y) {
		startingPositions.push_back(std::make_pair(x, y));
	}

	int getStartingPositionX(int position) const { return startingPositions[position].first; }
	int getStartingPositionY(int position) const { return startingPositions[position].second; }
	int getStartingPositionLength() const { return startingPositions.size(); }
	void setStartingPositionY(int position, int y) { startingPositions[position].second = y; }
	void createAndDrawShells(ShellManager& shellManager);
	void eraseAndMoveShells(ShellManager& shellManager);
};

