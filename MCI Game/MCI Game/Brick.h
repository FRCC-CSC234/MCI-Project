#pragma once
#include "GameObject.h"

//#SimonM Object class for Brick objects

class Brick : public GameObject
{
private:
	//denotes the ID of the powerup in a given brick
	int powerupID;

public:
	//Constructor
	Brick(double x, double y, int pic=0; int powID=-1 );

	//getters/setters
	int getPowerupID( );
	void setPowerupID( int powerup );
};

