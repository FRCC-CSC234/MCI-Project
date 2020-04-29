#include "Ball.h"
#include <random>
#include <time.h>
// Team: Logic
// Author: Simon Martin


//Child class of GameObject for Ball objects

/***********************************************************
#SimonM
Name: Ball
Description: Constructor
**********************************************************/
Ball::Ball( )
{
	GameObject( );
	// this needs width and height values to be set.

	/********************
	#nick Pallotti
	speeds are how fast and what
	direction the ball is moving
	********************/
	speedX = 0;
	speedY = 5;

}

/********************
	#nick Pallotti
	this method moves the ball,
********************/
void Ball::move() {
	srand(time(0));

	if (yLocation >= 500) { //if the ball hits the top of the screen
		speedY = (speedY * -1);
		int xmove = rand() % 2;
		if (xmove == 1) {
			speedX = 5;
		}
		else if (xmove == 2) {
			speedX = -5;
		}
	}
	else if (yLocation <= 0) { //if the ball hits the top of the screen
		speedY = (speedY * -1);
		int xmove = rand() % 2;
		if (xmove == 1) {
			speedX = 5;
		}
		else if (xmove == 2) {
			speedX = -5;
		}
	}
	else if (xLocation >= 700) { //if the ball hits the right side of the screen
		speedX = speedX * -1;
		int xmove = rand() % 2;
	
	
	}
	else if (xLocation <= 0) { //if the ball hits the left side of the screen
		speedX = speedX * -1;
		int xmove = rand() % 2;
		
	
	}

	setX(xLocation + speedX);
	setY(yLocation + speedY);

}