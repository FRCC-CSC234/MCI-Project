//Main Driver for MCI Game - version 1
//starts, plays and ends the game
//written by: Patty Wiens 4/18/20
//edited by:  Trel Johnson, Nick Brady 4/22, Simon Martin 4/29


// Implemented Driver.h to remove having to include more than 1 .h file
#include "Driver.h"


using namespace std;


void startGame( );
void endGame( );
void playGame( );
//void startMusic();

vector<Brick> bricks;
vector<Ball> balls;
Paddle paddle;
Level level; //*** exists to make me not have to delete stuff from drawScreen();


int main( int argc, char** argv ) // Main must have these specific arguments for SDL to work 
{

	
	startGame( );
	//startMusic();
	playGame( );
	endGame( );
	


	system( "pause" );
	return 0;
}


//*** moved game.cpp over to here


void startGame( )
{
	//#nick pallotti
	//i changed the games width to 720 to better fit the blocks as well as the blue
	//backgrounds width to 720 but not the other colors
	TrelGraphics2::start( "Insert MCI Game Name Here", 720, 500 ); //*** needed a TrelGraphics::start call, made up a size.
	cout << "in Gamemain startGame - NEEDS TO BE IMPLEMENTED" << endl;
	
}

void playGame( )
{
	cout << "in Gamemain playGame - NEEDS TO BE IMPLEMENTED" << endl;

	bool quit = false;
	int direction = 0;
	SDL_Event e;
	while ( !quit )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			if ( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if ( e.type == SDL_KEYDOWN )
			{
				int paddleLocation = level.getPaddle().getX();
				switch ( e.key.keysym.sym )
				{
					
				case SDLK_LEFT:
					direction = -1;
					//(level.getPaddle()).setX(paddleLocation - 5);
					break;
				case SDLK_RIGHT:
					direction = 1;
					break;
				case SDLK_1:
					level.setPictureID( 0 );
					break;
				case SDLK_2:
					level.setPictureID( 1 );
					break;
				case SDLK_3:
					level.setPictureID( 2 );
					break;

				}
			}
			else if ( e.type == SDL_KEYUP )
			{
				switch ( e.key.keysym.sym )
				{
				case SDLK_LEFT:
					direction = direction == 1 ? 1 : 0;
					break;
				case SDLK_RIGHT:
					direction = direction == -1 ? -1 : 0;
					break;
				}
			}
		}

		//handle all the objects that need to be moved
		level.moveObjects(direction);
		
		// removed draw code. Draw Flat screen needs to be used to draw things to the screen 
		drawFlatScreen( level.getBricks(), level.getBalls(), level.getPaddle(), level );
	}

}

void endGame( )
{
	cout << "in gameMain endGame - NEEDS TO BE IMPLEMENTED" << endl;
	TrelGraphics2::close( );

}

//void startMusic()
//{
//	if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);
//
//	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
//	Mix_Music* mus;  // Background Music
//
//	mus = Mix_LoadMUS("MCIsong2.wav");
//
//	Mix_PlayMusic(mus, -1); //Music loop: -1 for continuous play
//
//}



