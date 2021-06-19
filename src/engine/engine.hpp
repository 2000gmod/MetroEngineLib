#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "rendering/rendering.hpp"
#include "rendering/vectors.hpp"
#include "rendering/shapes/shapes.hpp"
#include "rendering/input.hpp"
#include "rendering/init.hpp"
#include "rendering/text/text.hpp"
#include "rendering/color.hpp"


#define FRAMERATE               60

#define PI                      3.1415

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

extern SDL_AudioDeviceID deviceID;

extern SDL_AudioSpec wavSpec;
extern Uint32 wavLength;
extern Uint8 *wavBuffer; 

extern uint32_t *screenArray;

#endif