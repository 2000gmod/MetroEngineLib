#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <math.h>

struct Vector2{
    
    double x;
    double y;
    Vector2(double x_init, double y_init);
    Vector2();
    
    Vector2 operator + (const Vector2&);
    Vector2 operator - (const Vector2&);
    Vector2 operator * (const float&);
    Vector2 operator / (const float&);
    void operator = (const Vector2&);
    bool operator == (const Vector2&);
    float dot(Vector2* vec1);
    float magnitude();
    void normalize();
};

void swapVector2(Vector2* a, Vector2* b);


#endif