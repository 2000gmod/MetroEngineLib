#include "shapes.hpp"

Rectangle::Rectangle(){
    Vector2 p1(10, 10);
    Vector2 p2(ME_Width/2, ME_Height/2);
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
    Vector2 p3(0, 0);
    Vector2 p4(0, 0);

    p3.x = p2.x;
    p3.y = p1.y;
    
    p4.x = p1.x;
    p4.y = p2.y;

    Line(color, 1, p1, p3, pixelBuffer).draw();
    Line(color, 1, p1, p4, pixelBuffer).draw();

    Line(color, 1, p2, p3, pixelBuffer).draw();
    Line(color, 1, p2, p4, pixelBuffer).draw();
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