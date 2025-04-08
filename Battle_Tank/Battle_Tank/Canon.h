#pragma once
#include "utils.h"
#include "Board.h"
#include "Entity.h"

class Tank;

class Canon : public Entity
{
	char canonChar = canonUp;

public :


	void move(CanonDirection direction, int x, int y);
	
	//void draw(CanonDirection canonDirection, int x, int y);
};

