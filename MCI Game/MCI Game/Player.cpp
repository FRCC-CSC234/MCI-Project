#include "Player.h"
#include "Driver.h"
#include <string>

// Team: Logic
// Author: Kyle Dexter


//Parent class containing common fields for game objects

/***********************************************************
#KyleD
Name: Player
Description: Constructors
**********************************************************/

Player::Player( )
{
	playerName = "No Name";
	playerScore = 0;
	playerLives = 0;
	Paddle playerPaddle;
	Level currentLevel;
}
Player::Player( string name )
{
	playerName = name;
	playerScore = 0;
	playerLives = 5;
	playerPaddle;
	currentLevel;
}

/***********************************************************
#KyleD
Name: Player
Description: Setter, updates level.
**********************************************************/

void Player::setLevel( Level levelNumber )
{
	currentLevel = levelNumber;
}

/***********************************************************
#KyleD
Name: Player
Description: Setter, adds score
**********************************************************/

void Player::addScore( int score )
{
	playerScore = playerScore + score;
}

/***********************************************************
#KyleD
Name: Player
Description: Setter, subtracts score
**********************************************************/

void Player::takeScore( int score )
{
	playerScore = playerScore - score;
}

/***********************************************************
#KyleD
Name: Player
Description: Setter, adds lives
**********************************************************/

void Player::addLives( int lives )
{
	playerLives = playerLives + lives;
}

/***********************************************************
#KyleD
Name: Player
Description: Setter, subtracts lives
**********************************************************/

void Player::takeLives( int lives )
{
	playerLives = playerLives - lives;
}

/***********************************************************
#KyleD
Name: Player
Description: Getter, returns level info
**********************************************************/

Level Player::getLevelDetails( )
{
	return currentLevel;
}

/***********************************************************
#KyleD
Name: Player
Description: Getter, returns Paddle information
**********************************************************/


Paddle Player::getPlayerPaddle( )
{
	return playerPaddle;
}

/***********************************************************
#KyleD
Name: Player
Description: Getter, returns score
**********************************************************/

int Player::getScore( )
{
	return playerScore;
}

/***********************************************************
#KyleD
Name: Player
Description: Getter, returns score
**********************************************************/

int Player::getLives( )
{
	return playerLives;
}