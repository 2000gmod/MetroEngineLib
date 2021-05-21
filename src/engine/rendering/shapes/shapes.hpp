#ifndef SHAPES_H
#define SHAPES_H

#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include "../vectors.hpp"
#include "../rendering.hpp"

#define FULL 1
#define EMPTY 0

class Line{
    public:
        uint32_t color;
        Vector2 p1;
        Vector2 p2;
        int thickness;
        uint32_t* pixelBuffer;

        Line();
        Line(uint32_t color_init, int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(Vector2 point_1, Vector2 point_2);
        void update_color(uint32_t new_color);
        bool isOnSameSide(Vector2 a, Vector2 b);
};

class Rectangle{
    public:
        uint32_t color;
        Vector2 p1;
        Vector2 p2;
        uint32_t* pixelBuffer;

        Rectangle();
        Rectangle(uint32_t color_init, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(Vector2 point_1, Vector2 point_2);
        void update_color(uint32_t new_color);
};

class Circle{
    public:
        uint32_t color;
        Vector2 p1;
        double radius;
        int thickness;
        uint32_t* pixelBuffer;

        Circle();
        Circle(uint32_t color_init,int thick, Vector2 point_1, double r, uint32_t* drawingBuffer);
        Circle(uint32_t color_init,int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw();
        void update_position(Vector2 point_1);
        void update_color(uint32_t new_color);
};

class Poly{
    public:
        uint32_t color;
        uint32_t fillColor;
        std::vector<Vector2> vertices;
        int thickness;
        bool full;
        uint32_t* pixelBuffer;

        Poly();
        Poly(uint32_t color_init, int thick, bool paintedInside,std::vector<Vector2> vertexList, uint32_t* drawingBuffer);
        Poly(uint32_t color_init, uint32_t fill_color_init, int thick, bool paintedInside,std::vector<Vector2> vertexList, uint32_t* drawingBuffer);

        void draw();
        void update_vertices(std::vector<Vector2> vertexList);
        void update_color(uint32_t new_color);
        void moveByVector(Vector2 move);
        bool isInside(Vector2 point);

    private:
        int minX; 
        int maxX; 
        int minY;
        int maxY;
        void updateMinMax();
};

class PolyObject{
    public:
        std::vector<Poly> objects;

        PolyObject(std::vector<Poly> objectList);
        
        void draw();
        void updateObjects(std::vector<Poly> objectList);
        void moveByVector(Vector2 move);
};


#endif