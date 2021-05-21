#include "shapes.hpp"

Line::Line(){
    vector2 p1(0, 0);
    vector2 p2(WIDTH, HEIGHT);
    color = RED;
    return;
}

Line::Line(uint32_t color_init, int thick, vector2 point_1, vector2 point_2, uint32_t* drawingBuffer){
    color = color_init;
    thickness = thick;
    p1 = point_1;
    p2 = point_2;
    pixelBuffer = drawingBuffer;
    return;
}

void Line::draw(){
    drawLine(pixelBuffer, p1, p2, color, thickness);
    return;
}

void Line::update_position(vector2 point_1, vector2 point_2){
    p1 = point_1;
    p2 = point_2;
    return;
}

void Line::update_color(uint32_t new_color){
    color = new_color;
}
