#include "Level.h"

void Level::develop( )
{
	cout << "in Level.cpp - NEEDS TO BE IMPLEMENTED" << endl;
}

Level::Level() {

	Ball ball;
	ball.setX(400);
	ball.setY(380);
	addBall(ball);

	//Paddle paddle;
	paddle.setX(350);
	paddle.setY(400);

	ball.setSpeedY(-2);
	
	//currently  have a defualt array for testing, this should be changed eventualy
	for (int i = 0; i < 30; i++) {
		Brick brick;
		brick.setX((i%10)* 72);
		brick.setY((i/10) * 29);
		addBrick(brick);
	}

	//level.setPictureID(0);
}

Level::Level(int x) {

	Ball ball;
	ball.setX(400);
	ball.setY(380);
	addBall(ball);

	//Paddle paddle;
	paddle.setX(350);
	paddle.setY(400);

	levelNumber = x;

	ball.setSpeedY(-2 + x);

	//currently  have a defualt array for testing, this should be changed eventualy
	for (int i = 0; i < 30; i++) {
		Brick brick;
		brick.setX((i % 10) * 72);
		brick.setY((i / 10) * 29);
		addBrick(brick);
	}

	//level.setPictureID(0);
}

//#nick pallotti
//this method moves the ball and also checks for collision with the paddle
int Level::moveObjects(int direction, Player &player) {

	//for each ball on the board move the ball
	for (int i = 0; i < balls.size(); i++) {
		
		//for loop checks for the balls collision with the bricks
		for (int j = 0; j < bricks.size(); j++) {

			//ball x/y are the balls x and y coordinates	
			int ballx = (balls.at(i)).getX() + 7;
			int bally = (balls.at(i)).getY();


			//the bounds/edges of the brick
			int xLeftBound = bricks.at(j).getX();
			int xRightBound = bricks.at(j).getX() + 72;

			int yBottomBound = bricks.at(j).getY();
			int yTopBound = bricks.at(j).getY() + 29;

			//if block checking that the ball intersects with the y and x coordinateds of the block
			if (bally >= yBottomBound && bally <= yTopBound) {
				if(ballx >= xLeftBound && ballx <= xRightBound) {
					//if there is an collision erase the block and send the ball back
					bricks.erase(bricks.begin() + j);
					//#SimonM if the array of bricks is empty, move on to next level
					if (bricks.size() == 0)
					{
						return 1;
					}

					int newSpeed = balls.at(i).getSpeedY() * -2;
					(balls.at(i)).setSpeedY(newSpeed);
					
				}
	
			}
			
		}

		//#SimonM if move returns -1, means the ball is dead, resets to paddle waits for space to launch
		if (balls.at(i).move(paddle.getX(), bricks) == -1)
		{
			//death
			player.takeLives(1);
			cout << player.getLives();

			//#SimonM if player is out of lives, end game.
			if (player.getLives() < 0)
			{
				cout << "Game over!" << endl;
				paddle.setX(350);
				paddle.setY(400);
				
				balls.at(i).setSpeedX(0);
				balls.at(i).setSpeedY(0);
				return -1;
			}

			//#SimonM reset ball and paddle to middle
			paddle.setX(350);
			paddle.setY(400);

			balls.at(i).setX(400);
			balls.at(i).setY(380);
			balls.at(i).setSpeedY(-2);

			//#SimonM set ball to immovable so that it waits for the space key to start moving again
			balls.at(i).setMoveable(false);
					
		}
	}

	//move the paddle in the apporpriate direction
	if (direction == 1) {
		paddle.setX(paddle.getX() + 8);
	}

	if (direction == -1) {
		paddle.setX(paddle.getX() - 8);
	}

	return 0;
}
