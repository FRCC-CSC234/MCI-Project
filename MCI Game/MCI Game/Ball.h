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
	int speedX;
	int speedY;
	bool movable;
public:
	//Constructor
	Ball( );

	int move(int paddleLocation, vector<Brick> bricks);
	void moveX();

	void setSpeedX(int x) {speedX = x;}
	void setSpeedY(int y) { speedY = y; }
	void setDirection(double newDirection);
	void setMovable(bool move);

	bool getMovable() { return movable; }
	int getSpeedX() { return speedX; }
	int getSpeedY() { return speedY; }
	double getDirection() { return direction; }
};

