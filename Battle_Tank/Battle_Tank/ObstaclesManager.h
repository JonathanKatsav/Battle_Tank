#pragma once

#include "utils.h"
#include "Tank.h"

template <typename T>

class ObstaclesManager
{
    int maxObj = 0;
    std::vector<T> obstacles;

    // Remove all obstacles from the vector
    void removeObstacles() { obstacles.clear(); }

public:
    int getMaxObj() { return maxObj; }
    int getSize() { return obstacles.size(); }
    T* getObstacle(int location) { return &obstacles[location]; }
    void setMaxSize(int size) { maxObj = size; }
    void erase();
    void draw();
    virtual void pushObj(T obj) { obstacles.push_back(obj); }
    void createObstacles();
    virtual bool checkCollisionWithPlayer(Tank& player);
    void removeAllObstacles() { removeObstacles(); }
    // Remove a Obstacle from the vector
    void removeObstacle(int index);
    int getSize() const { return obstacles.size(); }
    // Function that are goingto be fulfilled by the inherited classes
    virtual void add() = 0;
    virtual void move() = 0;

};

//The following function are not in a cpp file because of the use of <typename T>

//TODO here
template <typename T>
bool ObstaclesManager<T>::checkCollisionWithPlayer(Tank& player) {
    int playerX = player.getX();
    int playerY = player.getY();
    //TODO: check this in Tank
    //Entity::Direction dir = player.getDirection(); // Assuming player has a method to get his current direction

    for (size_t i = 0; i < obstacles.size(); ) {
        int obstacleX = obstacles[i].getX();
        int obstacleY = obstacles[i].getY();

        // if player and the obstacle meet at the same position 
        if ((obstacleX - playerX) == 0 && (obstacleY - playerY) == 0) {
            return true;
        }

        //if no continue or return statement is executed ++i is called to move to the next obstacle
        ++i;
    }
    return false;
}

template <typename T>
void ObstaclesManager<T>::removeObstacle(int index) {
    if (index >= 0 && index < obstacles.size()) {
        obstacles.erase(obstacles.begin() + index);
    }
}

template <typename T>
void ObstaclesManager<T>::createObstacles() {
        add();
}

template <typename T>
void ObstaclesManager<T>::erase() {
    for (auto& obstacle : obstacles)
        obstacle.erase();
}

template <typename T>
void ObstaclesManager<T>::draw() {
    for (auto& obstacle : obstacles)
        obstacle.draw();
}

