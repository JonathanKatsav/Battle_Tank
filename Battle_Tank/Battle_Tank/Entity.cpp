#include "Entity.h"

void Entity::move() {
    setXValue(newXPosition);
    setYValue(newYPosition);
}

void Entity::restoreErasedPoints() {
    if (pointErased == true && (erasedPositionX != x || erasedPositionY != y)) {
        printToScreen(erasedPositionX, erasedPositionY, pBoard->getOriginalChar(erasedPositionX, erasedPositionY),
            true);
        pointErased = false;
    }

    char charAtXY = pBoard->getOriginalChar(x, y);
    char charAbove = pBoard->getOriginalChar(x, y - 1);
    char charToRight = pBoard->getOriginalChar(x + 1, y);

    if (charAtXY != Board::empty) {
        erasedPositionX = x;
        erasedPositionY = y;
        pointErased = true;
    }
}

bool Entity::touchingWalls() {
    // check if the wall is on the right or left
    if (pBoard->isWall(pBoard->getChar(newXPosition, newYPosition))) {
        return true;
    }
    // check if the wall is up or down
    /*if (pBoard->isWall(pBoard->getChar(x, newYPosition))) {
        return true;
    }*/
}