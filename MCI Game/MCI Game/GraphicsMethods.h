#pragma once
#include "TrelGraphics2.h"
#include "Driver.h"
//written by Trel J

class Level;

void drawFlatScreen( vector<Brick> bricks, vector<Ball> balls, vector<Paddle> paddle, Level background, int powerupID=-1 );
void drawCircularScreen( std::vector<Brick> bricks, std::vector<Ball> balls, std::vector<Paddle> paddle, Level background ); // To be built at a later time
void drawTitleScreen( );
