#pragma once
#include "utils.h"
#include "Entity.h"

class Shell : public Entity {
	bool shellExploded = false;
	bool shellReadyToDelete = false;

public:
	Shell(Board* board, int x, int y) : Entity() {
		setStartingPosition(x, y);
		setChar(shellChar);
		setBoard(*board);
	}
};

