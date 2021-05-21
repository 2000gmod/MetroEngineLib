#include "vectors.hpp"

Vector2 Vector2::operator + (const Vector2& vecIn){
    Vector2 vec(0, 0);
    vec.x = this->x + vecIn.x;
    vec.y = this->y + vecIn.y;
    return vec;
}
Vector2 Vector2::operator - (const Vector2& vecIn){
    Vector2 vec(0, 0);
    vec.x = this->x - vecIn.x;
    vec.y = this->y - vecIn.y;
    return vec;
}
Vector2 Vector2::operator * (const float& num){
    Vector2 vec(0, 0);
    vec.x = this->x * num;
    vec.y = this->y * num;
    return vec;
}
Vector2 Vector2::operator / (const float& num){
    Vector2 vec(0, 0);
    vec.x = this->x / num;
    vec.y = this->y / num;
    return vec;
}

float Vector2::dot(Vector2* vec1){
    float out = vec1->x * x + vec1->y + y;
    return out;
}

void Vector2::operator = (const Vector2& vecIn){
    x = vecIn.x;
    y = vecIn.y;
    return;
}
Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(double x_init, double y_init){
    x = x_init;
    y = y_init;
}

float Vector2::magnitude(){
    return sqrt(x*x + y*y);
}

void Vector2::normalize(){
    x *= 1/magnitude();
    y *= 1/magnitude();
}

void swapVector2(Vector2* a, Vector2* b){
    Vector2 temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}