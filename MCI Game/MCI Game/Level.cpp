#include "Level.h"

//Written by Nick Pallotti, edited by Simon Martin

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

int playerLives = 4;

Level::Level() {

	

	Ball ball(400, 380);
	addBall(ball);

	Paddle paddle(350, 500);
	setPaddle(paddle);

	ball.setSpeedY(-2);
	
	createBricks();
	//currently  have a defualt array for testing, this should be changed eventualy
	//for (int i = 0; i < 30; i++) {
	//	Brick brick;
	//	brick.setX((i % 10) * 72);
	//	brick.setY((i / 10) * 29);
	//	if (brick.getX() == 0 && brick.getY() == 0)
	//	{
	//		brick.setPowerupID(0);
	//	}
	//	if (i == 5)
	//	{
	//		brick.setPowerupID(5);
	//	}
	//	if (i == 25)
	//	{
	//		brick.setPowerupID(9);
	//	}

	//	addBrick(brick);
	//}

	//level.setPictureID(0);
}

Level::Level(int x) {

	Ball ball(400, 380); // Moving Creation of Ball to Constructor
	bonusBall = false;
	addBall(ball);

	
	Paddle paddle( 350, 400 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );

	bonusPaddle = false;

	levelNumber = x;

	ball.setSpeedY(-2);

	//currently  have a defualt array for testing, this should be changed eventualy
	for (int i = 0; i < 30; i++) {
		Brick brick(((i % 10) * 60)+30, ((i / 10) * 29 + 15) ); // Moved brick making to constructor 
		addBrick(brick);
	}
}

//#NickB creates bricks and assigns images at random
void Level::createBricks() 
{
	int	powerupBrickCount = 0;
	for (int i = 0; i < 30; i++)
	{

		Brick brick((i % 10) * 60+30,(i / 10) * 29+15);

		int randomPercent = rand() % 100 + 1;
		if (randomPercent >= 90 && powerupBrickCount != 2) // are we generating a power up brick
		{
			int random = rand() % 8 + 4;  // Generating 4-13
			brick.setPictureID(random); // Set a picture ID to brick
			brick.setPowerupID((random - 4)); // Set a power id of brick from 0 -9
			addBrick(brick);
			powerupBrickCount++;
		}
		else
		{
			int random = rand() % 4;  // Generating 0-4
			brick.setPictureID(random); // Set a picture ID to brick
			brick.setPowerupID(-1); // No power up
			addBrick(brick);
		}
	}

}

//#nick pallotti
//this method moves the ball and also checks for collision with the paddle
/*
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
					checkPowerUps(player, j);
					bricks.erase(bricks.begin() + j);
					//#SimonM if the array of bricks is empty, move on to next level
					if (bricks.size() == 0)
					{
						return 1;
					}
					else
					{
					int newSpeed = balls.at(i).getSpeedY() * -1;
					(balls.at(i)).setSpeedY(newSpeed);
					}		
				}
			}
		}
		for (int k = 0; k < paddles.size(); k++)
		{
			//#SimonM added an if for double paddle since this will have to be another method with another paddle Xlocation sent
			if (paddles.size() > 1)
			{
				if (balls.at(i).move2(paddles.at(0).getX(), paddles.at(1).getX(), paddles.at(k).getWidth(), bricks) == -1)
				{
					//#SimonMcheck if there's a second ball, in which case do not reduce lives, just delete extra ball
					if (bonusBall == true)
					{
						bonusBall = false;
						balls.erase(balls.begin() + i);
						return 0;
					}
					else if (invincible == true)
					{
						balls.at(i).setSpeedY(balls.at(i).getSpeedY() * -1);
						invincible = false;
					}
					else
					{
						//#SimonM reduce players life count by one, prints the player's lives for testing
						player.takeLives(1);
						cout << player.getLives();
						//#SimonM remove extra paddle if true
						bonusPaddle = false;

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

						//#SimonM reset all paddles to middle
						for (int k = 0; k < paddles.size(); k++)
						{
							//#SimonM checks if there are multiple paddles, if so deletes any extras
							if (paddles.size() > 1)
							{
								paddles.erase(paddles.begin() + (k + 1));
							}
							paddles.at(k).setX(350 + (200 * k));
							paddles.at(k).setY(400);
							paddles.at(k).setWidth(100);
						}

						balls.at(i).setX(400);
						balls.at(i).setY(380);
						balls.at(i).setSpeedY(-2);

						//#SimonM set ball to immovable so that it waits for the space key to start moving again
						balls.at(i).setMoveable(false);
					}
				}
			}
			//if there aren't 2 paddles, just send Xlocation of original.
			else
			{
				//#SimonM if move returns -1, means the ball is dead, resets to paddle waits for space to launch
				if (balls.at(i).move(paddles.at(k).getX(), paddles.at(k).getWidth(), bricks) == -1)
				{
					//if player has a second ball in play, delete extra ball. no lives lost.
					if (bonusBall == true)
					{
						bonusBall = false;
						balls.erase(balls.begin() + i);
						return 0;
					}
					//#SimonM if player has invincibility, just bounce the ball back up and set invincibility back to false.
					else if (invincible == true)
					{
						balls.at(i).setSpeedY(balls.at(i).getSpeedY() * -1);
						invincible = false;
					}
					else
					{
						//#SimonM reduce players life count by one, prints the player's lives for testing
						player.takeLives(1);
						cout << player.getLives();
						bonusPaddle = false;

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

						//#SimonM reset all paddles to middle
						for (int k = 0; k < paddles.size(); k++)
						{
							//#SimonM checks if there are multiple paddles, if so deletes any extras
							if (paddles.size() > 1)
							{
								paddles.erase(paddles.begin() + (k + 1));
							}
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
*/

