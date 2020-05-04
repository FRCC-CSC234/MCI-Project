#pragma once
#include "GameObject.h"
#include "Brick.h"
#include "Paddle.h"
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

	//#SimonM sets the ability of the ball to be moved on the y-axis
	bool movable;

public:
	//Constructor
	Ball(double x, double y );

	int move(Paddle p);
	double getAngle();

	//getters/setters
	void setSpeedX(double x) {speedX = x;}
	void setSpeedY(double y) { speedY = y; }
	void setDirection(double newDirection) { this->direction = newDirection; }
	void setMovable(bool move) { this->movable = move; }

	bool getMovable() { return movable; }
	double getSpeedX() { return speedX; }
	double getSpeedY() { return speedY; }
	double getDirection() { return direction; }
};

