#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>
#include <math.h>
#include "vectors.hpp"

#define PI                      3.1415


class Clock{
    public:
        uint32_t deltaTime;
        uint32_t lastTime;
        __uint128_t totalTime;
        Clock();
        void Tick();
};

//void clearScreen(uint32_t* pixelBuffer);

void clearScreen(uint32_t* pixelBuffer);
void drawPixel(uint32_t* pixelBuffer, Vector2& pos, uint32_t colour);
void drawPixelSize(uint32_t* pixelBuffer, Vector2& pos, uint32_t colour, double size);



#endif