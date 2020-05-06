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
	playerLives = 4;
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
	stickyBall = 0; 

	createBricks();
}

/***********************************************************
#
Name: startFlatLevel
Description:
**********************************************************/
void Level::startFlatLevel()
{
	balls.clear();
	paddles.clear();
	bricks.clear();
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
	stickyBall = 0; 

	createBricks();
}

void Level::startCircularLevel()
{
	balls.clear();
	paddles.clear();
	bricks.clear();
	Ball ball(350, 550); // Moving Creation of Ball to Constructor
	ball.setSpeedX(1.0 / 3.0);
	ball.setSpeedY(-2.0 / 3.0);
	ball.setMovable( false );
	addBall(ball);
	
	Paddle paddle( 350, 560 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );

	createCircleBricks();

	//Ball ball();

	cout << "This don't EXIST" << endl;
}

/***********************************************************
#Kyle, #Sophia
Name: createCircleBricks
Description: Creates the bricks for the circle level
includes their art and power ups if applicable. Ensures only
4 max bricks contain powerups.
**********************************************************/
void Level::createCircleBricks( )
{
	int numberOfBricksinLevel;
	int BrickRowNumber;
	const int numberOfBricksInRow = 16;

	int numOfRow1PowerUp = 1;
	int numOfRow2PowerUp = 2;
	int numOfRow3PowerUp = 1;


	srand( time( NULL ) ); // Truely Random 
	int	powerupBrickCount = 0; // How many powerup

	// Brick Constructor = Brick::Brick(double x, double y, bool rotate90, bool verFlip, bool horFlip) : GameObject(pic, 30, 60, x, y, 0)


	/**************************
	      Creating Row 1
	**************************/
	Brick brick1( 300, 27, 0, false, false ); //0
	Brick brick2( 397, 49, 0, false, false ); //1
	Brick brick3( 478, 109, 270, true, false ); //1 vertical flip, rotate 90
	Brick brick4( 531, 197, 90, false, false ); //0 vertical flip, rotate 90
	Brick brick5( 531, 300, 90, false, false ); //0 flip brick4 vertical //only rotate 90?
	Brick brick6( 478, 397, 90, false, false ); //1 flip brick3 vertical //only rotate 90?
	Brick brick7( 397, 478, 90, false, false ); //1 flip brick2 vertical //only rotate 90?
	Brick brick8( 300, 531, 90, false, false ); //0 flip brick1 vertical //only rotate 90?
	Brick brick9( 197, 531, 90, false, true ); //0 flip brick8 horizontal
	Brick brick10( 109, 478, 90, false, true ); //1 flip brick7 horizontal
	Brick brick11( 49, 397, 90, false, true ); //1 flip brick6 horizontal
	Brick brick12( 27, 300, 90, false, true ); //0 repeat 5, flip horizontal
	Brick brick13( 27, 197, 90, true, true ); //0 repeat 4, flip horizontal
	Brick brick14( 49, 109, 90, true, true ); //1 repeat 3, flip horizontal
	Brick brick15( 109, 49, 0, false, true ); //1 repeat 2, flip horizontal
	Brick brick16(197, 27, 0, false, true); //0 repeat 1, flip horizontal

	//Vector for type 0 bricks
	vector<Brick> b0;
	b0.push_back( brick1 );
	b0.push_back( brick4 );
	b0.push_back( brick5 );
	b0.push_back( brick8 );
	b0.push_back( brick9 );
	b0.push_back( brick12 );
	b0.push_back( brick13 );
	b0.push_back( brick16 );

	//Vector for type 1 bricks
	vector<Brick> b1;
	b1.push_back( brick2 );
	b1.push_back( brick3 );
	b1.push_back( brick6 );
	b1.push_back( brick7 );
	b1.push_back( brick10 );
	b1.push_back( brick11 );
	b1.push_back( brick14 );
	b1.push_back( brick15 );

	/*     BRICK TYPE 0     */
	//Loop to assign values to type 0 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow1PowerUp != 0 )
		{
			int random = rand( ) % 10 + 18; 
			b0.at( i ).setPictureID( random ); // Set a picture ID to brick using files 19-28
			numOfRow1PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand( ) % 4 + 14;  // Generating color, using image files 15-18
			b0.at( i ).setPictureID( random ); // Set a picture ID to brick color
			b0.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick(b0.at(i));
	}

	/*     BRICK TYPE 1     */
	//Loop to assign values to type 1 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow1PowerUp != 0 )
		{
			int randomPowerUp = rand() % 10 + 32;
			int random = rand( );
			b1.at( i ).setPictureID( random ); // Set a picture ID to brick using files 33-42
			numOfRow1PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			//TO FIX: how do picIDs work? right now would generate same bricks as flat level
			int random = rand() % 4 + 28;  // Generating color, using image files 29-32 (same colors, different brick type)
			b1.at( i ).setPictureID( random ); // Set a picture ID to brick 
			b1.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick(b1.at(i));
	}
	//adding bricks to brick vector
	


/*addBrick(brick1);
	addBrick(brick2);
	addBrick(brick3);
	addBrick(brick4);
	addBrick(brick5);
	addBrick(brick6);
	addBrick(brick7);
	addBrick(brick8);
	addBrick(brick9);
	addBrick(brick10);
	addBrick(brick11);
	addBrick(brick12);
	addBrick(brick13);
	addBrick(brick14);
	addBrick(brick15);
	addBrick(brick16);
	*/
	/**************************
	      Creating Row 2
	**************************/




	/**************************
	     Creating Row 3
	**************************/
}

