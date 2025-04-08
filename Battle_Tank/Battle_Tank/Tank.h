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

	Canon cannon;

	int playerNum = 0;

	char prevKey = '\0';
	char currentKey = '\0';
	

	bool rdyToFire = true;
	bool Shoot = false;
	bool canRotateCannon = true;

public:
	Tank(Board* board, int YPos, int XPos) : Entity()  {
		setChar(playerChar);
		setBoard(*board);
		setStartingPosition(XPos, YPos);
		setStaringCanonPosition(XPos, (YPos - 1));
	}

	void keyPressed(char key);
	void move() override;

	void eraseAndMovePlayer(Tank& player);

	void setKeys(const char* karr) {
		keys = karr;
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
		cannon.setStartingPosition(x, y);
	}

	int getPlayerNum() {
		return playerNum;
	}

	void rotatCanon();

	void moveForward();
	void moveBackward();
	bool CanonWallCheck(const Rotation& rotation);

	void draw() override;
};

