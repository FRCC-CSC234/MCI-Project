#include "Level.h"

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

Level::Level() {

	Ball ball;
	ball.setX(400);
	ball.setY(100);
	addBall(ball);

	//Paddle paddle;
	paddle.setX(350);
	paddle.setY(400);

	int powerupBrickCount = 0;

	//currently  have a defualt array for testing, this should be changed eventualy
	for ( int i = 0; i < 30; i++ )
	{
		 
		Brick brick;
		brick.setX( (i % 10) * 72 );
		brick.setY( (i / 10) * 29 );

		int randomPercent = rand( ) % 100 + 1;
		if ( randomPercent >= 90 && powerupBrickCount != 2) // are we generating a power up brick
		{
			int random = rand( ) %8 + 4;  // Generating 4-13
			brick.setPictureID( random ); // Set a picture ID to brick
			brick.setPowerupID( random ); // Set a power id of brick
			addBrick( brick );
			powerupBrickCount++;
		}
		else
		{
			int random = rand( ) % 4 ;  // Generating 0-4
			brick.setPictureID( random ); // Set a picture ID to brick
			brick.setPowerupID( -1 ); // No power up
			addBrick( brick );
		}
	
		
	}

	//level.setPictureID(0);
}

Level::Level(int x) {

	Ball ball;
	ball.setX(400);
	ball.setY(100);
	addBall(ball);

	//Paddle paddle;
	paddle.setX(350);
	paddle.setY(400);

	levelNumber = x;

	ball.setSpeedY(4 + x);

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
void Level::moveObjects(int direction) {

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
					//if there is an collision erase the block and send the ball back
					bricks.erase(bricks.begin() + j);
					int newSpeed = balls.at(i).getSpeedY() * -1;
					(balls.at(i)).setSpeedY(newSpeed);
				}
	
			}
			
		}

		balls.at(i).move(paddle.getX());

	}

	//move the paddle in the apporpriate direction
	if (direction == 1) {
		paddle.setX(paddle.getX() + 8);
	}

	if (direction == -1) {
		paddle.setX(paddle.getX() - 8);
	}
}
