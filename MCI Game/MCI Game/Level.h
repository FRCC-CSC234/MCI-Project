#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "GraphicsMethods.h"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "SDL_Mixer.h"

using namespace std;

//Written by Nick Pallotti, edited by Simon Martin, Nick Brady, Trel Johnson, and Kyle Dexter

class Level
{
	int levelNumber;
	bool complete;

	//#SimonM if player has a bonus ball, this will be true. 
	//If bonus ball hits bottom, this will become false but no lifes reduced
	bool bonusBall; 

	//#SimonM if player has a second paddle this will be true. Once player 
	//loses a life this becomes false
	bool bonusPaddle;

	//#SimonM if player has the 'one time shield' power up the ball will 
	//just bounce off the bottom of the screen once.
	bool invincible;

	//#SimonM if player has the super ball power up this will be true.
	//makes the ball bounce through all bricks until it hits the top
	bool superBall;

	// Nick B adding a certain number of times player can use stickyBall
	int stickyBall; 

	vector<Ball> balls;
	vector<Brick> bricks;
	vector<Paddle> paddles;

	//*** Adding Picture ID to level for background images
	int pictureID; // ID value for background image.
	int playerLives;

	void develop( );

public:

	static bool quit;
	//#NickP constructors
	Level();
	Level(int x);

	void startFlatLevel( );
	void startCircularLevel( );

	//#SimonM sound effect and music methods
	void startMusic(int x);
	void playSound(int x);
	
	//Randomizes and draws bricks for the circular level
	void createCircleBricks( );

	//randomizes and draws bricks on the screen
	void createBricks( );
	void createBricks2();

	//need comments
	void gameFrame( );
	void checkFlatCollision( );
	void checkCollisionCircular( );
	void shouldTheBallBeHereFlat( );
	void shouldTheBallBeHereCircular( );

	//#NickP add items to vectors
	void addBall(Ball ball) { balls.push_back(ball); }
	void addBrick(Brick brick) { bricks.push_back(brick); }

	//#NathanM checks a brick in the vector for powerups and activates as necessary	
	void checkPowerUps(int brickLocation);
	
	//getters/setters
	void setLevelNumber(int x) { levelNumber = x; }
	void setComplete(bool c) { complete = c; }
	void setPaddle(Paddle paddle) { paddles.push_back(paddle); }
	void setBonusBall(bool isBonus) { this->bonusBall = isBonus; }
	void setBonusPaddle(bool isBonus) { this->bonusPaddle = isBonus; }
	void setInvincible(bool isInvincible) { this->invincible = isInvincible; }
	void setPictureID( int pictureID ) { this->pictureID = pictureID; }
	void setLives(int addLives) { this->playerLives = addLives; }

	int getPictureID( ) { return pictureID; }
	void moveBall(bool b);
	bool getInvincible() { return invincible; }
	bool getBonusPaddle() { return bonusPaddle; }
	bool getBonusBall() { return bonusBall; }
	int getLevelNumber() { return levelNumber;}
	bool getComplete() { return complete; }
	vector<Ball> getBalls() { return balls; }
	vector<Brick> getBricks() { return bricks; }
	vector<Paddle> getPaddles() { return paddles; }
	int getLives( ) { return playerLives; }
};

