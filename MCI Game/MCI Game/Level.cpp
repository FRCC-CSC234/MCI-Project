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

	Paddle paddle( 350, 560 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );
	
	Ball ball(350, 350); // Moving Creation of Ball to Constructor
	ball.setSpeedX(1.0 / 3.0);
	ball.setSpeedY(-2.0 / 3.0);
	ball.setMovable( false );
	addBall(ball);
	
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

	//#SimonM commented out levelnumber using rand for now
	//pictureID = levelNumber;
	pictureID = (rand() % 2);

	Paddle paddle( 350, 560 ); // Moving Paddle Creation to Constructor 
	paddles.push_back( paddle );
	
	Ball ball(paddle.getX(), (paddle.getY()-20)); // Moving Creation of Ball to Constructor
	ball.setSpeedX(1.0 / 3.0);
	ball.setSpeedY(-2.0 / 3.0);
	ball.setMovable( false );
	addBall(ball);
	

	bonusBall = false;
	bonusPaddle = false;
	superBall = false;
	stickyBall = 0; 

	createBricks();
}

/***********************************************************
#
Name: startCircularLevel
Description:
**********************************************************/
void Level::startCircularLevel()
{
	//startMusic(2);
	//balls.clear();
	//paddles.clear();
	//bricks.clear();
	//pictureID = levelNumber;
	//Ball ball(250, 250); // Moving Creation of Ball to Constructor
	//ball.setSpeedX(1.0 / 3.0);
	//ball.setSpeedY(-2.0 / 3.0);
	//ball.setMovable( false );
	//addBall(ball);
	//
	//Paddle paddle( 350, 560, true, 0 ); // Moving Paddle Creation to Constructor 
	//paddles.push_back( paddle );

	//createCircleBricks();
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

	// Brick Constructor =Brick::Brick(double x, double y, int rotateVal, bool verFlip, bool horFlip, double topR, double bottomR, 
    //                                   double leftAngle, double rightAngle) : GameObject(0, 22, 95, x, y, 0) 

	/**************************
	      Creating Row 1
	**************************/
	Brick brick1( 300, 27, 0, false, false, 273, 250, 270, 292.5); //0
	Brick brick2( 397, 49, 0, false, false, 273, 250, 292.5, 315); //1
	Brick brick3( 468, 119, 270, true, false, 273, 250, 315, 337.5 ); //1 vertical flip, rotate 90 //USES ORIGINAL TL CORNER
	Brick brick4( 501, 227, 90, false, true, 273, 250, 337.5, 360 ); //0 vertical flip, rotate 90
	Brick brick5( 501, 330, 90, false, false, 273, 250, 0, 22.5 ); //0 flip brick4 vertical //only rotate 90?
	Brick brick6( 468, 407, 90, false, false, 273, 250, 22.5, 45 ); //1 flip brick3 vertical //only rotate 90?
	Brick brick7( 397, 478, 0, true, false, 273, 250, 45, 67.5 ); //1 flip brick2 vertical //only rotate 90?
	Brick brick8( 300, 531, 0, true, false, 273, 250, 67.5 , 90 ); //0 flip brick1 vertical //only rotate 90?
	Brick brick9( 197, 531, 0, true, true, 273, 250, 90, 112.5 ); //0 flip brick8 horizontal
	Brick brick10( 109, 478, 0, true, true, 273, 250, 112.5, 135 ); //1 flip brick7 horizontal
	Brick brick11( 38, 406, 270, false, true, 273, 250, 135, 157.5 ); //1 flip brick6 horizontal
	Brick brick12( -5, 330, 270, false, true, 273, 250, 157.5, 180 ); //0 repeat 5, flip horizontal
	Brick brick13( -5, 227, 90, true, true, 273, 250, 180, 202.5 ); //0 repeat 4, flip horizontal
	Brick brick14( 39, 119, 90, true, true, 273, 250, 202.5, 225  ); //1 repeat 3, flip horizontal
	Brick brick15( 109, 49, 0, false, true, 273, 250, 225, 247.5 ); //1 repeat 2, flip horizontal
	Brick brick16(197, 27, 0, false, true, 273, 250, 247.5, 270 ); //0 repeat 1, flip horizontal

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
			//b0.at( i ).setPictureID( random - 18 ); //setting powerup ID to match image
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
			int random = rand() % 10 + 32;
			b1.at( i ).setPictureID( random ); // Set a picture ID to brick using files 33-42
			//b1.at( i ).setPowerupID( random - 32 ); //setting powerup ID to match image
			numOfRow1PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand() % 4 + 28;  // Generating color, using image files 29-32 (same colors, different brick type)
			b1.at( i ).setPictureID( random ); // Set a picture ID to brick 
			b1.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick(b1.at(i));
	}

	/**************************
	      Creating Row 2
	**************************/
	Brick brick17( 300, 51, 0, false, false, 249, 227, 270, 292.5) ; //0
	Brick brick18( 388, 71, 0, false, false, 249, 227 , 292.5, 315 ); //1
	Brick brick19( 452, 135, 270, true, false, 249, 227 , 315, 337.5 ); //1 vertical flip, rotate 90 //USES ORIGINAL TL CORNER
	Brick brick20( 483, 233, 90, false, true, 249, 227 , 337.5, 360 ); //0 vertical flip, rotate 90
	Brick brick21( 483, 327, 90, false, false, 249, 227, 0, 22.5 ); //0 flip brick4 vertical //only rotate 90?
	Brick brick22( 452, 398, 90, false, false, 249, 227, 22.5, 45 ); //1 flip brick3 vertical //only rotate 90?
	Brick brick23( 388, 462, 0, true, false, 249, 227, 45, 67.5 ); //1 flip brick2 vertical //only rotate 90?
	Brick brick24( 300, 510, 0, true, false, 249, 227, 67.5 , 90  ); //0 flip brick1 vertical //only rotate 90?
	Brick brick25( 206, 510, 0, true, true, 249, 227, 90, 112.5 ); //0 flip brick8 horizontal
	Brick brick26( 125, 462, 0, true, true, 249, 227, 112.5, 135 ); //1 flip brick7 horizontal
	Brick brick27( 61, 398, 270, false, true, 249, 227, 135, 157.5 ); //1 flip brick6 horizontal
	Brick brick28( 22, 327, 270, false, true, 249, 227, 157.5, 180 ); //0 repeat 5, flip horizontal
	Brick brick29( 22, 233, 90, true, true, 249, 227, 180, 202.5 ); //0 repeat 4, flip horizontal
	Brick brick30( 61, 135, 90, true, true, 249, 227, 202.5, 225 ); //1 repeat 3, flip horizontal
	Brick brick31( 125, 71, 0, false, true, 249, 227, 225, 247.5 ); //1 repeat 2, flip horizontal
	Brick brick32( 206, 51, 0, false, true, 249, 227, 247.5, 270 ); //0 repeat 1, flip horizontal

	//Vector for type 0 bricks
	vector<Brick> b0r2;
	b0r2.push_back( brick17 );
	b0r2.push_back( brick20 );
	b0r2.push_back( brick21 );
	b0r2.push_back( brick24 );
	b0r2.push_back( brick25 );
	b0r2.push_back( brick28 );
	b0r2.push_back( brick29 );
	b0r2.push_back( brick32 );

	//Vector for type 1 bricks
	vector<Brick> b1r2;
	b1r2.push_back( brick18 );
	b1r2.push_back( brick19 );
	b1r2.push_back( brick22 );
	b1r2.push_back( brick23 );
	b1r2.push_back( brick26 );
	b1r2.push_back( brick27 );
	b1r2.push_back( brick30 );
	b1r2.push_back( brick31 );

	/*     BRICK TYPE 0     */
	//Loop to assign values to type 0 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow2PowerUp != 0 )
		{
			int random = rand( ) % 10 + 46;
			b0r2.at( i ).setPictureID( random ); // Set a picture ID to brick using files 46-55
			//b0r2.at( i ).setPowerupID( random - 46 ); //set powerup ID to match picture
			numOfRow2PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand( ) % 4 + 42;  // Generating color, using image files 42-45
			b0r2.at( i ).setPictureID( random ); // Set a picture ID to brick color
			b0r2.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick( b0r2.at( i ) );
	}

	/*     BRICK TYPE 1     */
	//Loop to assign values to type 1 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow2PowerUp != 0 )
		{
			int random = rand( ) % 10 + 60;
			b1r2.at( i ).setPictureID( random ); // Set a picture ID to brick using files 60-69
			//b1r2.at( i ).setPowerupID( random - 60 ); //set powerup ID to match picture
			numOfRow2PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand( ) % 4 + 56;  // Generating color, using image files 56-59 (same colors, different brick type)
			b1r2.at( i ).setPictureID( random ); // Set a picture ID to brick 
			b1r2.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick( b1r2.at( i ) );
	}

	
	/**************************
	     Creating Row 3
	**************************/
	Brick brick33( 300, 74, 0, false, false, 226, 204, 270, 292.5 ); //0
	Brick brick34( 379, 93, 0, false, false, 226, 204, 292.5, 315 ); //1
	Brick brick35( 437, 152, 270, true, false, 226, 204, 315, 337.5); //1 vertical flip, rotate 90 //USES ORIGINAL TL CORNER
	Brick brick36( 465, 239, 90, false, true, 226, 204, 337.5, 360 ); //0 vertical flip, rotate 90
	Brick brick37( 465, 324, 90, false, false, 226, 204, 0, 22.5 ); //0 flip brick4 vertical //only rotate 90?
	Brick brick38( 437, 388, 90, false, false, 226, 204, 22.5, 45 ); //1 flip brick3 vertical //only rotate 90?
	Brick brick39( 379, 446, 0, true, false, 226, 204, 45, 67.5 ); //1 flip brick2 vertical //only rotate 90?
	Brick brick40( 300, 489, 0, true, false, 226, 204, 67.5, 90 ); //0 flip brick1 vertical //only rotate 90?
	Brick brick41( 215, 489, 0, true, true, 226, 204, 90, 112.5 ); //0 flip brick8 horizontal
	Brick brick42( 142, 446, 0, true, true, 226, 204, 112.5, 135 ); //1 flip brick7 horizontal
	Brick brick43( 84, 388, 270, false, true, 226, 204, 135, 157.5 ); //1 flip brick6 horizontal
	Brick brick44( 49, 324, 270, false, true, 226, 204, 157.5, 180 ); //0 repeat 5, flip horizontal
	Brick brick45( 49, 239, 90, true, true, 226, 204, 180, 202.5 ); //0 repeat 4, flip horizontal
	Brick brick46( 84, 152, 90, true, true, 226, 204, 202.5, 225 ); //1 repeat 3, flip horizontal
	Brick brick47( 142, 93, 0, false, true, 226, 204, 225, 247.5 ); //1 repeat 2, flip horizontal
	Brick brick48( 215, 74, 0, false, true, 226, 204, 247.5, 270  ); //0 repeat 1, flip horizontal

	//Vector for type 0 bricks
	vector<Brick> b0r3;
	b0r3.push_back( brick33 );
	b0r3.push_back( brick36 );
	b0r3.push_back( brick37 );
	b0r3.push_back( brick40 );
	b0r3.push_back( brick41 );
	b0r3.push_back( brick44 );
	b0r3.push_back( brick45 );
	b0r3.push_back( brick48 );

	//Vector for type 1 bricks
	vector<Brick> b1r3;
	b1r3.push_back( brick34 );
	b1r3.push_back( brick35 );
	b1r3.push_back( brick38 );
	b1r3.push_back( brick39 );
	b1r3.push_back( brick42 );
	b1r3.push_back( brick43 );
	b1r3.push_back( brick46 );
	b1r3.push_back( brick47 );

	/*     BRICK TYPE 0     */
	//Loop to assign values to type 0 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow3PowerUp != 0 )
		{
			int random = rand( ) % 10 + 74;
			b0r3.at( i ).setPictureID( random ); // Set a picture ID to brick using files 74-83
			//b0r3.at( i ).setPictureID( random - 74); //set powerup ID to match image
			numOfRow3PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand( ) % 4 + 70;  // Generating color, using image files 70-73
			b0r3.at( i ).setPictureID( random ); // Set a picture ID to brick color
			b0r3.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick( b0r3.at( i ) );
	}

	/*     BRICK TYPE 1     */
	//Loop to assign values to type 1 brick
	for ( int i = 0; i < 8; i++ )
	{
		int randomPercent = rand( ) % 100 + 1;

		//if brick is powerup brick, randomly choose powerup
		if ( randomPercent >= 90 && numOfRow3PowerUp != 0 )
		{
			int random = rand( ) % 10 + 88;
			b1r3.at( i ).setPictureID( random ); // Set a picture ID to brick using files 89-98
			//b1r3.at( i ).setPowerupID( random - 88 ); //set powerup ID to match image
			numOfRow3PowerUp--;
		}
		//otherwise just randomly choose a color 
		else
		{
			int random = rand( ) % 4 + 84;  // Generating color, using image files 85-88 (same colors, different brick type)
			b1r3.at( i ).setPictureID( random ); // Set a picture ID to brick 
			b1r3.at( i ).setPowerupID( -1 ); // No power up 
		}
		addBrick( b1r3.at( i ) );
	}
}

