#pragma once
#include "GameObject.h"

//#SimonM Object class for Brick objects

class Brick : public GameObject
{
private:
	//denotes the ID of the powerup in a given brick
	int powerupID;
	int rotateVal;
	bool verFlip;
	bool horFlip;
	double topR;
	double bottomR;
	double leftAngle;
	double rightAngle;

public:
	//Constructor
	Brick(double x, double y, int pic=0, int powID=-1 );
	Brick(double x, double y, int rotateVal, bool verFlip, bool horFlip, double topR, double bottomR, double leftAngle, double rightAngle );

	//getters/setters
	int getPowerupID( );
	void setPowerupID( int powerup );
	bool getVerFlip();
	bool getHorFlip();
	int getRotateVal();
	double getTopR( ) { return topR; }
	double getBottomR( ) { return bottomR; }
	double getLeftAngle( ) { return leftAngle; }
	double getRightAngle(  )  {  return rightAngle;  }

};

