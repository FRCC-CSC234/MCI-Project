#include "Level.h"
#include <vector>

//Written by Nick Pallotti
//Edited by Simon Martin, Nick Brady, Trel Johnson, Kyle Dexter

bool Level::quit = false;

/***********************************************************
#NickP
Name: develop
Description: 
**********************************************************/
void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}



/***********************************************************
#NickP, #NickB, #TrelJ, #SimonM
Name: Level
Description: Default Constructor
**********************************************************/
Level::Level() 
{
	playerlives = 4;
	pictureID = 0;
}

/***********************************************************
#NickP, #NickB, #TrelJ, #SimonM
Name: Level
Description: Constructor
**********************************************************/
Level::Level(int x) 
{
	levelNumber = x;
	
	Ball ball(350, 550); // Moving Creation of Ball to Constructor
	ball.setSpeedX(1.0 / 3.0);
	ball.setSpeedY(-2.0 / 3.0);
	ball.setMovable( false );
	addBall(ball);
	
	Paddle paddle( 350, 560 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );

	//set all the powerup booleans to false
	bonusBall = false;
	bonusPaddle = false;
	superBall = false;

	createBricks();
}

void Level::startLevel()
{

	Ball ball(350, 550); // Moving Creation of Ball to Constructor
	ball.setSpeedX(1.0 / 3.0);
	ball.setSpeedY(-2.0 / 3.0);
	ball.setMovable( false );
	addBall(ball);
	
	Paddle paddle( 350, 560 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );

	bonusBall = false;
	bonusPaddle = false;
	superBall = false;

	createBricks();
}

/***********************************************************
#NickP, #NickB
Name: createBricks
Description: randomly fills the bricks array with bricks
includes their art and power ups if applicable. Ensures only
2 max bricks contain powerups.
**********************************************************/
void Level::createBricks() 
{
	srand(time(NULL));
	int	powerupBrickCount = 0;
	for (int i = 0; i < 30; i++)
	{
		//instantiate brick object
		Brick brick((i % 10) * 60+30,(i / 10) * 29+15);

		//random number for brick type
		// int randomPercent = rand() % 100 + 1;  
		int randomPercent = 1;

		// are we generating a power up brick
		if (randomPercent >= 90 && powerupBrickCount != 2) 
		{
			int random = rand() % 10 + 4;  // Generating 4-13
			brick.setPictureID(random); // Set a picture ID to brick
			brick.setPowerupID((random - 4)); // Set a power id of brick from 0 -9
			addBrick(brick);
			powerupBrickCount++;
		}
		// normal brick
		else
		{
			int random = rand() % 4;  // Generating 0-4
			brick.setPictureID(random); // Set a picture ID to brick
			brick.setPowerupID(5); // No power up
			addBrick(brick);
		}
	}

}

/***********************************************************
#NickP, #NickB, TrelJ
Name: gameFrame
Description: 
**********************************************************/
void Level::gameFrame()
{
	bool canPaddleMove = true; 
	for (int howManyBalls=0; howManyBalls <balls.size(); howManyBalls++)
	{
		balls.at( howManyBalls ).move(paddles.at(0));
	}

	checkCollision( );

	// Check to see if the paddles can move
	int paddlesWidth = (paddles.at( 0 ).getWidth( ))/2; // Cender to Edge X
	int direction = Paddle::getDirection( );
		
	// Is the left paddle moving off the screen
	if ( paddles.at( 0 ).getX( )- paddlesWidth < 0 && direction == -1 )
	{
		canPaddleMove = false; 
	}

	if ( paddles.at( paddles.size()-1 ).getX( ) + paddlesWidth > 600 && direction == 1 )
	{
		canPaddleMove = false;
	}

	if ( canPaddleMove == true )
	{
		for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
		{
			paddles.at( howManyPaddles ).move( );
		}
	}

	shouldTheBallBeHere( );
}

