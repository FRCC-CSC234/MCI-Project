//Main Driver for MCI Game - version 1
//starts, plays and ends the game
//written by: Patty Wiens 4/18/20
//edited by:  Trel Johnson, Nick Brady 4/22, Simon Martin 4/29

// Implemented Driver.h to remove having to include more than 1 .h file
#include "Driver.h"

using namespace std;

void startGame();
void showIntroSceen( );
void endGame();
void playGame();
void nextLevel( );

Level level; //*** exists to make me not have to delete stuff from drawScreen();

int main( int argc, char** argv ) // Main must have these specific arguments for SDL to work 
{
	startGame( );
	showIntroSceen();
	playGame();
	endGame();
	system( "pause" );
	return 0;
}

/***********************************************************
#NickP
Name: startGame
Description: Starts the graphics methods
**********************************************************/
void startGame()
{
	Level::quit = false; // Added to have intro and instructions show on screen 
	TrelGraphics2::start( "SPERM SLAMMERS", 600, 600 ); //*** needed a TrelGraphics::start call, made up a size.

}

/***********************************************************
#
Name: nextLevel
Description: Progress the game to the next level 
**********************************************************/
void nextLevel()
{
	if(level.getLevelNumber() == 0)
	{
		level.startFlatLevel( );
	}
	if(level.getLevelNumber() == 1)
	{
		level.startFlatLevel( );
	}
	if(level.getLevelNumber() == 2)
	{
		level.startFlatLevel();
		//level.startCircularLevel();
	}
}

/***********************************************************
#NickP
Name: playGame
Description: Contains calls to SDL and other classes to run the game
**********************************************************/
void playGame()
{
	level.setLevelNumber(0); //*** Needs to be set back to 0 
	nextLevel();

	SDL_Event e;
	int direction = 0;
	int gameState = 0;
	while ( !Level::quit && level.getLevelNumber()<3&& level.getLives()>=0)
	{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					Level::quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					int paddleLocation = level.getPaddles().at(0).getX();
					switch (e.key.keysym.sym)
					{
					case SDLK_LEFT:
						direction = -1;
						Paddle::setDirection(-1);
						break;
					case SDLK_RIGHT:
						direction = 1;
						Paddle::setDirection(1);
						break;
					case SDLK_1:
						level.setPictureID(0);
						break;
					case SDLK_2:
						level.setPictureID(1);
						break;
					case SDLK_3:
						level.setPictureID(2);
						break;
					case SDLK_SPACE:
						if ( e.key.repeat == 0 )
						{
							level.moveBall( true );
						}
						break;
					}
				}
				else if (e.type == SDL_KEYUP)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_LEFT:
						direction = direction == 1 ? 1 : 0;
						Paddle::setDirection(Paddle::getDirection() == 1 ? 1 : 0);
						break;
					case SDLK_RIGHT:
						direction = direction == -1 ? -1 : 0;
						Paddle::setDirection(Paddle::getDirection() == -1 ? -1 : 0);
						break;
						//#SimonM set spacebar to change balls movable bool to true
					case SDLK_SPACE:
						level.moveBall(true);
						break;
					}
				}
			}
	
		//#SimonM the moveObjects method returns an int -1 for death, 0 for normal, 1 for moving to next level
		for ( int i = 0; i < 6 && gameState == 0; i++ )
		{
			level.gameFrame( );
		}

		// removed draw code. Draw Flat screen needs to be used to draw things to the screen 
		drawFlatScreen( level.getBricks( ), level.getBalls( ), level.getPaddles( ), level );

		if ( level.getBricks().size() ==  0 )
		{
			level.setLevelNumber((level.getLevelNumber()) + 1);
			nextLevel();
		}
	}
}

/***********************************************************
#NickP, SimonM
Name: endGame
Description: Calls graphics deletion of objects
**********************************************************/
void endGame()
{
		TrelGraphics2::close();
}

/***********************************************************
#SimonM
Name: winGame
Description: Handles the game being won
**********************************************************/
void winGame()
{
	// Game over is 5, Win screen is 6
	bool pause = true;
	int titleScreentoDisplay = 6;
	SDL_Event e;

	drawTitleScreen(6);

	while (!Level::quit && pause)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				Level::quit = true;
				TrelGraphics2::close();
				break;
			case SDL_KEYUP:
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					drawTitleScreen(4);
				}
				if (e.key.keysym.sym == SDLK_SPACE)
				{
					pause = false;
				}
				if (e.key.keysym.sym != SDLK_LEFT && e.key.keysym.sym != SDLK_SPACE)
				{
					pause = false;
				}
				break;
			}
		}
	}
}

/***********************************************************
#NickB
Name: showIntroScreen
Description: Shows intro screen, gives player an option to see instuction
**********************************************************/
void showIntroSceen( )
{
	// Intro is 3, how to play is 4
	bool pause = true;
	int titleScreentoDisplay = 3; 
	SDL_Event e;

	drawTitleScreen(3);

	while ( !Level::quit && pause )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			switch ( e.type )
			{
			case SDL_QUIT:
				Level::quit = true;
				break;
			case SDL_KEYUP:
				if ( e.key.keysym.sym == SDLK_LEFT )
				{
					drawTitleScreen(4);
				}
				if ( e.key.keysym.sym == SDLK_SPACE )
				{
					pause = false;
				}
				if (e.key.keysym.sym != SDLK_LEFT && e.key.keysym.sym != SDLK_SPACE)
				{
					pause = false;
				}
				break;
			}
		}
	}
}

