# MCI Brick Break Game

The MCI Brick Break Game was created as a tool for publishing information regarding male contraception and pregnancies.  The hope is that this medium would best reach the target audience of 13 - 30 year old males.  Male Contraceptive Initiative (MCI) [https://www.malecontraceptive.org/](https://www.malecontraceptive.org/) contracted with the students from the Front Range Community College [https://www.frontrange.edu/campuses/campus-locations/larimer-campus](https://www.frontrange.edu/campuses/campus-locations/larimer-campus), Spring 2020 CSC 234 class to create and code the game.


# The Game 

This brick break game is a 2 dimensional, 1980's style game.  The game consists of 2 levels.  Level one is the standard straight attack brick break game.  Level two is "brick break in the round".  Both levels contain hidden powerup bricks which not only display a message regarding male contraception but alter the player's game (i.e. changing speeds, changing paddle sizes ...).
This is a single person game however scores may be kept for multiple players.

## Game Structure

The game was written in C++ using SDL (Simple DirectMedia Layer) libraries.  Appropriate SDL2 libraries will need to be installed, included and linked to the project file prior to editing.  [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php) 
[https://www.libsdl.org/projects/SDL_mixer/](https://www.libsdl.org/projects/SDL_mixer/)
SDL_tff is not needed as text was rendered as images.

## Project Flow
Class gameMain solely contains:
    
   	StartGame():
   	PlayGame():
   	EndGame():
Class game calls: 
   
    DrawGame(): TrelGraphics2 & TrelTexture    
    Player():
    Level ():  
    PowerUps(): Contraception Facts, Attribute changes 
    GameObjects(): Paddle, Ball, Brick and their attributes
    HandleEvent():
    GameStateUpdate():
    GameOver():
    
 

## Copyright/License Agreement
Copyright 2020, Front Range Community College

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License, or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

