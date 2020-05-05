#pragma once

// Created By Trel Johnson

// This ordering is important to make sure things that need other things happen in the right order.
// Driver exists to make sure everything is loaded.

#include <SDL.h>
#include "GameObject.h"
#include "Ball.h"
#include "Brick.h"
#include "Level.h"
#include "Paddle.h"
#include "GraphicsMethods.h"

//#include "SDL_Mixer.h"