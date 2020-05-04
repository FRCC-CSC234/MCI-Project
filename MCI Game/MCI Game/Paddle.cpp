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
Paddle::Paddle(double x, double y ):GameObject(0, 14, 100, x, y, 8)
{
}

/***********************************************************
#NickB
Name: move
Description: code to move the paddle in a given direction
**********************************************************/
void Paddle::move()
{
	xLocation += speed * direction/4;
}