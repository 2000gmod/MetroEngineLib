#include "rendering.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

extern const int ME_Width;
extern const int ME_Height;

uint32_t *pixel_array = new uint32_t[ME_Height*ME_Width]; 

Clock::Clock(){
    deltaTime = 0;
    lastTime = 0;
}

void Clock::Tick(){
    uint32_t time = SDL_GetTicks();
    deltaTime = time - lastTime;
    lastTime = time;
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
    //if (!(pixelBuffer[(int)round(pos.y)*ME_Width + (int)round(pos.x)] ^ colour)) return;
    pixelBuffer[(int)round(pos.y)*ME_Width + (int)round(pos.x)] = colour;
    return;
}

void drawPixelSize(uint32_t* pixelBuffer, Vector2 pos, uint32_t colour, double size){
    if(fabs(size - 1) < 0.1f) drawPixel(pixelBuffer, pos, colour);
    if (size < 0.1f) return;
    if(pos.x < 0 || pos.x >= ME_Width - size || pos.y < 0 || pos.y >= ME_Height - size){
        return;
    }
    for(int i = (-size/2); i <= size/2; i++){
        for(int j = (-size/2); j <= size/2; j++){
            drawPixel(pixelBuffer, pos + Vector2(i, j), colour);
        }
    }
    return;
}

void drawCircle(uint32_t* pixelBuffer, Vector2 pos, double radius, uint32_t colour, int thickness){
    Vector2 pixel(0, 0);
    for(float t = 0.0f; t < 2*PI; t += 0.00390625f/2){
        pixel.x = (int) round(radius*cos(t) + pos.x);
        pixel.y = (int) round(radius*sin(t) + pos.y);
        drawPixelSize(pixelBuffer, pixel, colour, thickness);
    }
    return;
}

void drawLine(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour, int thickness){
    Vector2 drawing(0, 0);
    if(p1.x > p2.x) swapVector2(&p1, &p2);

    if(p1.x == p2.x){
        drawing.x = p1.x;
        if(p1.y > p2.y){
            int temp = p2.y;
            p2.y = p1.y;
            p1.y = temp;
        }
        for(int k = p1.y; k<= p2.y; k++){
            drawing.y = k;
            drawPixelSize(pixelBuffer, drawing, colour, thickness);
        }
        return;
    }
    float slope = (float) (p2.y - p1.y)/(p2.x - p1.x);

    float axisCol = (float) p1.y - slope*p1.x;
    for(int k = p1.x; k < p2.x; k++){
        drawing.x = k;
        drawing.y = k*slope + axisCol;
        for(int j = 0; j <= fabs(slope); j++){
            drawPixelSize(pixelBuffer, drawing, colour, thickness);
            if(slope < 0) drawing.y -= 1;
            else drawing.y +=1;
        }
    }
    return;
}

void drawRectangle(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour){
    Vector2 p3(0, 0);
    Vector2 p4(0, 0);

    p3.x = p2.x;
    p3.y = p1.y;
    
    p4.x = p1.x;
    p4.y = p2.y;

    drawLine(pixelBuffer, p1, p3, colour, 1);
    drawLine(pixelBuffer, p1, p4, colour, 1);

    drawLine(pixelBuffer, p2, p3, colour, 1);
    drawLine(pixelBuffer, p2, p4, colour, 1);
    return;
}

void drawQuad(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, uint32_t colour){
    drawLine(pixelBuffer, p1, p2, colour, 1);
    drawLine(pixelBuffer, p2, p3, colour, 1);

    drawLine(pixelBuffer, p3, p4, colour, 1);
    drawLine(pixelBuffer, p4, p1, colour, 1);
    return;
}

void drawFilledRect(uint32_t* pixelBuffer, Vector2 p1, Vector2 p2, uint32_t colour){
    if(p1.x == p2.x || p1.y == p2.y) return;
    if(p1.y < p2.y) swapVector2(&p1, &p2);

    Vector2 draw1(0, 0), draw2(0, 0);
    *(&draw1) = *(&p1);
    draw2.y = p1.y;
    draw2.x = p2.x;

    for(int k = 0; k < p1.y - p2.y; k++){
        draw1.y += 1;
        draw2.y += 1;
        drawLine(pixelBuffer, draw1, draw2, colour, 1);
    }
    return;
}
