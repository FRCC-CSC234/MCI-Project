#include "GraphicsMethods.h"
//written by Trel J

/*************************
name: drawFlatScreen
description: ** this is a prototpye some things will be changed **
	Adds pictures from Brick,Ball,Paddle, and Level objects to frame rotation.
Comments Updated: Ben Jurenka
**************************/

void drawFlatScreen( std::vector<Brick> bricks, std::vector<Ball> balls, Paddle paddle, Level background, int powerupID )
{
	static TrelGraphics2 brickPictures( "Graphics_Text_Files/brickpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 ballPictures( "Graphics_Text_Files/ballpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 paddlePictures( "Graphics_Text_Files/paddlepictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 titleScreens( "Graphics_Text_Files/Title_Screens.txt" ); // No long only holding backgrounds updated name 
	static TrelGraphics2 powerupFacts( "powerups_fact.txt" );
	int x, y, w, h;
	double angle;
	bool vFlip, hFlip;
	SDL_Point center;
	titleScreens.addPictureToFrame( background.getPictureID( ), 0, 0 );
	for ( Brick brick : bricks )
	{
		w = brick.getWidth( );	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = brick.getHeight( ); // This is working under the assumtion that getHeight returns the distance to the edge from teh center.
		x = brick.getX( ) - w; //*** removed Center to match logic code
		y = brick.getY( ) - h;
		//angle = brick.getDirection( );  //*** commentted out as it's not used for other objects.
		angle = 0;
		//*** commenting out flipping and replacing with false as we are not doing that here.
		//vFlip = brick.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
		//hFlip = brick.getHFlip( );	// ^
		vFlip = false;
		hFlip = false;
		//*** incorrect setup for SDL_Point, replacing center = (x + w, y + h);
		center.x = w; // Updated 4.28
		center.y = h; // Updated 4.28
		brickPictures.addPictureToFrameRotation( brick.getPictureID( ), x, y, angle, vFlip, hFlip, &center );
	}
	//*** changes above repeated
	for ( Ball ball : balls )
	{
		w = ball.getWidth( );	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = ball.getHeight( ); // This is working under the assumtion that getHeight returns the distance to the edge from the center.
		x = ball.getX( ) - w;
		y = ball.getY( ) - h;
		//angle = ball.getDirection( );
		angle = 0;
		//vFlip = ball.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
		//hFlip = ball.getHFlip( );	// ^
		vFlip = false;
		hFlip = false;
		//center = (x + w, y + h);
		center.x = w; // Updated 4.28
		center.y = h; // Updated 4.28
		ballPictures.addPictureToFrameRotation( ball.getPictureID( ), x, y, angle, vFlip, hFlip, &center );
	}
	w = paddle.getWidth( );	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
	h = paddle.getHeight( ); // This is working under the assumtion that getHeight returns the distance to the edge from teh center.
	x = paddle.getX( ) - w;
	y = paddle.getY( ) - h;
	//angle = paddle.getDirection( );
	angle = 0;
	//vFlip = paddle.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
	//hFlip = paddle.getHFlip( );	// ^
	vFlip = false;
	hFlip = false;
	//center = (x + w, y + h);
	center.x = w; // Updated 4.28
	center.y = h; // Updated 4.28
	paddlePictures.addPictureToFrameRotation( paddle.getPictureID( ), x, y, angle, vFlip, hFlip, &center );
	if ( powerupID != -1 )
	{
		powerupFacts.addPictureToFrame( (powerupID * 2) + rand( ) % 2, 170, 150 );
	}
	TrelGraphics2::drawFrame( );
}

/*************************
name: drawCircularScreen
description: ** this is a prototpye some things will be changed **
	Adds pictures from Brick,Ball,Paddle, and Level objects to frame rotation.
Comments Updated: Ben Jurenka
**************************/
// commented out due to not having circular brick or paddle types.
/*
void drawCircularScreen( std::vector<CBrick> bricks, std::vector<Ball> balls, CPaddle paddle, Level background, int powerupID )
{
	static const double PI = 3.1415926535897;
	static TrelGraphics2 brickPictures( "Graphics_Text_Files/brickpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 ballPictures( "Graphics_Text_Files/ballpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 paddlePictures( "Graphics_Text_Files/paddlepictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 titleScreens( "Graphics_Text_Files/Title_Screens.txt" );

	cout << "***** This method has not been built yet" << endl;
	double angle;
	int x, y, w, h;
	int radius;
	bool vFlip, hFlip;
	SDL_Point center;
	for ( CBrick brick : bricks )
	{
		radius = brick.getRadius( );
		angle = brick.getAngle( )+90;
		int picID = brick.getPictureID( )+14;
		w=brick.getCenterX();
		h=brick.getCenterY();
		// these two could get replaced with stuff simaler to ball depending on how it's handled. 
		x = (360 + ((cos( angle ) * PI / 180)* radius))-w;
		y = (360 + ((sin( angle ) * PI / 180) * radius)) - h;
		// these two could get replaced wiht x and y checks, depending on how it's handled.
		vFlip = (angle > 0 && angle < 180);
		hFlip = (angle > 90 && angle < 270);
		brickPictures.addPictureToFrameRotation(picID, x, y, 0, vFlip, hFlip);
	}
	for ( Ball ball : balls )
	{
		w = ball.getWidth( );	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = ball.getHeight( ); // This is working under the assumtion that getHeight returns the distance to the edge from the center.
		x = ball.getX( ) - w;
		y = ball.getY( ) - h;
		//angle = ball.getDirection( );
		angle = 0;
		//vFlip = ball.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
		//hFlip = ball.getHFlip( );	// ^
		vFlip = false;
		hFlip = false;
		//center = (x + w, y + h);
		center.x = w; // Updated 4.28
		center.y = h; // Updated 4.28
		ballPictures.addPictureToFrameRotation( ball.getPictureID( ), x, y, angle, vFlip, hFlip, &center );
	}
	radius = paddle.getRadius( );
	angle = paddle.getAngle( ) + 90;
	int picID = paddle.getPictureID( );
	x = (360 + ((cos( angle ) * PI / 180) * radius)) - paddle.getCenterX( );
	y = (360 + ((sin( angle ) * PI / 180) * radius)) - paddle.getCenterY( );
	vFlip = false;
	hFlip = false;
	paddlePictures.addPictureToFrameRotation( picID, x, y, angle-90, vFlip, hFlip );
	if ( powerupID != -1 )
	{
		powerupFacts.addPictureToFrame( (powerupID * 2) + rand( ) % 2, 170, 150 );
	}
	TrelGraphics2::drawFrame( );
}
*/

/********************************************************
name: drawTitleScreen
description: creates a static TrelGraphics2 object that holds
		 one texture loaded from text stored in titleImage.txt file
		 adds title image to window.
**********************************************************/
void drawTitleScreen( )
{
	static TrelGraphics2 titleImage( "titleImage.txt" );// Best way to handle it, not worth making a new constructor for one image, and doing seperalty is a bad idea with static local variables
	titleImage.addPictureToFrame( 0, 0, 0 );
	TrelGraphics2::drawFrame( );
}
