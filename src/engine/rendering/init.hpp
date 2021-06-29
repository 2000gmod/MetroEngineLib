#ifndef INIT_HPP
#define INIT_HPP

#include <SDL2/SDL.h>
#include "rendering.hpp"
#include "shapes/shapes.hpp"
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>


void initWindow(std::string windowTitle);
void updateFrame();

int applyConfiguration(std::string configFileName);

#endif