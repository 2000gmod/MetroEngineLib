#include "shapes.hpp"

Rectangle::Rectangle(){
    Vector2 p1(10, 10);
    Vector2 p2(WIDTH/2, HEIGHT/2);
    color = RED;
    return;
}

Rectangle::Rectangle(uint32_t color_init, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer){
    color = color_init;
    p1 = point_1;
    p2 = point_2;
    pixelBuffer = drawingBuffer;
    return;
}

void Rectangle::draw(){
    drawRectangle(pixelBuffer, p1, p2, color);
    return;
}

void Rectangle::update_position(Vector2 point_1, Vector2 point_2){
    p1 = point_1;
    p2 = point_2;
    return;
}

void Rectangle::update_color(uint32_t new_color){
    color = new_color;
}