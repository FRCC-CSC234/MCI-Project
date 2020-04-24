#include "Level.h"
#include "Brick.h"
#include "Ball.h"
#include<vector>

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

/*******************************
#Nick Pallotti
this is the default Level constructor
********************************/

Level::Level()
{
	int levelNumber = 1;

	setBricks(bricks);

	complete = false;

	setBall();

}


/*******************************
#Nick Pallotti
this is the Level constructor 
when being passed what level the player 
is on
********************************/
Level::Level(int x)
{
	int levelNumber = x;

	setBricks(bricks);

	complete = false;

	Ball* ball = new Ball();
}

/*******************************
	#Nick Pallotti
	getters for the variables
********************************/

Ball Level::getBall() { 
	return (ball); 
}
vector<Brick> Level::getBricks() {
	return (bricks); 
}
bool Level::getComplete() {
	return (complete); 
}
int Level::getLevelNumber() {
	return (levelNumber); 
}


/*******************************
	#Nick Pallotti
	setters for the variables
********************************/
void setBall() {

}

void setBricks(vector<Brick> bricks) {

}

void setComplete() {

}

void setLevel(int x) {

}