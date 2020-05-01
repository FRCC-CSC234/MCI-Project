#pragma once
#include "Paddle.h"
//#include "Level.h"

class Player
{
private:

	//Player's Name
	//string playerName;

	//Player current score
	//int playerScore;

	//Player current lives
	int playerLives;

	//The player's paddle
	//Paddle playerPaddle;

	//Current level the player is on
	//Level currentLevel;
public:
	//Constructors
	Player( );
	//Player( string name );

	//Setters
	//void setLevel( Level levelNumber );
	//void addScore( int score );
	//void takeScore( int score );
	void addLives( int lives );
	void takeLives( int lives );

	//Getters
	//Paddle getPlayerPaddle( );
	//Level getLevelDetails( );
	//int getScore( );
	int getLives( );
};

