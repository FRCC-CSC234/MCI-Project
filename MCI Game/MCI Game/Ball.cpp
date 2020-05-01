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
void Ball::move(int paddleLocation) {
	srand(time(0));

	if (yLocation >= 500) { //if the ball hits the top of the screen
		speedY = (speedY * -1);
		moveX();
	}
	else if (yLocation <= 0) { //if the ball hits the bottom of the screen
		//speedY = (speedY * -1);
		//moveX();
	}
	else if (xLocation >= 720 || xLocation <= 0) { //if the ball hits the right or left side of the screen
		speedX = speedX * -1;
	}
	else if ((yLocation == 400)) {
		if ( xLocation >= paddleLocation && xLocation <= paddleLocation + 100) { //if the ball hits th paddle
		speedY = (speedY * -1);
			moveX();
		}
	}

	//set the balls new location
	setX(xLocation + speedX);
	setY(yLocation + speedY);

}

//#nick pallotti
//method for randomly changing the balls speed in the x direction
void Ball::moveX() {
	int xmoveAmount = rand() % 5;    //how fast the x direction speed changes
	int xmoveDirection = rand() % 2;  //whether the speed changes in the left or right direction

	//if xMoveDirection == 1 speed up to the right
	if (xmoveDirection == 1) {

		//this if block decides how much the speed changes
		if (xmoveAmount == 1) {
			speedX += 1;
		}
		else if (xmoveAmount == 2) {
			speedX += 2;
		}
		else if (xmoveAmount == 3) {
			speedX += 3;
		}
		else if (xmoveAmount == 4) {
			speedX += 4;
		}
		else {
			speedX += 5;
		}
		//makes sure the ball doesnt go to fast
		if (speedX > 5) {
			speedX = 5;
		}

	}
	//if xMoveDirection != 1 speed up to the left
	else {
		//this if block decides how much the speed changes
		if (xmoveAmount == 1) {
			speedX -= 1;
		}
		else if (xmoveAmount == 2) {
			speedX -= 2;
		}
		else if (xmoveAmount == 3) {
			speedX -= 3;
		}
		else if (xmoveAmount == 4) {
			speedX -= 4;
		}
		else {
			speedX -= 5;
		}
		//makes sure the ball doesnt move to fast
		if (speedX < -5) {
			speedX = -5;
		}
	}
}