/***********************************************************
#NickP, #NickB
Name: createBricks
Description: randomly fills the bricks array with bricks
includes their art and power ups if applicable. Ensures only
2 max bricks contain powerups.
**********************************************************/
void Level::createBricks( )
{
	startMusic( );

	int levelcount = levelNumber;
	int numberOfBricksInLevel;
	int numberOfPowerUpInLevel;

	if ( levelcount == 0 )
	{
		numberOfBricksInLevel = 30;
		numberOfPowerUpInLevel = 4;
	}
	else
	{
		numberOfBricksInLevel = 50;
		numberOfPowerUpInLevel = 6;
	}

	srand( time( NULL ) ); // Truely Random 
	int	powerupBrickCount = 0; // How many powerup
	for ( int brickCount = 0; brickCount < numberOfBricksInLevel; brickCount++ ) // Total Number of Brick
	{

		Brick brick( (brickCount % 10) * 60 + 30, (brickCount / 10) * 30 + 15 ); // Create a brick Object 

		//random number for brick type
		int randomPercent = rand( ) % 100 + 1;

		// are we generating a power up brick
		if (randomPercent >= 90 && powerupBrickCount != numberOfPowerUpInLevel)
		{
			int random = rand() % 10 + 4;  // Generating 4-13
			brick.setPictureID(random); // Set a picture ID to brick
			brick.setPowerupID((random - 4)); // Set a power id of brick from 0 -9
			addBrick(brick);
			powerupBrickCount++;
		}
		//normal brick
		else
		{
		int random = rand( ) % 4;  // Generating 0-4
		brick.setPictureID( random ); // Set a picture ID to brick
		brick.setPowerupID( -1 ); // No power up
		addBrick( brick );
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

	
		for ( int howManyBalls = 0; howManyBalls < balls.size( ); howManyBalls++ )
		{
			//balls.at( howManyBalls ).move( paddles.at( 0 ) );
		}

		if ( bricks.size( ) != 0 ) // Make sure there bricks available
		{
			checkCollision( );

		}

		// Check to see if the paddles can move
		int paddlesWidth = (paddles.at( 0 ).getWidth( )) / 2; // Cender to Edge X
		int direction = Paddle::getDirection( );

		// Is the left paddle moving off the screen
		if ( paddles.at( 0 ).getX( ) - paddlesWidth < 0 && direction == -1 )
		{
			canPaddleMove = false;
		}

		if ( paddles.at( paddles.size( ) - 1 ).getX( ) + paddlesWidth > 600 && direction == 1 )
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
	if ( bricks.size( ) != 0 ) // If there is no bricks, do not check collision 
	{
		for ( int howManyBalls = 0; howManyBalls < balls.size( ); howManyBalls++ )
		{
			// X and Y Location of the Ball 
			int ballXLocation = balls.at( howManyBalls ).getX( );
			int ballYLocation = balls.at( howManyBalls ).getY( );

			// X and Y speed of the Ball
			double ballXSpeed = balls.at( howManyBalls ).getSpeedX( );
			double ballYSpeed = balls.at( howManyBalls ).getSpeedY( );

			// Collision Checks - bottom of screen
			if ( ballYLocation >= 591 ) // if the ball hits the bottom of the screen 
			{
				//if you have a second ball, just erase it
				if ( bonusBall )
				{
					balls.erase( balls.begin( ) + howManyBalls );
					bonusBall = false;
				}
				//if you have invincibility, the ball will bounce off the bottom one time
				else if ( invincible )
				{
					playSound(0);
					balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					invincible = false;
				}
				//if no power ups, you just dead.
				else
				{
					////reduce player lives
					playSound(2);
					drawLivesScreen( playerLives );
					playerLives--;
					cout << "Lives: " << playerLives << endl;

					
					//reset ball and paddle to middle of screen
					balls.erase( balls.begin( ) + howManyBalls );

					Ball ball( 350, 550 );
					ball.setSpeedX( 1.0 / 3.0 );
					ball.setSpeedY( -2.0 / 3.0 );
					ball.setMovable( false );
					addBall( ball );

					//erase all paddles
					for ( int i = 0; i <= paddles.size( ); i++ )
					{
						paddles.erase( paddles.begin( ) );
					}

					//generate new paddle
					Paddle paddle( 350, 560 );
					setPaddle( paddle );

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
				playSound(0);
				balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
				superBall = false;
			}

			// if ball hits the left or right side of the screen
			if ( ballXLocation >= 591 || ballXLocation <= 9 )
			{
				playSound(0);
				balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
			}

			vector<int> brickRemove;
			brickRemove.clear( );
			bool xCollide = false;
			bool yCollide = false;
			bool brickCollide = false;

			//brick collision checks
			for ( int howManyBricks = 0; howManyBricks < bricks.size( ); howManyBricks++ )
			{
				// Center the Brick
				brickCollide = false;
				int bricksXLocation = bricks.at( howManyBricks ).getX( );
				int bricksYLocation = bricks.at( howManyBricks ).getY( );

				int bricksWidth = (bricks.at( howManyBricks ).getWidth( )) / 2; // Cender to Edge X
				int bricksHeight = (bricks.at( howManyBricks ).getHeight( )) / 2; // Center to Edge Y
				int top, bottom, left, right;
				top = bricksYLocation - bricksHeight; // Brick Top
				bottom = bricksYLocation + bricksHeight; // Brick Bottom
				left = bricksXLocation - bricksWidth; // Left of Brick 
				right = bricksXLocation + bricksWidth; // Right of Brick

				// Are you between the left and right edges  // X+bricksWidth // X-bricksWidth
				// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 
				if ( ballXLocation >= left && ballXLocation <= right )
				{
					if ( abs( ballYLocation - top ) < 9 ) // Is the ball on top of the brick 
					{
						//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						yCollide = true;

						//bricks.erase(bricks.begin() + howManyBricks);
						brickCollide = true;
					}

					if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the brick 
					{
						//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						yCollide = true;

						//bricks.erase(bricks.begin() + howManyBricks);
						brickCollide = true;
					}
				}

				// Are you between the top and bottom edges  // Y+bricksWidth // Y-bricksWidth
				if ( abs( ballYLocation <= bottom ) && ballYLocation >= top )
				{
					if ( abs( ballXLocation - left ) < 9 ) // Is the ball on top of the brick 
					{
						//balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
						xCollide = true;
						//checkPowerUps( howManyBricks );
						//bricks.erase( bricks.begin( ) + howManyBricks );
						brickCollide = true;
					}

					if ( abs( ballXLocation - right ) < 9 ) // Is the ball on bottom of the brick 
					{
						//balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
						xCollide = true;
						//checkPowerUps( howManyBricks );
						//bricks.erase(bricks.begin() + howManyBricks);
						brickCollide = true;
					}
				}

				if ( brickCollide )
				{
					brickRemove.push_back( howManyBricks );
				}
			}

			if ( xCollide && !superBall )
			{
				balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
			}

			if ( yCollide && !superBall )
			{
				balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
			}

			for ( int remove = brickRemove.size( ) - 1; remove >= 0; remove-- )
			{
				checkPowerUps( brickRemove.at( remove ) );
				bricks.erase( bricks.begin( ) + brickRemove.at( remove ) );
			}

			for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
			{
				// Center the Paddle
				bool paddleCollision = false; 
				int paddleXLocation = paddles.at( howManyPaddles ).getX( );
				int paddleYLocation = paddles.at( howManyPaddles ).getY( );

				double paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
				double paddlesHeight = (paddles.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y
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
					if ( abs( ballYLocation - top ) < 9 ) // Is the ball on top of the brick 
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						paddleCollision = true;
					}

					if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the brick 
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						paddleCollision = true;
					}

				}

				if ( ballYLocation <= bottom && ballYLocation >= top )
				{
					if ( abs( ballXLocation - left ) < 9 ) // Is the ball on top of the brick 
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
						paddleCollision = true;
					}

					if ( abs( ballXLocation - right < 9 ) ) // Is the ball on bottom of the brick 
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
						paddleCollision = true;
					}
				}
				if (paddleCollision && stickyBall > 0)
				{
					balls.at(howManyBalls).setX(paddleXLocation);
					balls.at(howManyBalls).setY(paddleYLocation-10);
					balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
					balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
					balls.at(howManyBalls).setMovable( false );
					stickyBall--;
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
		int stuckTo = -1; 
		for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
		{
			int paddleXLocation = paddles.at( howManyPaddles ).getX( );
			int paddleYLocation = paddles.at( howManyPaddles ).getY( );
			int paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
			int paddlesHeight = (paddles.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y

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
					stuckTo=howManyPaddles;
				}

				if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the brick 
				{
					// Is the ball going the right direction

					if ( ballYSpeed < 0 )
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					}

					ballInsidePaddle = true;
					stuckTo=howManyPaddles;
				}
			}

			if ( ballYLocation <= bottom && ballYLocation >= top )
			{
				if ( abs( ballYLocation - left ) < 9 ) // Is the ball on top of the brick 
				{
					// Is the ball going the right direction
					if ( ballXSpeed > 0 )
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					}

					ballInsidePaddle = true;
					stuckTo=howManyPaddles;
				}

				if ( abs( ballYLocation - right < 9 ) ) // Is the ball on bottom of the brick 
				{
					// Is the ball going the right direction?
					if ( ballXSpeed < 0 )
					{
						balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
					}

					ballInsidePaddle = true;
					stuckTo=howManyPaddles;
				}
			}
		}
		
		// If ball inside paddle move it
		if ( ballInsidePaddle == true )
		{
			if (stickyBall>0)
			{
				balls.at(howManyBalls).setX(paddles.at(stuckTo).getX());
				balls.at(howManyBalls).setY(paddles.at(stuckTo).getY()-10);
				balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
				balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
				balls.at(howManyBalls).setMovable( false );
				stickyBall--;
			}
			else
			{
				balls.at(howManyBalls).move(paddles.at(0));
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
	//handles activating powerups
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
			//#SimonM add a life to player
			playerLives++;
			cout << "Bonus life! Lives now: " << playerLives << endl;
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
			cout << "sticky ball" << endl;

			stickyBall = 3; // Adjust number of times the power up to be used if needed 
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

	//random number to show which fact
	int powerupPic = bricks.at( brickLocation ).getPowerupID() * 2 + (rand( )%2);
	
	bool pause = true;
	SDL_Event e;

	//handles drawing the powerup screen and exiting with key press
	if (bricks.at(brickLocation).getPowerupID() != -1)
	{
		playSound(3);
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
	else
	{
		playSound(1);
	}
}

/***********************************************************
#PattiW
Name: startMusic
Description: Plays music
**********************************************************/
void Level::startMusic()
{
	//if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);

	//Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	//Mix_Music* mus;  // Background Music

	//mus = Mix_LoadMUS("MCIsong2.wav");

	//Mix_PlayMusic(mus, -1); //Music loop: -1 for continuous play
}

/***********************************************************
#SimonM
Name: playSound
Description: Plays sound effect
**********************************************************/
void Level::playSound(int x)
{
	//if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);

	//Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	//Mix_Chunk* sound;  // Background Music

	////ints rep sound effects.
	//// 0 = bounce, 1 = break, 2 = death, 3 = powerup
	//switch (x)
	//{
	//case 0:
	//	sound = Mix_LoadWAV("bloop1.wav");
	//	Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
	//	break;
	//case 1:
	//	sound = Mix_LoadWAV("break.wav");
	//	Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
	//	break;
	//case 2:
	//	sound = Mix_LoadWAV("death.wav");
	//	Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
	//	break;
	//case 3:
	//{
	//	int randSound = (rand() % 3 + 1);
	//	switch (randSound)
	//	{
	//	case 1:
	//		sound = Mix_LoadWAV("allright.wav");
	//		break;

	//	case 2:
	//		sound = Mix_LoadWAV("damn.wav");
	//		break;
	//	case 3:
	//		sound = Mix_LoadWAV("ohyeah.wav");
	//		break;
	//	default:
	//		sound = Mix_LoadWAV("powerup.wav");
	//		break;
	//	}
	//}
	//	Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
	//	break;
	//default:
	//	break;
	//}
}