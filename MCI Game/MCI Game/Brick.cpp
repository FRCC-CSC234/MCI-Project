 #include "Brick.h"
// Team: Logic
// Author: Simon Martin


//Child class of GameObject for Brick objects

/***********************************************************
#SimonM
Name: Brick
Description: Constructor
**********************************************************/
Brick::Brick( double x, double y, int pic, int powID ):GameObject(pic, 30, 60, x, y, 0)
{
	powerupID = powID;
	// This needs width and height to be set. 
}

/***********************************************************
#Sophia, #Kyle
Name: Brick 
Description: Circular brick constructor, overloaded normal brick
**********************************************************/
Brick::Brick(double x, double y, int rotateVal, bool verFlip, bool horFlip, double topR, double bottomR, double leftAngle, double rightAngle) : GameObject(0, 22, 95, x, y, 0) 
{
	this->rotateVal = rotateVal;
	this->verFlip = verFlip;
	this->horFlip = horFlip;
	this->topR = topR;
	this->bottomR = bottomR;
	this->leftAngle = leftAngle;
	this->rightAngle = rightAngle;
}

/***********************************************************
#Sophia, #Kyle
Name: GetVerflip
Description: Get the boolean to say if the brick should be flipped vertically or not
**********************************************************/

bool Brick::getVerFlip()
{
	return verFlip;
}

/***********************************************************
#Sophia, #Kyle
Name: getHorFlip
Description: Get the boolean to say if the brick should be flipped horizontally 
**********************************************************/
bool Brick::getHorFlip()
{
	return horFlip;
}

/***********************************************************
#Sophia, #Kyle
Name: getRotate
Description: Get the boolean to say if the brick should be rotated 90 degrees
**********************************************************/

int Brick::getRotateVal()
{
	return rotateVal;
}

/***********************************************************
#SimonM
Name: getPowerupID
Description: getter, returns powerupID
**********************************************************/
int Brick::getPowerupID( )
{
	return powerupID;
}

/***********************************************************
#SimonM
Name: setPowerupID
Description: setter, takes int parameter and sets to powerupID
**********************************************************/
void Brick::setPowerupID( int powerup )
{
	this->powerupID = powerup;
}