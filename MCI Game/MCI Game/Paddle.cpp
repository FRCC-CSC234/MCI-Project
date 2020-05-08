#include "Paddle.h"
// Team: Logic
// Author: Simon Martin


//Child class of GameObject for Paddle objects

int Paddle::direction = 0;


/***********************************************************
#SimonM
Name: Paddle
Description: Constructor
**********************************************************/
Paddle::Paddle( double x, double y, bool isCircular, double angle ):GameObject( isCircular?1:0, 14, 100, x, y, 8 )
{
	this->isCircular=isCircular;
	this->angle = angle;
}

/***********************************************************
#NickB
Name: move
Description: code to move the paddle in a given direction
**********************************************************/
void Paddle::move()
{
	if (isCircular)
	{
		angle += speed * direction / 4;
		xLocation = 300 + (cos( angle * 3.1415926535897 / 180 )*50);
		yLocation = 300 + (sin( angle * 3.1415926535897 / 180 ) * 50);
	}
	else
	{
		xLocation += speed * direction / 4;
	}
}