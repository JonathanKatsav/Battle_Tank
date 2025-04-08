#include "Tank.h"


//TODO: need to splitn  into keys and set the diractions correctly
void Tank::keyPressed(char key) {
	char savedCurrKey = currentKey;
    for (size_t i = 0; i < sizeof(Tank::keys); i++) {
        if (std::tolower(key) == Tank::keys[i]) {
            currentKey = Tank::keys[i];
        }
    }

    if (prevKey != savedCurrKey)
        prevKey = savedCurrKey;

    switch (currentKey) {
    case 'e': case 'o':
		setRightTrack(Forward);
        break;
    case 'd': case 'l':
		setRightTrack(Backward);   
        break;
    case 'q': case 'u':
		setLeftTrack(Forward);
        break;
    case 'a': case 'j':
		setLeftTrack(Backward);
        break;
    case 's': case 'k':
		setLeftTrack(Stop);
		setRightTrack(Stop);
        break;
    case 'w': case 'i':
        setLeftTrack(Stop);
        setRightTrack(Stop);
        setShoot(true);
        break;
    default:
        break;
    }
}

//TODO
void Tank::move() {
    if (leftTrack == Forward == rightTrack) {
        moveForward();
    }
    else if (leftTrack == Backward == rightTrack) {
        moveBackward();
    }
    else
    rotatCanon();

    


    // Call the move function of the Object class
    Entity::move();
	this->cannon.move(canonDirection, x, y);
}

void Tank::eraseAndMovePlayer(Tank& player) {
    player.erase();
    player.move();
}

void Tank::rotatCanon() {
    // Rotating "slow" clockwise
    if (leftTrack == Forward && rightTrack == Stop) {
        if(!CanonWallCheck(Clockwise))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) + 1 + 8) % 8);
    }
    else if (leftTrack == Stop && rightTrack == Backward) {
        if (!CanonWallCheck(Clockwise))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) + 1 + 8) % 8);
    }
    // Rotating "fast" clockwise
    else if (leftTrack == Forward && rightTrack == Backward) {
        if (!CanonWallCheck(ClockwiseFast))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) + 2 + 8) % 8);
    }
    // Rotating "slow" counter clockwise
    else if (leftTrack == Backward && rightTrack == Stop) {
        if (!CanonWallCheck(CounterClockwise))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) - 1 + 8) % 8);
    }
    else if (leftTrack == Stop && rightTrack == Forward) {
        if (!CanonWallCheck(CounterClockwise))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) - 1 + 8) % 8);
    }
    // Rotating "fast" counter clockwise
    else if (leftTrack == Backward && rightTrack == Forward) {
        if (!CanonWallCheck(CounterClockwiseFast))
        canonDirection = static_cast<CanonDirection>((static_cast<int>(canonDirection) - 2 + 8) % 8);
    }
}

void Tank::moveForward() {
	if (canonDirection == Up)
        setnewYPosition(getY() - 1);
	
    else if (canonDirection == Down)
        setnewYPosition(getY() + 1);
	
    else if (canonDirection == Left)
        setnewXPosition(getX() - 1);
	
    else if (canonDirection == Right)
        setnewXPosition(getX() + 1);
	
    else if (canonDirection == UpRight) {
        setnewXPosition(getX() + 1);
        setnewYPosition(getY() - 1);
    }
    else if (canonDirection == DownRight) {
        setnewXPosition(getX() + 1);
        setnewYPosition(getY() + 1);
    }
	else if (canonDirection == DownLeft) {
		setnewXPosition(getX() - 1);
		setnewYPosition(getY() + 1);
	}
	else if (canonDirection == UpLeft) {
		setnewXPosition(getX() - 1);
		setnewYPosition(getY() - 1);
	}
}

void Tank::moveBackward() {
    if (canonDirection == Up)
        setnewYPosition(getY() + 1);

    else if (canonDirection == Down)
        setnewYPosition(getY() - 1);

    else if (canonDirection == Left)
        setnewXPosition(getX() + 1);

    else if (canonDirection == Right)
        setnewXPosition(getX() - 1);

    else if (canonDirection == UpRight) {
        setnewXPosition(getX() - 1);
        setnewYPosition(getY() + 1);
    }
    else if (canonDirection == DownRight) {
        setnewXPosition(getX() - 1);
        setnewYPosition(getY() - 1);
    }
    else if (canonDirection == DownLeft) {
        setnewXPosition(getX() + 1);
        setnewYPosition(getY() - 1);
    }
    else if (canonDirection == UpLeft) {
        setnewXPosition(getX() + 1);
        setnewYPosition(getY() + 1);
    }
}