/***********************************************************
#NickP, #NickB
Name: createBricks
Description: randomly fills the bricks array with bricks
includes their art and power ups if applicable. Ensures only
2 max bricks contain powerups.
**********************************************************/
//void Level::createBricks( )
//{
//	startMusic(levelNumber);
//
//	int levelcount = levelNumber;
//	int numberOfBricksInLevel;
//	int numberOfPowerUpInLevel;
//
//	if ( levelcount == 0 )
//	{
//		numberOfBricksInLevel = 10;
//		numberOfPowerUpInLevel = 3;
//	}
//	else if (levelcount == 1)
//	{
//		numberOfBricksInLevel = 20;
//		numberOfPowerUpInLevel = 4;
//	}
//	else
//	{
//		numberOfBricksInLevel = 30;
//		numberOfPowerUpInLevel = 6;
//	}
//
//	srand( time( NULL ) ); // Truely Random 
//	int	powerupBrickCount = 0; // How many powerup
//	for ( int brickCount = 0; brickCount < numberOfBricksInLevel; brickCount++ ) // Total Number of Brick
//	{
//
//		Brick brick( (brickCount % 10) * 60 + 30, (brickCount / 10) * 30 + 15 ); // Create a brick Object 
//
//		//random number for brick type
//		int randomPercent = rand( ) % 100 + 1;
//
//		// are we generating a power up brick
//		if (randomPercent >= 70 && powerupBrickCount != numberOfPowerUpInLevel)
//		{
//			int random = rand() % 10 + 4;  // Generating 4-13
//			brick.setPictureID(random); // Set a picture ID to brick
//			brick.setPowerupID((random - 4)); // Set a power id of brick from 0-9
//			addBrick(brick);
//			powerupBrickCount++;
//		}
//
//		//normal brick
//		else
//		{
//		int random = rand( ) % 4;  // Generating 0-4
//		brick.setPictureID( random ); // Set a picture ID to brick
//		brick.setPowerupID( -1 ); // No power up
//		addBrick( brick );
//		}
//	}
//}

