#pragma once
#include "GameObject.h"

//#SimonM Object class for Brick objects

class Paddle : public GameObject
{
private:

	static int direction;

public:

	


	//Constructor
	Paddle(double x, double y );

	//moves paddle object
	void move( );

	//getters/setters
	static int getDirection( ) { return direction; }
	static void setDirection( int dir ) { direction = dir; };
	
};

