#include "Level.h"

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

Level::Level() {

	Ball ball;
	
	ball.setX(400);
	ball.setY(200);
	
	addBall(ball);

	Paddle paddle;
	paddle.setX(350);
	paddle.setY(450);

	Brick brick;
	brick.setX(300);
	brick.setY(30);
	addBrick(brick);

	//level.setPictureID(0);
}

void Level::moveBalls() {
	for (int i = 0; i < balls.size(); i++) {
		balls.at(i).move();
	}
}