/***********************************************************
#NickP, #NickB
Name: createBricks2
Description: randomly fills the bricks array with bricks
includes their art and power ups if applicable. Ensures only
2 max bricks contain powerups.
**********************************************************/
void Level::createBricks()
{
	startMusic(levelNumber);

	int levelCount = levelNumber;
	int numberOfBricksInLevel; // Total # of Brick in level
	int numberOfPowerUpInLevel; // Total # of power up in level
	int powerUpCheck[10] = { 0 }; // Array to check if no duplicate powerups
	int random; // Random number generator
	srand(time(NULL)); // Truely Random 

	//Based on Level sets # of Bricks in level and # of power up in level 

	if (levelCount == 0)
	{
		numberOfBricksInLevel = 10;
		numberOfPowerUpInLevel = 5;
	}
	if (levelCount == 1)
	{
		numberOfBricksInLevel = 10;
		numberOfPowerUpInLevel = 7;
	}
	if (levelCount == 2)
	{
		numberOfBricksInLevel = 10;
		numberOfPowerUpInLevel = 10;
	}

	// Generate basic bricks based on level 
	for (int brickCount = 0; brickCount < numberOfBricksInLevel; brickCount++)
	{
		random = rand() % 4;
		Brick brick((brickCount % 10) * 60 + 30, (brickCount / 10) * 30 + 15);
		brick.setPictureID(random);
		brick.setPowerupID(-1);
		addBrick(brick);
	}
	int howManyRow = numberOfBricksInLevel / 10;

	for (int powerUpCount = 0; powerUpCount < numberOfPowerUpInLevel; powerUpCount++)
	{

		//"Randomly" choose a power up

		int powerUpID = rand() % 10 + 4;  // Generating 4-13

		if (powerUpCheck[(powerUpID - 4)] == 0)  // If there no same power up, use that power up
		{
			powerUpCheck[(powerUpID - 4)]++;
		}
		else
		{
			while (powerUpCheck[(powerUpID - 4)] != 0) // if Power ID is matching, keep generating till you find one
			{
				powerUpID = rand() % 10 + 4;  // Generating 4-13
			}
			powerUpCheck[(powerUpID - 4)]++;
		}

		int rowMin; // Row Starts at....
		int rowMax;	// Row Ends at....

		// Are we adding a powerup to a row we haven't added a power up to

		if (powerUpCount <= howManyRow)
		{
			if (powerUpCount == 0)
			{
				rowMin = 0;
				rowMax = powerUpCount + 9;
			}
			else
			{
				rowMax = (powerUpCount * 10) - 1;
				rowMin = rowMax - 10;
			}

			random = rand() % (rowMax - rowMin + 1) + rowMin;

			//Add that specific powerup to Row 

			bricks.at(random).setPictureID(powerUpID);
			bricks.at(random).setPowerupID((powerUpID - 4));
		}

		// Are we adding a powerup to a row we have already added a power up to

		if (powerUpCount > howManyRow)
		{
			int chooseARow = rand() % howManyRow; // Choose a row 

			if (chooseARow == 0)
			{
				rowMin = 0;
				rowMax = powerUpCount + 9;
			}
			else
			{
				rowMax = (chooseARow * 10) - 1;
				rowMin = rowMax - 10;
			}

			random = rand() % (rowMax - rowMin + 1) + rowMin;

			if (bricks.at(random).getPowerupID() == -1)  // No power up at indext assign power up
			{
				bricks.at(random).setPictureID(powerUpID);
				bricks.at(random).setPowerupID((powerUpID - 4));
			}
			else
			{
				while (bricks.at(random).getPowerupID() != -1) // if Power ID is matching, keep generating till you find one
				{
					random = rand() % (rowMax - rowMin + 1) + rowMin;
				}
				bricks.at(random).setPictureID(powerUpID);
				bricks.at(random).setPowerupID((powerUpID - 4));
			}
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
			balls.at( howManyBalls ).move( paddles.at( 0 ) );
		}

		if ( bricks.size( ) != 0 ) // Make sure there bricks available
		{
			//#SimonM uncomment this when we get back to the circular level
			/*if (levelNumber==2)
			{
				checkCollisionCircular( );
			}
			else
			{*/
				checkFlatCollision( );
			//}
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
		/*if (levelNumber==2)
		{
			shouldTheBallBeHereCircular( );
		}
		else
		{*/
			shouldTheBallBeHereFlat( );
		//}
}

/***********************************************************
#NickP, #NickB, TrelJ
Name: checkCollision
Description:
**********************************************************/
void Level::checkFlatCollision()
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
			if ( ballYLocation >= 591 ) // if the ball hits the bottom  
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

					Ball ball( 350, 350 );
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
			if (ballXLocation >= 591 || ballXLocation <= 9)
			{
				playSound(0);
				balls.at(howManyBalls).setSpeedX(ballXSpeed * -1);
				if (ballXLocation >= 591)
				{
					balls.at(howManyBalls).setX(590);
				}
				else
				{
					balls.at(howManyBalls).setX(10);
				}
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

			//if ball should samsh through without reflecting
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

			//paddle collision checks
			for ( int howManyPaddles = 0; howManyPaddles < paddles.size( ); howManyPaddles++ )
			{
				// Center the Paddle
				bool paddleCollision = false; 
				int paddleXLocation = paddles.at( howManyPaddles ).getX( );
				int paddleYLocation = paddles.at( howManyPaddles ).getY( );

				double paddlesWidth = (paddles.at( howManyPaddles ).getWidth( )) / 2; // Cender to Edge X
				double paddlesHeight = (paddles.at( howManyPaddles ).getHeight( )) / 2; // Center to Edge Y
				int top, bottom, left, right;
				top = paddleYLocation - paddlesHeight; // Paddle Top
				bottom = paddleYLocation + paddlesHeight; // Paddle Bottom
				left = paddleXLocation - paddlesWidth; // Left of Paddle 
				right = paddleXLocation + paddlesWidth; // Right of Paddle

				// Are you between the left and right edges  
				// Are you between the top and bottom edges  
				// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Paddle ( See Above ) 
				if ( ballXLocation >= left && ballXLocation <= right )
				{
					if ( abs( ballYLocation - top ) < 9 ) // Is the ball on top of the paddle 
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );

						if (ballXLocation < paddleXLocation)
						{
							if (ballXLocation >= 591 || ballXLocation <= 9)
							{
							balls.at(howManyBalls).setSpeedX(-1);
							}
							else
							{
								balls.at(howManyBalls).setSpeedX((paddleXLocation - ballXLocation) * -.02);
							}
						}
						else
						{
							if (ballXLocation >= 591 || ballXLocation <= 9)
							{
								balls.at(howManyBalls).setSpeedX(-1);
							}
							else
							{
								balls.at(howManyBalls).setSpeedX((ballXLocation - paddleXLocation) * .02);
							}
						}
						paddleCollision = true;
					}

					if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the paddle 
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
					balls.at(howManyBalls).setY(paddleYLocation-20);
					balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
					balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
					balls.at(howManyBalls).setMovable( false );
					
				}
			}
		}
	}
}

