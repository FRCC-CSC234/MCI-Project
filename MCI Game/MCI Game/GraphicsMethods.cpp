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
		if (background.getLevelNumber()==2)
		{
			x = brick.getX();
			y = brick.getY();
			angle = brick.getRotateVal();
			//angle = 0;
			vFlip = brick.getVerFlip();
			hFlip = brick.getHorFlip();
			//vFlip = false;
			//hFlip = false;
			brickPictures.addPictureToFrameRotation( brick.getPictureID( ), x, y, angle, vFlip, hFlip );
		}
		else
		{
			w = brick.getWidth() / 2;	// This is working under the assumtion that getWidth returns the distance to the edge from the center.
			h = brick.getHeight() / 2; // This is working under the assumtion that getHeight returns the distance to the edge from teh center.
			x = brick.getX() - w; //*** removed Center to match logic code
			y = brick.getY() - h;
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
		ballPictures.addPictureToFrameRotation( ball.getPictureID( ), x, y, angle+90, vFlip, hFlip, &center );
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




/*
void drawCircularScreen( std::vector<CBrick> bricks, std::vector<Ball> balls, vector<CPaddle> paddle, Level background, int powerupID )
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
	for (int i=0; i<paddles.size(); i++)
	{
		radius = paddles[i].getRadius( );
		angle = paddles[i].getAngle( ) + 90;
		int picID = paddle.getPictureID( );
		x = (360 + ((cos( angle ) * PI / 180) * radius)) - paddles[i].getCenterX( );
		y = (360 + ((sin( angle ) * PI / 180) * radius)) - paddles[i].getCenterY( );
		vFlip = false;
		hFlip = false;
		paddlePictures.addPictureToFrameRotation( picID, x, y, angle-90, vFlip, hFlip );
	}
	if ( powerupID != -1 )
	{
		powerupFacts.addPictureToFrame( (powerupID * 2) + rand( ) % 2, 200, 150 );
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