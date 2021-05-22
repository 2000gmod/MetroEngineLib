#include "shapes.hpp"

Line::Line(){
    Vector2 p1(0, 0);
    Vector2 p2(ME_Width, ME_Height);
    color = RED;
    return;
}

Line::Line(uint32_t color_init, int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer){
    color = color_init;
    thickness = thick;
    p1 = point_1;
    p2 = point_2;
    pixelBuffer = drawingBuffer;
    return;
}

void Line::draw(){
    if (p1 == p2) return;
    drawLine(pixelBuffer, p1, p2, color, thickness);
    return;
}

void Line::update_position(Vector2 point_1, Vector2 point_2){
    p1 = point_1;
    p2 = point_2;
    return;
}

void Line::update_color(uint32_t new_color){
    color = new_color;
}

bool Line::isOnSameSide(Vector2 a, Vector2 b){
    /*
    * d = (x - p1.x)*(p2.y-p1.y) - (y - p1.y)*(p2.x - p1.x)
    */

   double dVectorA = (a.x - p1.x)*(p2.y-p1.y) - (a.y - p1.y)*(p2.x - p1.x);
   double dVectorB = (b.x - p1.x)*(p2.y-p1.y) - (b.y - p1.y)*(p2.x - p1.x);

   if(dVectorA*dVectorB < 0) return true;
   else return false;
}