/***********************************************************

Name: checkCollisionCircular
Description:
**********************************************************/
void Level::checkCollisionCircular()
{
	if ( bricks.size( ) != 0 ) // If there is no bricks, do not check collision 
	{
		for ( int howManyBalls = 0; howManyBalls < balls.size( ); howManyBalls++ )
		{
			//distance of ball from center
			double xSection = (300 - balls.at( howManyBalls ).getX( )) * (300 - balls.at( howManyBalls ).getX( ));
			double ySection = (300 - balls.at( howManyBalls ).getY( )) * (300 - balls.at( howManyBalls ).getY( ));
			double distance = sqrt(xSection + ySection);

			// X and Y Location of the Ball 
			int ballXLocation = balls.at( howManyBalls ).getX( );
			int ballYLocation = balls.at( howManyBalls ).getY( );
			
			//angle of ball
			double angle = acos( (ballXLocation - 300) / distance );
			
			// X and Y speed of the Ball
			double ballXSpeed = balls.at( howManyBalls ).getSpeedX( );
			double ballYSpeed = balls.at( howManyBalls ).getSpeedY( );

			// Collision Checks - egg
			if ( distance <= 34 ) // if the ball hits the center/egg of the screen 
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

					Ball ball( 350, 350 );
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
					Paddle paddle( 350, 560, true );
					setPaddle( paddle );

					//set all powerups to false
					invincible = false;
					bonusBall = false;
					bonusPaddle = false;
					superBall = false;
				}
			}

			if (ballYLocation >= 600){
				playSound(0);
				balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
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
				double bricksXLocation = bricks.at( howManyBricks ).getX( );
				int bricksYLocation = bricks.at( howManyBricks ).getY( );

				int bricksWidth = (bricks.at( howManyBricks ).getWidth( )) / 2; // Center to Edge X
				int bricksHeight = (bricks.at( howManyBricks ).getHeight( )) / 2; // Center to Edge Y
				double top, bottom, left, right;
				top = bricks.at( howManyBricks ).getTopR( ); // Brick Top Radius
				bottom = bricks.at( howManyBricks ).getBottomR( ); // Brick Bottom Radius
				left = bricks.at( howManyBricks ).getLeftAngle( ); // Left of Brick Angle 
				right = bricks.at( howManyBricks ).getRightAngle( ); // Right of Brick Angle

				// Are you between the left and right edges  // X+bricksWidth // X-bricksWidth
				// Is the distance between the line and center 9  //Center of ball (X/Y Ball) & Edge of Brick ( See Above ) 
				if ( angle >= left && angle <= right )
				{
					if ( abs( distance - top ) < 9 ) // Is the ball on top of the brick 
					{
						//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						yCollide = true;

						//bricks.erase(bricks.begin() + howManyBricks);
						brickCollide = true;
					}

					if ( abs( distance - bottom ) < 9 ) // Is the ball on bottom of the brick 
					{
						//balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						yCollide = true;

						//bricks.erase(bricks.begin() + howManyBricks);
						brickCollide = true;
					}
				}

				// Are you between the top and bottom edges  // Y+bricksWidth // Y-bricksWidth
				if ( abs( distance <= bottom ) && distance >= top )
				{
					if ( abs( angle - left ) < 9 ) // Is the ball on top of the brick 
					{
						//balls.at( howManyBalls ).setSpeedX( ballXSpeed * -1 );
						xCollide = true;
						//checkPowerUps( howManyBricks );
						//bricks.erase( bricks.begin( ) + howManyBricks );
						brickCollide = true;
					}

					if ( abs( angle - right ) < 9 ) // Is the ball on bottom of the brick 
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
				//checkPowerUps( brickRemove.at( remove ) );
				//bricks.erase( bricks.begin( ) + brickRemove.at( remove ) );
			}

			//paddle collision
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
					if ( abs( distance - top ) < 9 ) // Is the ball on top of the brick 
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						paddleCollision = true;
					}

					if ( abs( distance - bottom ) < 9 ) // Is the ball on bottom of the brick 
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
						paddleCollision = true;
					}
				}

				if ( distance <= bottom && distance >= top )
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
					balls.at(howManyBalls).setY(paddleYLocation-20);
					balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
					balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
					balls.at(howManyBalls).setMovable( false );
				}
			}
		}
	}
}

