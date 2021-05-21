#ifndef ENGINEH_HPP
#define ENGINEH_HPP

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

#define WIDTH                   960
#define HEIGHT                  540

#define FRAMERATE               60

#define PI                      3.1415

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

extern uint32_t pixel_array[WIDTH*HEIGHT];

#endif