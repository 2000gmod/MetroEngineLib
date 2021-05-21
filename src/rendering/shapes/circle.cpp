#include "shapes.hpp"

Circle::Circle(){
    vector2 p1(30, 30);
    radius = 30;
    color = RED;
    return;
}

Circle::Circle(uint32_t color_init, int thick, vector2 point_1, double r, uint32_t* drawingBuffer){
    p1 = point_1;
    radius = r;
    color = color_init;
    pixelBuffer = drawingBuffer;
    thickness = thick;
}

Circle::Circle(uint32_t color_init,int thick, vector2 point_1, vector2 point_2, uint32_t* drawingBuffer){
    radius = (int)(point_1 - point_2).magnitude();
    p1 = point_1;
    color = color_init;
    pixelBuffer = drawingBuffer;
    thickness = thick;
}

void Circle::draw(){
    drawCircle(pixelBuffer, p1, radius, color, thickness);
}

void Circle::update_position(vector2 point_1){
    p1 = point_1;
}

void Circle::update_color(uint32_t new_color){
    color = new_color;
}