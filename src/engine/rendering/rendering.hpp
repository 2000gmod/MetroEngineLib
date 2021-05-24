#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>
#include <math.h>
#include "vectors.hpp"
#include "../engine.hpp"


class Clock{
    public:
        uint32_t deltaTime;
        uint32_t lastTime;
        __uint128_t totalTime;
        Clock();
        void Tick();
};

void clearScreen(uint32_t* pixelBuffer);
void drawPixel(uint32_t* pixelBuffer, Vector2 pos, uint32_t colour);
void drawPixelSize(uint32_t* pixelBuffer, Vector2 pos, uint32_t colour, double size);

void drawCircle(uint32_t* pixelBuffer, Vector2 pos, double radius, uint32_t colour, int thickness);
void drawLine(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour, int thickness);

void drawRectangle(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour);
void drawQuad(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, uint32_t colour);

void drawFilledRect(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour);


#endif