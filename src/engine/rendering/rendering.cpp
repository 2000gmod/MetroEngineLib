#include "rendering.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

extern int ME_Width;
extern int ME_Height;

uint32_t *screenArray;

Clock::Clock(){
    deltaTime = 0;
    lastTime = 0;
    totalTime = 0;
}

void Clock::Tick(){
    uint32_t time = SDL_GetTicks();
    deltaTime = time - lastTime;
    lastTime = time;
    totalTime += deltaTime;
}

void clearScreen(uint32_t* pixelBuffer){
    for(int k = 0; k <= ME_Width * ME_Height; k++){
        pixelBuffer[k] = 0;
    }
}

void drawPixel(uint32_t* pixelBuffer, Vector2 pos, uint32_t colour){
    if(pos.x < 0 || pos.x >= ME_Width || pos.y < 0 || pos.y >= ME_Height){
        return;
    }

    uint32_t newAlpha = colour & 0x000000FF;
    if(newAlpha == 0) return;
    else if(newAlpha < 255) {

        double alphaFraction = (double) newAlpha / 0xFF;
        colour += (0xFF - newAlpha);

        uint32_t oldColor = pixelBuffer[(int)round(pos.y)*ME_Width + (int)round(pos.x)];
        uint32_t oldAlpha = oldColor & 0x000000FF;
        oldColor += (0xFF - oldAlpha);

        

        colour = alphaFraction * colour + (1 - alphaFraction) * oldColor;
        newAlpha = colour & 0x000000FF;
        colour += (0xFF - newAlpha);
    }

    pixelBuffer[(int)round(pos.y)*ME_Width + (int)round(pos.x)] = colour;
    return;
}

void drawPixelSize(uint32_t* pixelBuffer, Vector2 pos, uint32_t colour, double size){
    if(fabs(size - 1) < 0.1f) drawPixel(pixelBuffer, pos, colour);
    if (size < 0.1f) return;

    for(int i = (-size/2); i <= size/2; i++){
        for(int j = (-size/2); j <= size/2; j++){
            drawPixel(pixelBuffer, pos + Vector2(i, j), colour);
        }
    }
    return;
}