#pragma once
#include "TrelGraphics2.h"
#include "Driver.h"
//written by Trel J

void drawFlatScreen( vector<Brick> bricks, vector<Ball> balls, Paddle paddle, Level background, int powerupID=-1 );
//void drawCircularScreen( std::vector<CBrick> bricks, std::vector<Ball> balls, CPaddle paddle, Level background, int powerupID=-1 ); // To be built at a later time
void drawTitleScreen( );

// commented out circular screen to avoid errors caused by not having circular brick and paddle types in existance.
																			// I don't know how to spell	 ^