#pragma once
#include "GameObject.h"
#include "Brick.h"
#include <vector>
#include <iostream>

//#SimonM Object class for Brick objects

class Ball : public GameObject
{
private:
	// direction between 0 and 360
	double direction;
	double speedX;
	double speedY;
	bool movable;

public:
	//Constructor
	Ball(double x, double y );

	int move();
	double getAngle();
	void setSpeedX(double x) {speedX = x;}
	void setSpeedY(double y) { speedY = y; }
	void setDirection(double newDirection) { this->direction = newDirection; }
	void setMoveable(bool move) { this->movable = move; }

	bool getMoveable() { return movable; }
	double getSpeedX() { return speedX; }
	double getSpeedY() { return speedY; }
	double getDirection() { return direction; }
};

