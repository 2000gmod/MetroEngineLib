#ifndef INIT_HPP
#define INIT_HPP

#include <SDL2/SDL.h>
#include "rendering.hpp"
#include <string>


void initWindow(std::string windowTitle, bool fullscreen);
void updateFrame();

#endif