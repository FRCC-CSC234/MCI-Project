#pragma once
#include "GameObject.h"

//#SimonM Object class for Brick objects

class Ball : public GameObject
{
private:
	// direction between 0 and 360
	double direction;
	int speedX;
	int speedY;

public:
	//Constructor
	Ball( );

	void move(int paddleLocation);
	void moveX();

	void setSpeedX(int x) {speedX = x;}
	void setSpeedY(int y) { speedY = y; }
	void setDirection(double newDirection) { direction = newDirection; }

	int getSpeedX() { return speedX; }
	int getSpeedY() { return speedY; }
	double getDirection() { return direction; }
};