/***********************************************************
#NickP, #NickB, TrelJ
Name: checkCollision
Description: 
**********************************************************/
void Level::checkCollision()
{
	for (int howManyBalls = 0; howManyBalls < balls.size(); howManyBalls++)
	{
		// X and Y Location of the Ball 
		int ballXLocation = balls.at( howManyBalls ).getX( );
		int ballYLocation = balls.at(howManyBalls).getY();

		// X and Y speed of the Ball
		double ballXSpeed = balls.at( howManyBalls ).getSpeedX( );
		double ballYSpeed = balls.at( howManyBalls ).getSpeedY( );
		
		// Collision Checks - bottom of screen
		if ( ballYLocation >= 591 ) // if the ball hits the bottom of the screen 
		{
			//if you have a second ball, just erase it
			if (bonusBall)
			{
				balls.erase(balls.begin() + howManyBalls);
				bonusBall = false;
			}
			//if you have invincibility, the ball will bounce off the bottom one time
			else if (invincible)
			{
				balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
				invincible = false;
			}
			//if no power ups, you just dead.
			else
			{
				////reduce player lives
				drawLivesScreen( playerLives );
				playerLives--;
				cout << "Lives: " << playerLives << endl;

				/*int livesPic = 

				drawFlatScreen(bricks, balls, paddles, *this, );*/

				//reset ball and paddle to middle of screen
				balls.erase(balls.begin() + howManyBalls);

				Ball ball(350, 550); 
				ball.setSpeedX(1.0 / 3.0);
				ball.setSpeedY(-2.0 / 3.0);
				ball.setMovable(false);
				addBall(ball);
								
				//erase all paddles
				for (int i = 0; i <= paddles.size(); i++)
				{
					paddles.erase(paddles.begin());
				}

				//generate new paddle
				Paddle paddle(350, 560);
				setPaddle(paddle);

				//set all powerups to false
				invincible = false;
				bonusBall = false;
				bonusPaddle = false;
				superBall = false;
			}
		}
	
		// Collision Checks - top of screen
		if ( ballYLocation <= 9 ) // if ball hits the top of the screen
		{
			balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
			superBall = false;
		}

		// if ball hits the left or right side of the screen
		if ( ballXLocation>=591 || ballXLocation<=9 ) 
		{
			balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 ); 
		}

		vector<int> brickRemove;
		brickRemove.clear();
		bool xCollide = false;
		bool yCollide = false;
		bool brickCollide = false;

		for ( int howManyBricks = 0; howManyBricks < bricks.size( ); howManyBricks++ )
		{
			// Center the Brick
			brickCollide = false;
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
			// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 
			if ( ballXLocation >= left && ballXLocation <= right )
			{
				if ( abs (ballYLocation - top) < 9 ) // Is the ball on top of the brick 
				{
					//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					yCollide = true;
					
					//bricks.erase(bricks.begin() + howManyBricks);
					brickCollide = true;
				}

				if ( abs (ballYLocation - bottom) < 9 ) // Is the ball on bottom of the brick 
				{
					//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					yCollide = true;

					//bricks.erase(bricks.begin() + howManyBricks);
					brickCollide = true;
				}
			}
			
			// Are you between the top and bottom edges  // Y+bricksWidth // Y-bricksWidth
			if ( abs(ballYLocation >= bottom) && ballYLocation <= top )
			{
				if ( abs(ballYLocation - left) < 9 ) // Is the ball on top of the brick 
				{
					//balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					xCollide=true;
					//checkPowerUps( howManyBricks );
					//bricks.erase( bricks.begin( ) + howManyBricks );
					brickCollide=true;
				}

				if ( abs(ballYLocation - right) < 9 ) // Is the ball on bottom of the brick 
				{
					//balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					xCollide = true;
					//checkPowerUps( howManyBricks );
					//bricks.erase(bricks.begin() + howManyBricks);
					brickCollide = true;
				}
			}

			if (brickCollide)
			{
				brickRemove.push_back( howManyBricks );
			}
		}

		if ( xCollide && !superBall )
		{
		balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
		}

		if (yCollide && !superBall)
		{
		balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
		}

		for (int remove=brickRemove.size()-1; remove>=0; remove--)
		{
			checkPowerUps( brickRemove.at( remove ) );
			bricks.erase( bricks.begin( ) + brickRemove.at( remove ) );
		}

		for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
		{
			// Center the Brick
			int paddleXLocation = paddles.at( howManyPaddles ).getX( );
			int paddleYLocation = paddles.at( howManyPaddles ).getY( );

			double paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
			double paddlesHeight = (bricks.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y
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

/***********************************************************
#NickP, #NickB, TrelJ
Name: shouldTheBallBeHere
Description: 
**********************************************************/
void Level::shouldTheBallBeHere( )
{
	for ( int howManyBalls = 0; howManyBalls < balls.size( ); howManyBalls++ )
	{
		bool ballInsidePaddle = false; 
		int ballXLocation = balls.at( howManyBalls ).getX( );
		int ballYLocation = balls.at( howManyBalls ).getY( );
		double ballXSpeed = balls.at( howManyBalls ).getSpeedX( );
		double ballYSpeed = balls.at( howManyBalls ).getSpeedY( );

		for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
		{
			int paddleXLocation = paddles.at( howManyPaddles ).getX( );
			int paddleYLocation = paddles.at( howManyPaddles ).getY( );
			int paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
			int paddlesHeight = (bricks.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y

			int top, bottom, left, right;
			top = paddleYLocation - paddlesHeight; // Brick Top
			bottom = paddleYLocation + paddlesHeight; // Brick Bottom
			left = paddleXLocation - paddlesWidth; // Left of Brick 
			right = paddleXLocation + paddlesWidth; // Right of Brick

			// Is the ball in the paddle 
			// Is the distance between the line and center 9  
			//Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 
			if ( ballXLocation >= left && ballXLocation <= right )
			{
				if ( abs( ballYLocation - top ) < 9 ) // Is the ball on top of the brick 
				{
					// Is the ball going the right direction
					if ( ballYSpeed > 0 )
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					}

					ballInsidePaddle = true; 
				}

				if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the brick 
				{
					// Is the ball going the right direction

					if ( ballYSpeed < 0 )
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					}

					ballInsidePaddle = true;
				}
			}

			if ( ballYLocation >= bottom && ballYLocation <= top )
			{
				if ( abs( ballYLocation - left ) < 9 ) // Is the ball on top of the brick 
				{
					// Is the ball going the right direction
					if ( ballXSpeed > 0 )
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					}

					ballInsidePaddle = true;
				}

				if ( abs( ballYLocation - right < 9 ) ) // Is the ball on bottom of the brick 
				{
					// Is the ball going the right direction?
					if ( ballXSpeed < 0 )
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					}

					ballInsidePaddle = true;
				}
			}
		}
		
		// If ball inside paddle move it
		if ( ballInsidePaddle == true )
		{
			balls.at( howManyBalls ).move(paddles.at(0) );
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
		//fast ball
		if (bricks.at(brickLocation).getPowerupID() == 0)// ball speeds up
		{
			cout << "fast ball" << endl;
			//#SimonM set speed for all balls to half of their current speed
			for (int i = 0; i < balls.size(); i++)
			{
				balls.at(i).setSpeedY(balls.at(i).getSpeedY()*1.5);
			}
		}
		
		//small paddle
		if (bricks.at(brickLocation).getPowerupID() == 1) // paddle shrinks
		{
			cout << "small paddle" << endl;
			for (int i = 0; i < paddles.size(); i++)
			{
				paddles.at(i).setWidth(75);
			}
		}
		
		//big paddle
		if (bricks.at(brickLocation).getPowerupID() == 2) // changes the size of the paddle
		{
			cout << "big paddle" << endl;
			for (int i = 0; i < paddles.size(); i++)
			{
				paddles.at(i).setWidth(150);
			}
		}
		
		//extra life
		if (bricks.at(brickLocation).getPowerupID() == 3)// extra life
		{
			cout << "Bonus life! Lives now: " << playerLives << endl;
			//#SimonM add a life to player
			playerLives++;
		}
		
		//power ball
		if (bricks.at(brickLocation).getPowerupID() == 4) //ball breaks through multipal bricks
		{
			cout << "power ball" << endl;
			superBall = true;
		}
		
		//extra paddle
		if (bricks.at(brickLocation).getPowerupID() == 5) // add a paddle
		{
			cout << "bonus paddle" << endl;
			if (bonusPaddle == false)
			{
				Paddle paddle2( paddles.at( 0 ));
				paddle2.setX( paddle2.getX( ) + 200 );
				setPaddle(paddle2);
				bonusPaddle = true;
			}
		}
		
		//slow ball
		if (bricks.at(brickLocation).getPowerupID() == 6)// slows the ball down
		{
			cout << "slow ball" << endl;
			//set speed for all balls to half of their current speed
			for (int i = 0; i < balls.size(); i++)
			{
				balls.at(i).setSpeedY(balls.at(i).getSpeedY() / 2);
			}
		}
		
		//sticky paddle
		if (bricks.at(brickLocation).getPowerupID() == 7) // ball sticks to paddle
		{
			cout << "sticky paddle" << endl;
			//#SimonM used the movable boolean to adjust this power up. Needs testing.
			balls.erase(balls.begin() + 0);

			Paddle paddle(350, 560);

			Ball ball(paddles.at(0).getX(), (paddles.at(0).getY() - 10));
			ball.setSpeedX(1.0 / 3.0);
			ball.setSpeedY(-2.0 / 3.0);
			ball.setMovable(false);
			addBall(ball);
		}
		
		//extra ball
		if (bricks.at(brickLocation).getPowerupID() == 8) // add a ball
		{
			//#NathanM add a second ball
			cout << "bonus ball" << endl;
			Ball ball2(balls.at(0));
			ball2.setX(paddles.at(0).getX());
			ball2.setY(paddles.at(0).getY());
			ball2.setSpeedX(1.0 / 3.0);
			ball2.setSpeedY(-2.0 / 3.0);
			//ball2.setSpeedX( (ball2.getSpeedX( )) * -1 ); 
			ball2.setMovable(true);
			bonusBall = true;

			addBall(ball2);
		}

		//invincibility
		if (bricks.at(brickLocation).getPowerupID() == 9) // one time shield
		{
			cout << "invincibility" << endl;
			//#SimonM added a boolean for this power up, should make ball bounce off bottom border once.
			invincible = true;
		}
	}

	bool pause = true;
	int powerupPic = bricks.at( brickLocation ).getPowerupID() * 2 + (rand( )%2);
	SDL_Event e;
	if (bricks.at(brickLocation).getPowerupID() != -1)
	{
		while (!quit && pause)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYUP:
					if (e.key.keysym.sym == SDLK_SPACE)
					{
						if (bricks.at(brickLocation).getPowerupID() == 7)
							balls.at(0).setMovable(false);
						pause = false;
					}
					else
					{
						pause = false;
					}
				}
			}

			drawFlatScreen(bricks, balls, paddles, *this, powerupPic);
		}
	}


}
