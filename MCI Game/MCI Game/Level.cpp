#include "Level.h"

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

Level::Level() {

	Ball ball;
	ball.setX(400);
	ball.setY(380);
	addBall(ball);

	Paddle paddle;
	paddle.setX(350);
	paddle.setY(400);
	paddle.setWidth(100);
	setPaddle(paddle);

	ball.setSpeedY(-2);
	
	//currently  have a defualt array for testing, this should be changed eventualy
	for (int i = 0; i < 10; i++) {
		Brick brick;
		brick.setX((i % 10) * 72);
		brick.setY((i / 10) * 29);
		if (brick.getX() == 0 && brick.getY() == 0)
		{
			brick.setPowerupID(0);
		}
		if (i == 5)
		{
			brick.setPowerupID(5);
		}
		if (i == 25)
		{
			brick.setPowerupID(9);
		}

		addBrick(brick);
	}

	//level.setPictureID(0);
}

Level::Level(int x) {

	Ball ball;
	bonus = false;
	ball.setX(400);
	ball.setY(380);
	addBall(ball);

	//Paddle paddle;
	paddles.at(0).setX(350);
	paddles.at(0).setY(400);
	paddles.at(0).setWidth(100);

	levelNumber = x;

	ball.setSpeedY(-2 + x);

	//currently  have a defualt array for testing, this should be changed eventualy
	for (int i = 0; i < 30; i++) {
		Brick brick;
		brick.setX((i % 10) * 72);
		brick.setY((i / 10) * 29);
		addBrick(brick);
	}

	//level.setPictureID(0);
}

//#nick pallotti
//this method moves the ball and also checks for collision with the paddle
int Level::moveObjects(int direction, Player &player) {

	//for each ball on the board move the ball
	for (int i = 0; i < balls.size(); i++) {
		
		//for loop checks for the balls collision with the bricks
		for (int j = 0; j < bricks.size(); j++) {

			//ball x/y are the balls x and y coordinates	
			int ballx = (balls.at(i)).getX() + 7;
			int bally = (balls.at(i)).getY();


			//the bounds/edges of the brick
			int xLeftBound = bricks.at(j).getX();
			int xRightBound = bricks.at(j).getX() + 72;

			int yBottomBound = bricks.at(j).getY();
			int yTopBound = bricks.at(j).getY() + 29;

			//if block checking that the ball intersects with the y and x coordinateds of the block
			if (bally >= yBottomBound && bally <= yTopBound) {
				if(ballx >= xLeftBound && ballx <= xRightBound) {
					//if there is an collision, check for powerup, erase the block and send the ball back
					checkPowerUps(j);
					bricks.erase(bricks.begin() + j);
					//#SimonM if the array of bricks is empty, move on to next level
					if (bricks.size() == 0)
					{
						return 1;
					}

					int newSpeed = balls.at(i).getSpeedY() * -1;
					(balls.at(i)).setSpeedY(newSpeed);
					
				}
	
			}
			
		}
		for (int k = 0; k < paddles.size(); k++)
		{
			//#SimonM if move returns -1, means the ball is dead, resets to paddle waits for space to launch
			if (balls.at(i).move(paddles.at(k).getX(), paddles.at(k).getWidth(), bricks) == -1)
			{
				if (bonus == true)
				{
					bonus = false;
					balls.at(i).setX(900);
					balls.at(i).setY(980);
					balls.at(i).setSpeedY(0);
				}
				else
				{
					//death
					player.takeLives(1);
					cout << player.getLives();

					//#SimonM if player is out of lives, end game.
					if (player.getLives() < 0)
					{
						cout << "Game over!" << endl;
						paddles.at(k).setX(350);
						paddles.at(k).setY(400);

						balls.at(i).setSpeedX(0);
						balls.at(i).setSpeedY(0);
						return -1;
					}

					//#SimonM reset ball and paddle to middle
					for (int k = 0; k < paddles.size(); k++)
					{
						paddles.at(k).setX(350 + (200 * k));
						paddles.at(k).setY(400);
					}

					balls.at(i).setX(400);
					balls.at(i).setY(380);
					balls.at(i).setSpeedY(-2);

					//#SimonM set ball to immovable so that it waits for the space key to start moving again
					balls.at(i).setMoveable(false);
				}
			}
		}
	}

	//move the paddle in the apporpriate direction
	if (direction == 1) 
	{
		for (int k = 0; k < paddles.size(); k++)
		{
			paddles.at(k).setX(paddles.at(k).getX() + (8/4));
		}
	}

	if (direction == -1) 
	{
		for (int k = 0; k < paddles.size(); k++)
		{
			paddles.at(k).setX(paddles.at(k).getX() - (8/4));
		}
	}

	return 0;
}

/******************************************************************
# Nathan McIntrye
Name: checkPowerUps
description: Checks if there is a powerup at the current brick.
If there is a power up then applies what ever effect is appropriate
last updated: 4/29/2020
******************************************************************/
void Level::checkPowerUps(int brickLocation)
{
	if (bricks.at(brickLocation).getPowerupID() > -1)
	{
		if (bricks.at(brickLocation).getPowerupID() == 0) // add a ball
		{
			Ball ball2;
			ball2.setMoveable(true);
			bonus = true;
			ball2.setX(paddles.at(0).getX());
			ball2.setY(paddles.at(0).getY());
			ball2.setSpeedY(2);
			addBall(ball2);
		}
		if (bricks.at(brickLocation).getPowerupID() == 1)// slows the ball down
		{


		}
		if (bricks.at(brickLocation).getPowerupID() == 2) // one time shield
		{

		}
		if (bricks.at(brickLocation).getPowerupID() == 3) // changes the size of the paddle
		{
			paddles.at(0).setWidth(150);
		}
		if (bricks.at(brickLocation).getPowerupID() == 4) // paddle shrinks
		{
			paddles.at(0).setWidth(50);
		}
		if (bricks.at(brickLocation).getPowerupID() == 5) // add a paddle
		{
			Paddle paddle2;
			paddle2.setX(paddles.at(0).getX() - 150);
			paddle2.setY(400);
			paddle2.setWidth(100);
			setPaddle(paddle2);
		}
		if (bricks.at(brickLocation).getPowerupID() == 6) // ball sticks to paddle
		{

		}
		if (bricks.at(brickLocation).getPowerupID() == 7)// ball speeds up
		{

		}
		if (bricks.at(brickLocation).getPowerupID() == 8)// extra life
		{

		}
		if (bricks.at(brickLocation).getPowerupID() == 9) //ball breaks through multipal bricks
		{

		}

	}


}