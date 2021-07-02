#include "../../include/shapes.hpp"

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
            drawPixelSize(pixelBuffer, drawing, color, thickness);
        }
        return;
    }
    float slope = (float) (p2.y - p1.y)/(p2.x - p1.x);

    float axisCol = (float) p1.y - slope*p1.x;
    for(int k = p1.x; k < p2.x; k++){
        drawing.x = k;
        drawing.y = k*slope + axisCol;
        for(int j = 0; j <= fabs(slope); j++){
            drawPixelSize(pixelBuffer, drawing, color, thickness);
            if(slope < 0) drawing.y -= 1;
            else drawing.y +=1;
        }
    }
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