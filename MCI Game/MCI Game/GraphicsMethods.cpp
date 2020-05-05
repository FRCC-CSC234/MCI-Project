#include "GraphicsMethods.h"
//written by Trel J

/*************************
name: drawFlatScreen
description: ** this is a prototpye some things will be changed **
	Adds pictures from Brick,Ball,Paddle, and Level objects to frame rotation.
Comments Updated: Ben Jurenka
**************************/

void drawFlatScreen( std::vector<Brick> bricks, std::vector<Ball> balls, std::vector<Paddle> paddles, Level background, int powerupID )
{
	static TrelGraphics2 brickPictures( "Graphics_Text_Files/brickpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 ballPictures( "Graphics_Text_Files/ballpictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 paddlePictures( "Graphics_Text_Files/paddlepictures.txt", 0xFF, 0xFF, 0xFF );
	static TrelGraphics2 titleScreens( "Graphics_Text_Files/Title_Screens.txt" ); // No long only holding backgrounds updated name 
	static TrelGraphics2 factPictures( "Graphics_Text_Files/powerups_fact.txt", 0xFF, 0xFF, 0xFF );
	int x, y, w, h;
	double angle;
	bool vFlip, hFlip;
	SDL_Point center;
	TrelGraphics2::clearFrame( );
	titleScreens.addPictureToFrame( background.getPictureID( ), 0, 0 );
	for ( Brick brick : bricks )
	{
		w = brick.getWidth( )/2;	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = brick.getHeight( )/2; // This is working under the assumtion that getHeight returns the distance to the edge from teh center.
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
		brickPictures.addPictureToFrameRotation( brick.getPictureID( ), x, y, angle, vFlip, hFlip, center );
	}
	//*** changes above repeated
	for ( Ball ball : balls )
	{
		w = ball.getWidth( );	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = ball.getHeight( ); // This is working under the assumtion that getHeight returns the distance to the edge from the center.
		x = ball.getX( ) - w;
		y = ball.getY( ) - h;
		angle = ball.getAngle( );
		//angle = 0;
		//vFlip = ball.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
		//hFlip = ball.getHFlip( );	// ^
		vFlip = false;
		hFlip = false;
		//center = (x + w, y + h);
		center.x = w; // Updated 4.28
		center.y = h; // Updated 4.28
		ballPictures.addPictureToFrameRotation( ball.getPictureID( ), x, y, angle+90, vFlip, hFlip, center );
	}
	//#nathan: "I attempted to make it so multipal paddles can be drawn on to the screen but have been un succsessful."
	for (Paddle paddle : paddles)
	{
		w = paddle.getWidth()/2;	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
		h = paddle.getHeight( )/2; // This is working under the assumtion that getHeight returns the distance to the edge from teh center.
		x = paddle.getX()-w;
		y = paddle.getY() - h;
		//angle = paddle.getDirection( );
		angle = 0;
		//vFlip = paddle.getVFlip( );	// Temperory concept, likely to be replaced by math, will depend on art and logic team.
		//hFlip = paddle.getHFlip( );	// ^
		vFlip = false;
		hFlip = false;
		//center = (x + w, y + h);
		center.x = w; // Updated 4.28
		center.y = h; // Updated 4.28
		paddlePictures.addPictureToFrameResize(paddle.getPictureID(), x, y, w*2, h*2);
	}
	if (powerupID!=-1)
	{
		factPictures.addPictureToFrame( powerupID, 150, 200 );
	}
	TrelGraphics2::drawFrame( );
}

/*************************
name: drawCircularScreen
description: ** this is a prototpye some things will be changed **
	Adds pictures from Brick,Ball,Paddle, and Level objects to frame rotation.
Comments Updated: Ben Jurenka
**************************/
void drawCircularScreen( std::vector<Brick> bricks, std::vector<Ball> balls, Paddle paddle, Level background )
{
	cout << "***** This method has not been built yet"<< endl; 
}


/********************************************************
name: drawTitleScreen
description: creates a static TrelGraphics2 object that holds
		 one texture loaded from text stored in titleImage.txt file
		 adds title image to window.
**********************************************************/
void drawTitleScreen( int titleImageID )
{
	static TrelGraphics2 titleImage( "Graphics_Text_Files/Title_Screens.txt" );// Best way to handle it, not worth making a new constructor for one image, and doing seperalty is a bad idea with static local variables
	titleImage.addPictureToFrame( titleImageID, 0, 0 );
	TrelGraphics2::drawFrame( );
}


void drawLivesScreen(int lives)
{
	static TrelGraphics2 titleImage( "Graphics_Text_Files/Title_Screens.txt", 0xFF, 0xFF, 0xFF );// Best way to handle it, not worth making a new constructor for one image, and doing seperalty is a bad idea with static local variables

	SDL_Event e;
	for ( int i = 0; i < 90 && !Level::quit; i++ )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			switch ( e.type )
			{
			case SDL_QUIT:
				Level::quit = true;
			}
		}
		titleImage.addPictureToFrame( 7, 0, 0 );
		titleImage.addPictureToFrame( lives+8, 330, 290 );
		TrelGraphics2::drawFrame( );
	}
	for ( int i = 0; i < 90 && !Level::quit; i++ )
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			switch ( e.type )
			{
			case SDL_QUIT:
				Level::quit = true;
			}
		}
		if ( lives > 0 )
		{
			titleImage.addPictureToFrame( 7, 0, 0 );
			titleImage.addPictureToFrame( lives - 1 + 8, 330, 290 );
		}
		else
		{
			titleImage.addPictureToFrame( 5, 0, 0 );
			}
		TrelGraphics2::drawFrame( );
	}
}