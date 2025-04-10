#pragma once

#include "utils.h"
#include "Entity.h"
#include "Board.h"
#include "Canon.h"


class Tank : public Entity
{
	std::string keys = "";

	CanonDirection canonDirection = Up;
	TrackStatus leftTrack = Stop;
	TrackStatus rightTrack = Stop;

	size_t numKeys = 0;

	Canon canon;

	int playerNum = 0;

	char prevKey = '\0';
	char currentKey = '\0';


	bool rdyToFire = true;
	bool Shoot = false;
	bool canRotateCannon = true;

public:
	Tank(Board* board, int YPos = 0, int XPos = 0) : Entity() {
		setChar(playerChar);
		setBoard(*board);
		setStartingPosition(XPos, YPos);
		setStaringCanonPosition(XPos, (YPos - 1));
		canon.setBoard(*board);
		canon.setChar(canonUp);
		canon.setStartingPosition(XPos, (YPos - 1));
		startingPositionX = x;
		startingPositionY = y;
	}

	void keyPressed(char key);
	void move() override;

	void eraseAndMovePlayer(Tank& player);

	void setKeys(const char* karr) {
		keys = karr;
	}
	void setCurrentKey(char key) {
		currentKey = key;
	}
	void setPlayerNum(int num) {
		playerNum = num;
	}
	void setCanonDirection(CanonDirection x) {
		canonDirection = x;
	}
	void setCannonRotation(bool x) {
		canRotateCannon = x;
	}
	void setLeftTrack(TrackStatus x) {
		leftTrack = x;
	}
	void setRightTrack(TrackStatus x) {
		rightTrack = x;
	}
	void setShoot(bool x) {
		Shoot = x;
	}
	void setStaringCanonPosition(int x, int y) {
		canon.setStartingPosition(x, y);
	}
	void setCanonLocation();
	void setNumKeys() {
        numKeys = keys.length();
	}

	int getPlayerNum() {
		return playerNum;
	}
	size_t getNumKeys() {
		return numKeys;
	}
	char getkeys(int i) {
		return keys[i];
	}

	void rotatCanon();

	void moveForward();
	void moveBackward();
	bool CanonWallCheck(const Rotation& rotation);

	void draw() override;
	void erase() override;

	virtual void setStartingPosition(int x, int y) {
		startingPositionX = x;
		startingPositionY = y;

		canon.setStartingPosition(x, y - 1);

		this->x = startingPositionX;
		this->y = startingPositionY;
	}
};

