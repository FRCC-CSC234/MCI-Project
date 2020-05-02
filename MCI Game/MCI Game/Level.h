#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Player.h"
#include <vector>

using namespace std;

class Level
{
	int levelNumber;
	bool complete;
	bool bonus;
	vector<Ball> balls;
	vector<Brick> bricks;
	vector<Paddle> paddles;

	//*** Adding Picture ID to level for background images
	int pictureID; // ID value for background image.

	void develop( );

public:
	Level();
	Level(int x);

	int getPictureID( ) { return pictureID; }
	void setPictureID( int pictureID ) { this->pictureID = pictureID; }

	int moveObjects(int direction, Player &player);
	void checkPowerUps(int brickLocation);

	void setLevelNumber(int x) { levelNumber = x; }
	void setComplete(bool c) { complete = c; }
	void addBall(Ball ball) { balls.push_back(ball); }
	void addBrick(Brick brick) { bricks.push_back(brick); }
	void setPaddle(Paddle paddle) { paddles.push_back(paddle); }
	void moveBall(bool b) { balls.at(0).setMoveable(b);}
	void setBonus(bool isBonus) { this->bonus = isBonus; }

	bool getBonus() { return bonus; }
	int getLevelNumber() { return levelNumber;}
	bool getComplete() { return complete; }
	vector<Ball> getBalls() { return balls; }
	vector<Brick> getBricks() { return bricks; }
	vector<Paddle> getPaddles() { return paddles; }
	
};

