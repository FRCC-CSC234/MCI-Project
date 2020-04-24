#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include "Brick.h"
#include "Ball.h"

using namespace std;

class Level
{

	/*******************************
	#Nick Pallotti
	I added private here and variables 
	for the brick array, ball object,
	boolean for whether or not the game 
	is complete and the level number
	********************************/
private:

	int levelNumber;

	vector<Brick>bricks;

	Ball ball;

	bool complete;

	//*** Adding Picture ID to level for background images
	int pictureID; // ID value for background image.

	void develop( );

public:
	int getPictureID( ) { return pictureID; }
	void setPictureID( int pictureID ) { this->pictureID = pictureID; }

	/*******************************
	#Nick Pallotti
	this is the Level constructor
	********************************/
	Level() {}

	/*******************************
	#Nick Pallotti
	this is the Level constructor
	when being passed what level the
	player is on
	********************************/
	Level(int x) {}

	/*******************************
	#Nick Pallotti
	getters for the variables
	********************************/
	
	Ball getBall() { return ball; }
	vector<Brick> getBricks() { return bricks; }
	bool getComplete() { return complete; }
	int getLevelNumber() { return levelNumber; }

	/*******************************
	#Nick Pallotti
	setters for the variables
	********************************/

	void setBall(){}
	void setBricks(vector<Brick> bricks){}
	void setComplete(){}
	void setLevel(int x) {}

};

