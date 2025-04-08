#include "ShellManager.h"

// Add a new shell to the vector
//TODO here
void ShellManager::add() {
    int temp = getStartingPositionLength();
    int asd = 1;
    int startingX = 0, startingY = 0;
    
    //TODO: add the starting X, Y and dir of a shell
    Shell newShell(pBoard, startingX, startingY);

    pushObj(newShell);
    int position = getSize() - 1;
}

void ShellManager::createAndDrawShells(ShellManager& shellManager) {
    shellManager.createObstacles();
    shellManager.draw();
}

void ShellManager::eraseAndMoveShells(ShellManager& shellManager) {
    shellManager.erase();
    shellManager.move();
}


bool ShellManager::checkCollisionWithPlayer(Tank& player) {
    return true;
}

void ShellManager::move() {
	
}