void Level::gameFrame()
{
	for (int i=0; i<balls.size(); i++)
	{
		balls.at( i ).move( );
		checkCollision( );
	}
}


int Level::checkCollision()
{
	for (int howManyBalls = 0; howManyBalls < balls.size(); howManyBalls++)
	{

		// X and Y Location of the Ball 
		int ballXLocation = balls.at( howManyBalls ).getX( );
		int ballYLocation = balls.at(howManyBalls).getY();
		// X and Y speed of the Ball
		double ballXSpeed = balls.at( howManyBalls ).getSpeedX( );
		double ballYSpeed = balls.at( howManyBalls ).getSpeedY( );
		
		// Collision Checks 

		if ( ballYLocation >= 591 ) // if the ball hits the bottom of the screen 
		{
			balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
			return -1; // Return -1, ****Need something to handle the -1
		}
		
		if ( ballYLocation <= 9 ) // if ball hits the top of the screen
		{
			balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
		}
		if ( ballXLocation>=591 || ballXLocation<=9 ) // if ball hits the left or right side of the screen
		{
			balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 ); 
		}

		for ( int howManyBricks = 0; howManyBricks < bricks.size( ); howManyBricks++ )
		{
			// Center the Brick
			int bricksXLocation = bricks.at( howManyBricks ).getX( );  
			int bricksYLocation = bricks.at( howManyBricks ).getY( ); 

			int bricksWidth = (bricks.at( howManyBricks ).getWidth())/2; // Cender to Edge X
			int bricksHeight = (bricks.at( howManyBricks ).getHeight())/2; // Center to Edge Y
			int top, bottom, left, right;
			top = bricksYLocation - bricksHeight; // Brick Top
			bottom= bricksYLocation + bricksHeight; // Brick Bottom
			left = bricksXLocation - bricksWidth; // Left of Brick 
			right = bricksXLocation + bricksWidth; // Right of Brick
			
			// Are you between the left and right edges  // X+bricksWidth // X-bricksWidth
			// Are you between the top and bottom edges  // Y+bricksWidth // Y-bricksWidth
			// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 
			
			if ( ballXLocation >= left && ballXLocation <= right )
			{
				if ( abs (ballYLocation - top) < 9 ) // Is the ball on top of the brick 
				{
					balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					bricks.erase(bricks.begin() + howManyBricks);
				}

				if ( abs (ballYLocation - bottom) < 9 ) // Is the ball on bottom of the brick 
				{
					balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					bricks.erase(bricks.begin() + howManyBricks);
				}

			}
			
			if ( abs(ballYLocation >= bottom) && ballYLocation <= top )
			{
				if ( abs(ballYLocation - left) < 9 ) // Is the ball on top of the brick 
				{
					balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					checkPowerUps( howManyBricks );
					bricks.erase( bricks.begin( ) + howManyBricks );
				}

				if ( abs(ballYLocation - right) < 9 ) // Is the ball on bottom of the brick 
				{
					balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					bricks.erase(bricks.begin() + howManyBricks);
				}

			}

			


		}

		for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
		{
			// Center the Brick
			int paddleXLocation = paddles.at( howManyPaddles ).getX( );
			int paddleYLocation = paddles.at( howManyPaddles ).getY( );

			int paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
			int paddlesHeight = (bricks.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y
			int top, bottom, left, right;
			top = paddleYLocation - paddlesHeight; // Brick Top
			bottom = paddleYLocation + paddlesHeight; // Brick Bottom
			left = paddleXLocation - paddlesWidth; // Left of Brick 
			right = paddleXLocation + paddlesWidth; // Right of Brick

			// Are you between the left and right edges  // X+bricksWidth // X-bricksWidth
			// Are you between the top and bottom edges  // Y+bricksWidth // Y-bricksWidth
			// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 

			if ( ballXLocation >= left && ballXLocation <= right )
			{
				if ( abs(ballYLocation - top) < 9 ) // Is the ball on top of the brick 
				{
					balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
				}

				if ( abs (ballYLocation - bottom) < 9 ) // Is the ball on bottom of the brick 
				{
					balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
				}

			}

			if ( ballYLocation >= bottom && ballYLocation <= top )
			{
				if ( abs(ballYLocation - left) < 9 ) // Is the ball on top of the brick 
				{
					balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
				}

				if ( abs(ballYLocation - right < 9) ) // Is the ball on bottom of the brick 
				{
					balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
				}

			}

		}
		
	}


}



