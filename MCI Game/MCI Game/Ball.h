#pragma once
#include "GameObject.h"

//#SimonM Object class for Brick objects

class Ball : public GameObject
{
private:
	//*** needs direction value. in double form.

	int speedX;
	int speedY;
public:
	//Constructor
	Ball( );

	void move();

	void setSpeedX(int x) {speedX = x;}
	void setSpeedY(int y) { speedY = y; }

	int getSpeedX() { return speedX; }
	int getSpeedY() { return speedY; }

};