bool Tank::CanonWallCheck(const Rotation& rotation) {
    //checking Up position for the cannon
    if (rotation == Clockwise && canonDirection == Up)
		return (pBoard->isWall(pBoard->getChar(x + 1, y - 1)));
    else if (rotation == ClockwiseFast && canonDirection == Up)
        return (pBoard->isWall(pBoard->getChar(x + 1, y)));
    else if (rotation == CounterClockwise && canonDirection == Up)
        return (pBoard->isWall(pBoard->getChar(x - 1, y - 1)));
	else if (rotation == CounterClockwiseFast && canonDirection == Up)
        return (pBoard->isWall(pBoard->getChar(x - 1, y)));

    //checking Down position for the cannon
    if (rotation == Clockwise && canonDirection == Down)
        return (pBoard->isWall(pBoard->getChar(x - 1, y + 1)));
    else if (rotation == ClockwiseFast && canonDirection == Down)
        return (pBoard->isWall(pBoard->getChar(x - 1, y)));
    else if (rotation == CounterClockwise && canonDirection == Down)
        return (pBoard->isWall(pBoard->getChar(x + 1, y + 1)));
    else if (rotation == CounterClockwiseFast && canonDirection == Down)
        return (pBoard->isWall(pBoard->getChar(x + 1, y)));

    //checking Right position for the cannon
    if (rotation == Clockwise && canonDirection == Right)
        return (pBoard->isWall(pBoard->getChar(x + 1, y + 1)));
    else if (rotation == ClockwiseFast && canonDirection == Right)
        return (pBoard->isWall(pBoard->getChar(x, y + 1)));
    else if (rotation == CounterClockwise && canonDirection == Right)
        return (pBoard->isWall(pBoard->getChar(x + 1, y - 1)));
    else if (rotation == CounterClockwiseFast && canonDirection == Right)
        return (pBoard->isWall(pBoard->getChar(x, y - 1)));

    //checking Left position for the cannon
    if (rotation == Clockwise && canonDirection == Left)
        return (pBoard->isWall(pBoard->getChar(x - 1, y - 1)));
    else if (rotation == ClockwiseFast && canonDirection == Left)
        return (pBoard->isWall(pBoard->getChar(x, y - 1)));
    else if (rotation == CounterClockwise && canonDirection == Left)
        return (pBoard->isWall(pBoard->getChar(x - 1, y + 1)));
    else if (rotation == CounterClockwiseFast && canonDirection == Left)
        return (pBoard->isWall(pBoard->getChar(x, y + 1)));

    //checking UpRight position for the cannon
    if (rotation == Clockwise && canonDirection == UpRight)
        return (pBoard->isWall(pBoard->getChar(x + 1, y)));
    else if (rotation == ClockwiseFast && canonDirection == UpRight)
        return (pBoard->isWall(pBoard->getChar(x + 1, y + 1)));
    else if (rotation == CounterClockwise && canonDirection == UpRight)
        return (pBoard->isWall(pBoard->getChar(x, y + 1)));
    else if (rotation == CounterClockwiseFast && canonDirection == UpRight)
        return (pBoard->isWall(pBoard->getChar(x - 1, y - 1)));

    //checking DownRight position for the cannon
    if (rotation == Clockwise && canonDirection == DownRight)
        return (pBoard->isWall(pBoard->getChar(x, y + 1)));
    else if (rotation == ClockwiseFast && canonDirection == DownRight)
        return (pBoard->isWall(pBoard->getChar(x - 1, y + 1)));
    else if (rotation == CounterClockwise && canonDirection == DownRight)
        return (pBoard->isWall(pBoard->getChar(x + 1, y)));
    else if (rotation == CounterClockwiseFast && canonDirection == DownRight)
        return (pBoard->isWall(pBoard->getChar(x + 1, y - 1)));

    //checking DownLeft position for the cannon
    if (rotation == Clockwise && canonDirection == DownLeft)
        return (pBoard->isWall(pBoard->getChar(x - 1, y)));
    else if (rotation == ClockwiseFast && canonDirection == DownLeft)
        return (pBoard->isWall(pBoard->getChar(x - 1, y - 1)));
    else if (rotation == CounterClockwise && canonDirection == DownLeft)
        return (pBoard->isWall(pBoard->getChar(x, y + 1)));
    else if (rotation == CounterClockwiseFast && canonDirection == DownLeft)
        return (pBoard->isWall(pBoard->getChar(x + 1, y + 1)));

    //checking UpLeft position for the cannon
    if (rotation == Clockwise && canonDirection == UpLeft)
        return (pBoard->isWall(pBoard->getChar(x, y - 1)));
    else if (rotation == ClockwiseFast && canonDirection == UpLeft)
        return (pBoard->isWall(pBoard->getChar(x + 1, y - 1)));
    else if (rotation == CounterClockwise && canonDirection == UpLeft)
        return (pBoard->isWall(pBoard->getChar(x - 1, y)));
    else if (rotation == CounterClockwiseFast && canonDirection == UpLeft)
        return (pBoard->isWall(pBoard->getChar(x - 1, y + 1)));
}

void Tank::draw() { 
    restoreErasedPoints();
    printToScreen(x, y, ch);
    this->cannon.draw();
}

    