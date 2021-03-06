#include "../../include/shapes.hpp"

Circle::Circle(){
    Vector2 p1(30, 30);
    radius = 30;
    color = RED;
    return;
}

Circle::Circle(uint32_t color_init, int thick, Vector2 point_1, double r, uint32_t* drawingBuffer){
    p1 = point_1;
    radius = r;
    color = color_init;
    pixelBuffer = drawingBuffer;
    thickness = thick;
}

Circle::Circle(uint32_t color_init,int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer){
    radius = (int)(point_1 - point_2).magnitude();
    p1 = point_1;
    color = color_init;
    pixelBuffer = drawingBuffer;
    thickness = thick;
}

void Circle::draw(){
    Vector2 pixel(0, 0);
    for(float t = 0.0f; t < 2*PI; t += 0.00390625f/2){
        pixel.x = (int) round(radius*cos(t) + p1.x);
        pixel.y = (int) round(radius*sin(t) + p1.y);
        drawPixelSize(pixelBuffer, pixel, color, thickness);
    }
    return;
}

void Circle::update_position(Vector2 point_1){
    p1 = point_1;
}

void Circle::update_color(uint32_t new_color){
    color = new_color;
}