/******************************************************************
# Nathan McIntrye
Name: checkPowerUps
description: Checks if there is a powerup at the current brick.
If there is a power up then applies what ever effect is appropriate
last updated: 4/29/2020
Updated by Simon Martin. Added code for several other power ups.
******************************************************************/
void Level::checkPowerUps(int brickLocation)
{
	if (bricks.at(brickLocation).getPowerupID() > -1)
	{
		if (bricks.at(brickLocation).getPowerupID() == 9) // add a ball
		{
			cout << "bonus ball" << endl;
			Ball ball2(bricks.at(brickLocation).getX(), bricks.at(brickLocation).getY());
			ball2.setMoveable(true);
			bonusBall = true;
			ball2.setX(paddles.at(0).getX());
			ball2.setY(paddles.at(0).getY());
			ball2.setSpeedY(2);
			addBall(ball2);
		}
		if (bricks.at(brickLocation).getPowerupID() == 6)// slows the ball down
		{
			cout << "slow ball" << endl;
			//set speed for all balls to half of their current speed
			for (int i = 0; i < balls.size(); i++)
			{
				balls.at(i).setSpeedY(balls.at(i).getSpeedY() / 2);
			}

		}
		if (bricks.at(brickLocation).getPowerupID() == 8) // one time shield
		{
			cout << "invincibility" << endl;
			//#SimonM added a boolean for this power up, should make ball bounce off bottom border once.
			invincible = true;
		}
		if (bricks.at(brickLocation).getPowerupID() == 2) // changes the size of the paddle
		{
			cout << "big paddle" << endl;
			for (int i = 0; i < paddles.size(); i++)
			{
				paddles.at(i).setWidth(150);
			}
		}
		if (bricks.at(brickLocation).getPowerupID() == 1) // paddle shrinks
		{
			cout << "small paddle" << endl;
			for (int i = 0; i < paddles.size(); i++)
			{
				paddles.at(i).setWidth(75);
			}
		}
		if (bricks.at(brickLocation).getPowerupID() == 5) // add a paddle
		{
			cout << "bonus paddle" << endl;
			if (bonusPaddle == false)
			{
				Paddle paddle2( paddles.at( 0 ).getX( ) - 150, 400 );
				setPaddle(paddle2);
				bonusPaddle = true;
			}
		}
		if (bricks.at(brickLocation).getPowerupID() == 7) // ball sticks to paddle
		{
			cout << "sticky paddle" << endl;
			//#SimonM used the moveable boolean to adjust this power up. Needs testing.
				balls.at(0).setMoveable(false);
				balls.at(0).setX(400);
				balls.at(0).setY(380);
				balls.at(0).setSpeedY(2);
		}
		if (bricks.at(brickLocation).getPowerupID() == 0)// ball speeds up
		{
			cout << "fast ball" << endl;
			//#SimonM set speed for all balls to half of their current speed
			for (int i = 0; i < balls.size(); i++)
			{
				balls.at(i).setSpeedY(balls.at(i).getSpeedY()*1.5);
			}
		}
		if (bricks.at(brickLocation).getPowerupID() == 3)// extra life
		{
			cout << "Bonus life! Lives now: " << playerLives << endl;
			//#SimonM add a life to player
			playerLives++;
		}
		if (bricks.at(brickLocation).getPowerupID() == 4) //ball breaks through multipal bricks
		{
			cout << "power ball" << endl;
		}
	}
	
}