/***********************************************************
#NickP, #NickB, TrelJ
Name: moveBall
Description:
**********************************************************/
void Level::moveBall( bool b ) 
{
	for ( int i = 0; i < balls.size( ); i++ )
	{
		if ( balls.at( i ).getMovable()==false && b == true )
		{
			stickyBall--;
		}
		balls.at( i ).setMovable( b );
	}
}

/***********************************************************
#NickP, #NickB, TrelJ
Name: shouldTheBallBeHere
Description: 
**********************************************************/
void Level::shouldTheBallBeHereFlat( )
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
			top = paddleYLocation - paddlesHeight; // paddle Top
			bottom = paddleYLocation + paddlesHeight; // paddle Bottom
			left = paddleXLocation - paddlesWidth; // Left of paddle 
			right = paddleXLocation + paddlesWidth; // Right of paddle

			// Is the ball in the paddle 
			// Is the distance between the line and center 9  
			//Center of ball (X/Y Ball) & Edge of paddle ( See Above ) 
			if ( ballXLocation >= left && ballXLocation <= right )
			{
				if ( abs( ballYLocation - top ) < 9 ) // Is the ball on top of the paddle 
				{
					// Is the ball going the right direction
					if ( ballYSpeed > 0 )
					{
						balls.at( howManyBalls ).setSpeedY( ballYSpeed * -1 );
					}

					ballInsidePaddle = true; 
					stuckTo=howManyPaddles;
				}

				if ( abs( ballYLocation - bottom ) < 9 ) // Is the ball on bottom of the paddle 
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
				balls.at(howManyBalls).setY(paddles.at(stuckTo).getY()-20);
				balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
				balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
				balls.at(howManyBalls).setMovable( false );
			}
			else
			{
				balls.at(howManyBalls).move(paddles.at(0));
			}
		}
	}
}

