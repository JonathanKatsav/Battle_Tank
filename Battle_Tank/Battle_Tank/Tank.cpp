#include "Tank.h"



void Tank::keyPressed(char key) {
    char savedCurrKey = currentKey;
    
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
    if (leftTrack == Forward && rightTrack == Forward) {
        moveForward();
    }
    else if (leftTrack == Backward && rightTrack == Backward) {
        moveBackward();
    }
    else if (leftTrack == Stop && rightTrack == Stop) {
        newXPosition = x;
        newYPosition = y;

    }
    else
        rotatCanon();

    if (touchingWalls()) {
        newXPosition = x;
        newYPosition = y;
    }
    setCanonLocation();


    //TODO: adding checks to the movments of the tank (canon ristrictions and stuff) 


    // Call the move function of the Object class
    Entity::move();
    this->canon.move(canonDirection, x, y);
}

void Tank::eraseAndMovePlayer(Tank& player) {
    player.erase();
    player.move();
}

void Tank::rotatCanon() {
    // Rotating "slow" clockwise
    if (leftTrack == Forward && rightTrack == Stop) {
        if (!CanonWallCheck(Clockwise))
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
   int  fullScreenX = this->pBoard->screenX;
   int  fullScreenY = this->pBoard->screenY;
    if (canonDirection == Up)
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);

    else if (canonDirection == Down)
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);

    else if (canonDirection == Left)
        setnewXPosition((fullScreenX + (getX() - 1)) % fullScreenX);

    else if (canonDirection == Right)
        setnewXPosition((fullScreenX + (getX() + 1)) % fullScreenX);

    else if (canonDirection == UpRight) {
        setnewXPosition((fullScreenX + (getX() + 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);
    }
    else if (canonDirection == DownRight) {
        setnewXPosition((fullScreenX + (getX() + 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);
    }
    else if (canonDirection == DownLeft) {
        setnewXPosition((fullScreenX + (getX() - 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);
    }
    else if (canonDirection == UpLeft) {
        setnewXPosition(getX() - 1);
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);
    }
}

void Tank::moveBackward() {
    int  fullScreenX = this->pBoard->screenX;
    int  fullScreenY = this->pBoard->screenY;
    if (canonDirection == Up)
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);
    
    else if (canonDirection == Down)
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);

    else if (canonDirection == Left)
        setnewXPosition((fullScreenX + (getX() + 1)) % fullScreenX);

    else if (canonDirection == Right)
        setnewXPosition((fullScreenX + (getX() - 1)) % fullScreenX);

    else if (canonDirection == UpRight) {
        setnewXPosition((fullScreenX + (getX() - 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);
    }
    else if (canonDirection == DownRight) {
        setnewXPosition((fullScreenX + (getX() - 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);
    }
    else if (canonDirection == DownLeft) {
        setnewXPosition((fullScreenX + (getX() + 1)) % fullScreenX);
        setnewYPosition((fullScreenY + (getY() - 1)) % fullScreenY);
    }
    else if (canonDirection == UpLeft) {
        setnewXPosition(getX() + 1);
        setnewYPosition((fullScreenY + (getY() + 1)) % fullScreenY);
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
    this->canon.draw();
}

void Tank::erase() {
    restoreErasedPoints();
    printToScreen(x, y, emptyChar);
    this->canon.erase();
}

void Tank::setCanonLocation() {
    switch (this->canonDirection) {
    case Up:
        if (pBoard->isWall(pBoard->getChar(newXPosition, newYPosition - 1))) {
			setnewXPosition(x);
			setnewYPosition(y);
        }	
        else {
            canon.setXValue(this->newXPosition);
            canon.setYValue((this->newYPosition) - 1);
        }
        break;
    case UpRight:
        if (pBoard->isWall(pBoard->getChar(newXPosition + 1, newYPosition - 1))) {
            setnewXPosition(x);
            setnewYPosition(y);
        }
        else {
            canon.setXValue((this->newXPosition) + 1);
            canon.setYValue((this->newYPosition) - 1);
        }
        break;
    case Right:
        if (pBoard->isWall(pBoard->getChar(newXPosition + 1, newYPosition))) {
            setnewXPosition(x);
            setnewYPosition(y);
        }
        else {
            canon.setXValue((this->newXPosition) + 1);
            canon.setYValue((this->newYPosition));
        }
        break;
    case DownRight:
        if (pBoard->isWall(pBoard->getChar(newXPosition + 1, newYPosition + 1))) {
            setnewXPosition(x);
            setnewYPosition(y);
        }
        else {
            canon.setXValue((this->newXPosition) + 1);
            canon.setYValue((this->newYPosition) + 1);
        }
        break;
    case Down:
		if (pBoard->isWall(pBoard->getChar(newXPosition, newYPosition + 1))) {
			setnewXPosition(x);
			setnewYPosition(y);
		}
        else {
            canon.setXValue(this->newXPosition);
            canon.setYValue((this->newYPosition) + 1);
        }
        break;
    case DownLeft:
		if (pBoard->isWall(pBoard->getChar(newXPosition - 1, newYPosition + 1))) {
			setnewXPosition(x);
			setnewYPosition(y);
		}
		else {
			canon.setXValue((this->newXPosition) - 1);
			canon.setYValue((this->newYPosition) + 1);
		}
        break;
    case Left:
		if (pBoard->isWall(pBoard->getChar(newXPosition - 1, newYPosition))) {
			setnewXPosition(x);
			setnewYPosition(y);
		}
        else {
            canon.setXValue((this->newXPosition) - 1);
            canon.setYValue((this->newYPosition));
        }
        break;
    case UpLeft:
		if (pBoard->isWall(pBoard->getChar(newXPosition - 1, newYPosition - 1))) {
			setnewXPosition(x);
			setnewYPosition(y);
		}
        else {
            canon.setXValue((this->newXPosition) - 1);
            canon.setYValue((this->newYPosition) - 1);
        }
        break;
    }
}



