#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <math.h>

class vector2{
    public:
        double x;
        double y;
        vector2(double x_init, double y_init);
        vector2();
        
        vector2 operator + (const vector2&);
        vector2 operator - (const vector2&);
        vector2 operator * (const float&);
        vector2 operator / (const float&);
        void operator = (const vector2&);
        float dot(vector2* vec1);
        float magnitude();
        void normalize();
};

void swapVector2(vector2* a, vector2* b);


#endif