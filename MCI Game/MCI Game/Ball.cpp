#include "Ball.h"
#include <random>
#include <time.h>
#include<cmath>
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
	else if (yLocation <= 0) { //if the ball hits the top of the screen
		speedY = (speedY * -1);
		moveX();
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
	//int xmoveAmount = rand() % 5;    //how fast the x direction speed changes
	//int xmoveDirection = rand() % 2;  //whether the speed changes in the left or right direction

	////if xMoveDirection == 1 speed up to the right
	//if (xmoveDirection == 1) {

	//	//this if block decides how much the speed changes
	//	if (xmoveAmount == 1) {
	//		speedX += 1;
	//	}
	//	else if (xmoveAmount == 2) {
	//		speedX += 2;
	//	}
	//	else if (xmoveAmount == 3) {
	//		speedX += 3;
	//	}
	//	else if (xmoveAmount == 4) {
	//		speedX += 4;
	//	}
	//	else {
	//		speedX += 5;
	//	}
	//	//makes sure the ball doesnt go to fast
	//	if (speedX > 5) {
	//		speedX = 5;
	//	}

	//}
	////if xMoveDirection != 1 speed up to the left
	//else {
	//	//this if block decides how much the speed changes
	//	if (xmoveAmount == 1) {
	//		speedX -= 1;
	//	}
	//	else if (xmoveAmount == 2) {
	//		speedX -= 2;
	//	}
	//	else if (xmoveAmount == 3) {
	//		speedX -= 3;
	//	}
	//	else if (xmoveAmount == 4) {
	//		speedX -= 4;
	//	}
	//	else {
	//		speedX -= 5;
	//	}
	//	//makes sure the ball doesnt move to fast
	//	if (speedX < -5) {
	//		speedX = -5;
	//	}
	//}
	srand(time(NULL));
	int moveX = rand() % 3;
	//int moveAmount = rand() % 3;
	
	if (moveX == 1) {
		speedX += 3;
		if (speedX > 6) {
			speedX = 6;
		}
	}
	else if (moveX == 2) {
		speedX -= 3;
		if (speedX < -6) {
			speedX = -6;
		}
	}
	else if (moveX == 3) {

	}
}
/***************************************
#nick pallotti

this method calculates the angle of the 
direction the ball is currently going in 
and returns the angle as an double. 

the speedX and speedY of the ball can be
thought of as two sides of an triangle,
where speedX is the adjacent side and speedY
is the oppoiste side of angle  the angle Z
we can use inverse tangent to find the angle,
i havent taken trig or calc in a long time so 
i'm fuzy on how they work, so im just taking 
the inverse tangent of the positive values, and
knowing that each quadrant is 90 degrees adding
the appropriate amount of degrees depending on
which quadrant the total speed is in. aTan
(the inverse tangent function in c++) returns
radians, in order to convert form degrees to radians 
you can mutiply the result by (180/pi).
***************************************/
double Ball::getAngle() {
	int sideX;
	int sideY;

	double angle;
	//bassicly if spedX is 0 atan blows up so this handles that case
	if (speedX == 0) {
		if (speedY < 0) {
			angle = 270;
		}
		else {
			angle = 90;
		}
	}
	else if (speedX < 0 && speedY < 0) { //if direction is in quadrant 3
		sideX = speedX * -1;
		sideY = speedY * -1;

		angle = atan(sideY / sideX) * (180/3.1415); //find the degree
		angle = angle + 180; //add 180 degrees since we are in quadrant 3
	}
	else if (speedX < 0) { //if direction is in quadrant 2
		sideX = speedX * -1;
		sideY = speedY;

		angle = atan(sideY / sideX) * (180 / 3.1415); //find the angle
		angle = angle + 90; //add 90 since we are in quadrant 2
	}
	else if (speedY < 0) { //if direction is in in quadrant 4
		sideX = speedX;
		sideY = speedY * -1;

		angle = atan(sideY / sideX) * (180 / 3.1415); //find the degree
		angle = angle + 270; //add 270 since we are in quadrant 4
	}
	else { //if direction is in quadrant 1
		sideX = speedX;
		sideY = speedY;

		angle = atan(sideY / sideX) * (180 / 3.1415); //no need to add  anything since we are in quadrant 1
	}

	//ball is irented at 90 degrees so this makes up for that 
	angle = angle + 90;
	return angle;
}