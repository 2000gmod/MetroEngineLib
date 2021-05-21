#include "vectors.hpp"

vector2 vector2::operator + (const vector2& vecIn){
    vector2 vec(0, 0);
    vec.x = this->x + vecIn.x;
    vec.y = this->y + vecIn.y;
    return vec;
}
vector2 vector2::operator - (const vector2& vecIn){
    vector2 vec(0, 0);
    vec.x = this->x - vecIn.x;
    vec.y = this->y - vecIn.y;
    return vec;
}
vector2 vector2::operator * (const float& num){
    vector2 vec(0, 0);
    vec.x = this->x * num;
    vec.y = this->y * num;
    return vec;
}
vector2 vector2::operator / (const float& num){
    vector2 vec(0, 0);
    vec.x = this->x / num;
    vec.y = this->y / num;
    return vec;
}

float vector2::dot(vector2* vec1){
    float out = vec1->x * x + vec1->y + y;
    return out;
}

void vector2::operator = (const vector2& vecIn){
    x = vecIn.x;
    y = vecIn.y;
    return;
}
vector2::vector2(){
    x = 0;
    y = 0;
}

vector2::vector2(double x_init, double y_init){
    x = x_init;
    y = y_init;
}

float vector2::magnitude(){
    return sqrt(x*x + y*y);
}

void vector2::normalize(){
    x *= 1/magnitude();
    y *= 1/magnitude();
}

void swapVector2(vector2* a, vector2* b){
    vector2 temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}