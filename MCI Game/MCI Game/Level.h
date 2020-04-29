#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include <vector>

using namespace std;

class Level
{
	
	int levelNumber;
	bool complete;
	vector<Ball> balls;
	vector<Brick> bricks;
	Paddle paddle;

	//*** Adding Picture ID to level for background images
	int pictureID; // ID value for background image.

	void develop( );

public:
	Level();

	int getPictureID( ) { return pictureID; }
	void setPictureID( int pictureID ) { this->pictureID = pictureID; }

	void moveObjects(int direction);

	void setLevelNumber(int x) { levelNumber = x; }
	void setComplete(bool c) { complete = c; }
	void addBall(Ball ball) { balls.push_back(ball); }
	void addBrick(Brick brick) { bricks.push_back(brick); }
	void setPaddle(Paddle p) { paddle = p; }
	

	int getLevelNumber() { return levelNumber;}
	bool getComplete() { return complete; }
	vector<Ball> getBalls() { return balls; }
	vector<Brick> getBricks() { return bricks; }
	Paddle getPaddle() { return paddle; }
	
};

