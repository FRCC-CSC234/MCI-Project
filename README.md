# MCI Brick Break Game

The MCI Brick Break Game was created as a tool for publishing information regarding male contraception and pregnancies.  The hope is that this medium would best reach the target audience of 13 - 30 year old males.  Male Contraceptive Initiative (MCI) [https://www.malecontraceptive.org/](https://www.malecontraceptive.org/) contracted with the students from the Front Range Community College [https://www.frontrange.edu/campuses/campus-locations/larimer-campus](https://www.frontrange.edu/campuses/campus-locations/larimer-campus), Spring 2020 CSC 234 class to create and code the game.


# The Game 

This brick break game is a 2 dimensional, 1980's style game.  The game consists of 3 levels.  All levels contain hidden powerup bricks which not only display a message regarding male contraception but alter the player's game (i.e. changing speeds, changing paddle sizes ...).
This is a single person game.

## Game Structure

The game was written in C++ using SDL (Simple DirectMedia Layer) libraries.  Appropriate SDL2 libraries will need to be installed, included and linked to the project file prior to editing.  [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php) 
[https://www.libsdl.org/projects/SDL_mixer/](https://www.libsdl.org/projects/SDL_mixer/)
SDL_tff is not needed as text was rendered as images.

## Project Flow
Class gameMain contains:    
   	StartGame():
    ShowIntro():
   	PlayGame():
    StartMusic():
   	EndGame():

Class graphicsMethods contains:
    drawFlatScreen(): for levels 1, 2 and 3 game play
    drawCircularScreen(): to be implemented at a later date
    drawTitleScreen(): for StartGame()
    
Class level contains:
    createBricks():
    gameFrame():
    checkCollision():
    shouldTheBallBeHere():
    addBall():
    addBrick():
    checkPowerUps():
    
Classes paddle, brick and ball primarily contains:
    move():
    
Class TrelGraphics2 primarily contains (some methods have permutations):
    start():
	close( ):
	TrelGraphics2(): creates a graphics object
	createPictureFromFile( ):	
	readImageListFromFile( ):	
	addPictureToFrame( ):  adds a picture to a frame
	addRectToFrame():
    drawFrame( ):
    clearFrame( ):
    
Class TrelTexture contains:
    TrelTexture( ):
	~TrelTexture( ):
	loadFromFile():
	free( ):
	render( ):
	renderResize( ):
    setColor():

## Copyright/License Agreement
Copyright 2020: Nick Brady, Joy Choi, Kyle Dexter, Tony Erle, Trel Johnson, Ben Jurenka, Cayce Kelley, Blake Maenhout, Simon Martin, Nathan McIntrye, Nicholas Pallotti, Sophia Ressler, Alex Riesenhuber, Michael Webb, Patty Wiens

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License, or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