/***********************************************************
#
Name: shouldTheBallBeHereCircular
Description:
**********************************************************/
void Level::shouldTheBallBeHereCircular( )
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
				balls.at(howManyBalls).setY(paddles.at(stuckTo).getY()-20);
				balls.at(howManyBalls).setSpeedX( 1.0 / 3.0 );
				balls.at(howManyBalls).setSpeedY( -2.0 / 3.0 );
				balls.at(howManyBalls).setMovable( false );
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
			ball2.setY(paddles.at(0).getY()-20);
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
#PattiW, SimonM
Name: startMusic
Description: Plays different songs based on input integer
**********************************************************/
void Level::startMusic(int x)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music* mus;  // Background Music

	//ints rep different music tracks.
	// 0 = bounce, 1 = break, 2 = death, 3 = powerup
	switch (x)
	{
	case 0:
		mus = Mix_LoadMUS("MCIfunky.wav");
		Mix_PlayMusic(mus, -1);
		break;
	case 1:
		mus = Mix_LoadMUS("MCIgroovy.wav");
		Mix_PlayMusic(mus, -1);
		break;
	case 2:
		mus = Mix_LoadMUS("MCIsexy.wav");
		Mix_PlayMusic(mus, -1);
		break;
	}
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
	if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Chunk* sound;  // Background Music

	//ints rep sound effects.
	// 0 = bounce, 1 = break, 2 = death, 3 = powerup
	switch (x)
	{
	case 0:
		sound = Mix_LoadWAV("bloop1.wav");
		Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
		break;
	case 1:
		sound = Mix_LoadWAV("break.wav");
		Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
		break;
	case 2:
		sound = Mix_LoadWAV("death.wav");
		Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
		break;
	case 3:
	{
		int randSound = (rand() % 3 + 1);
		switch (randSound)
		{
		case 1:
			sound = Mix_LoadWAV("allright.wav");
			break;

		case 2:
			sound = Mix_LoadWAV("damn.wav");
			break;
		case 3:
			sound = Mix_LoadWAV("ohyeah.wav");
			break;
		default:
			sound = Mix_LoadWAV("powerup.wav");
			break;
		}
	}
	Mix_PlayChannel(-1, sound, 0); //Music loop: 0 for one play
	break;
	default:
		break;
	}
}