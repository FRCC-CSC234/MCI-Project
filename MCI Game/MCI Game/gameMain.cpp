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
void startMusic();
void nextLevel( );

Level level; //*** exists to make me not have to delete stuff from drawScreen();

int main( int argc, char** argv ) // Main must have these specific arguments for SDL to work 
{

	startGame();

	showIntroSceen();
	level.setLevelNumber(0);
	if (level.getLevelNumber() == 0)
	{
		playGame();
		level.setLevelNumber(1);
	}
	if (level.getLevelNumber() == 1) 
	{
		playGame();
		
	}

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
	startMusic();
	TrelGraphics2::start( "Insert MCI Game Name Here", 600, 600 ); //*** needed a TrelGraphics::start call, made up a size.
	cout << "in Gamemain startGame - NEEDS TO BE IMPLEMENTED" << endl;
	
}

void nextLevel()
{


}

/***********************************************************
#NickP
Name: playGame
Description: Contains calls to SDL and other classes to run the game
**********************************************************/
void playGame()
{
	cout << "in Gamemain playGame - NEEDS TO BE IMPLEMENTED" << endl;

	


	SDL_Event e;
	int direction = 0;
	int gameState = 0;
	while (!Level::quit)
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
						Paddle::setDirection( -1 );
						break;
					case SDLK_RIGHT:
						direction = 1;
						Paddle::setDirection( 1 );
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
						level.moveBall(true);
						break;
					}
				}
				else if (e.type == SDL_KEYUP)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_LEFT:
						direction = direction == 1 ? 1 : 0;
						Paddle::setDirection( Paddle::getDirection( ) == 1 ? 1 : 0 );
						break;
					case SDLK_RIGHT:
						direction = direction == -1 ? -1 : 0;
						Paddle::setDirection( Paddle::getDirection( ) == -1 ? -1 : 0 );
						break;
						//#SimonM set spacebar to change balls movable bool to true
					case SDLK_SPACE:
						level.moveBall(true);
						break;
					}


				}
			}



			//#SimonM the moveObjects method returns an int -1 for death, 0 for normal, 1 for moving to next level
			for (int i = 0; i < 6 && gameState == 0; i++)
			{
				//gameState = level.moveObjects(direction, player);
				level.gameFrame( );
			}
			// removed draw code. Draw Flat screen needs to be used to draw things to the screen 
			drawFlatScreen(level.getBricks(), level.getBalls(), level.getPaddles(), level);








			//#SimonM
			//if player is out of lives, quit. Need to put in way to exit this method and move to endGame method here instead.
			/*
			if (gameState == -1)
			{
				cout << endl << "you dead womp womp" << endl;
				quit = true;
			}

			if (gameState == 1)
			{
				//do level progression code here
				cout << endl << "Next level time" << endl;
				quit = true;
			}
			*/
		}
}

/***********************************************************
#NickP
Name: endGame
Description: Calls graphics deletion of objects
**********************************************************/
void endGame()
{
	cout << "in gameMain endGame - NEEDS TO BE IMPLEMENTED" << endl;
	TrelGraphics2::close( );
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

	drawTitleScreen( 3 );

	while ( !Level::quit && pause )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			switch ( e.type )
			{
			case SDL_QUIT:
				Level::quit = true;
				break;
			case SDL_KEYDOWN:
				if ( e.key.keysym.sym == SDLK_LEFT )
				{
					drawTitleScreen( 4 );
				}
				if ( e.key.keysym.sym == SDLK_SPACE )
				{
					pause = false;
				}
				break;
			}
		}
	}
}


/***********************************************************
#PattiW
Name: startMusic
Description: Plays music
**********************************************************/
void startMusic()
{
	//if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);

	//Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	//Mix_Music* mus;  // Background Music

	//mus = Mix_LoadMUS("MCIsong2.wav");

	//Mix_PlayMusic(mus, -1); //Music loop: -1 for continuous play
} 

