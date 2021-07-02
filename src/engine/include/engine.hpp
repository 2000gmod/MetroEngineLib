#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "rendering.hpp"
#include "vectors.hpp"
#include "shapes.hpp"
#include "input.hpp"
#include "init.hpp"
#include "text.hpp"
#include "color.hpp"
#include "misc.hpp"

#define FRAMERATE               60


extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

extern SDL_AudioDeviceID deviceID;

extern SDL_AudioSpec wavSpec;
extern Uint32 wavLength;
extern Uint8 *wavBuffer; 

extern uint32_t *screenArray;

#endif