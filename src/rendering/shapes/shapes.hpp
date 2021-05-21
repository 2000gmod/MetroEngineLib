#ifndef SHAPES_H
#define SHAPES_H

#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include "../vectors.hpp"
#include "../rendering.hpp"

class Line{
    public:
        uint32_t color;
        vector2 p1;
        vector2 p2;
        int thickness;
        uint32_t* pixelBuffer;

        Line();
        Line(uint32_t color_init, int thick, vector2 point_1, vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(vector2 point_1, vector2 point_2);
        void update_color(uint32_t new_color);
};

class Rectangle{
    public:
        uint32_t color;
        vector2 p1;
        vector2 p2;
        uint32_t* pixelBuffer;

        Rectangle();
        Rectangle(uint32_t color_init, vector2 point_1, vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(vector2 point_1, vector2 point_2);
        void update_color(uint32_t new_color);
};

class Circle{
    public:
        uint32_t color;
        vector2 p1;
        double radius;
        int thickness;
        uint32_t* pixelBuffer;

        Circle();
        Circle(uint32_t color_init,int thick, vector2 point_1, double r, uint32_t* drawingBuffer);
        Circle(uint32_t color_init,int thick, vector2 point_1, vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(vector2 point_1);
        void update_color(uint32_t new_color);
};

class Poly{
    public:
        uint32_t color;
        std::vector<vector2> vertices;
        int thickness;
        uint32_t* pixelBuffer;

        Poly();
        Poly(uint32_t color_init, int thick,std::vector<vector2> vertexList, uint32_t* drawingBuffer);

        void draw();
        void update_vertices(std::vector<vector2> vertexList);
        void update_color(uint32_t new_color);
        void moveByVector(vector2 move);
};

class PolyObject{
    public:
        std::vector<Poly> objects;

        PolyObject(std::vector<Poly> objectList);
        
        void draw();
        void updateObjects(std::vector<Poly> objectList);
        void moveByVector(vector2 move);
};


#endif