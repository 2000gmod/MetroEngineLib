#ifndef SHAPES_H
#define SHAPES_H

#include <SDL2/SDL.h>
#include <math.h>
#include <vector>

#include "vectors.hpp"
#include "rendering.hpp"
#include "color.hpp"

#define FULL 1
#define EMPTY 0


extern int ME_Width;
extern int ME_Height;

class Drawable{
    public:
        virtual void draw() = 0;
        virtual ~Drawable() = default;

};

class DrawableCollection : public Drawable{
    public:
        DrawableCollection();
        DrawableCollection(std::vector<Drawable*> shapesVector);

        void draw() override;

        std::vector<Drawable*> shapes;
};

typedef DrawableCollection Scene;

class Line : public Drawable{
    public:
        uint32_t color;
        Vector2 p1;
        Vector2 p2;
        int thickness;
        uint32_t* pixelBuffer;

        Line();
        Line(uint32_t color_init, int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw() override;
        void update_position(Vector2 point_1, Vector2 point_2);
        void update_color(uint32_t new_color);
        bool isOnSameSide(Vector2 a, Vector2 b);
        Vector2 getIntersection(Vector2 a, Vector2 b);
};

class Rectangle : public Drawable{
    public:
        uint32_t color;
        Vector2 p1;
        Vector2 p2;
        uint32_t* pixelBuffer;

        Rectangle();
        Rectangle(uint32_t color_init, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw() override;
        void update_position(Vector2 point_1, Vector2 point_2);
        void update_color(uint32_t new_color);
};

class Circle : public Drawable{
    public:
        uint32_t color;
        Vector2 p1;
        double radius;
        int thickness;
        uint32_t* pixelBuffer;

        Circle();
        Circle(uint32_t color_init,int thick, Vector2 point_1, double r, uint32_t* drawingBuffer);
        Circle(uint32_t color_init,int thick, Vector2 point_1, Vector2 point_2, uint32_t* drawingBuffer);

        void draw() override;
        void update_position(Vector2 point_1);
        void update_color(uint32_t new_color);
};

class Poly : public Drawable{
    public:
        uint32_t color;
        uint32_t fillColor;
        std::vector<Vector2> vertices;
        int thickness;
        bool full;
        uint32_t* pixelBuffer;

        Poly();
        Poly(uint32_t color_init, int thick, bool paintedInside,std::vector<Vector2> vertexList, uint32_t* drawingBuffer);
        Poly(uint32_t color_init, uint32_t fill_color_init, int thick, bool paintedInside, std::vector<Vector2> vertexList, uint32_t* drawingBuffer);

        void draw() override;
        void update_vertices(std::vector<Vector2> vertexList);
        void update_color(uint32_t new_color_outline, uint32_t new_color_fill);
        void moveByVector(Vector2 move);
        bool isInside(Vector2 point);

    private:
        int minX = 0; 
        int maxX = 0; 
        int minY = 0;
        int maxY = 0;
        void updateMinMax();
};

class PolyObject : public Drawable{
    public:
        std::vector<Poly> objects;

        PolyObject(std::vector<Poly> objectList);
        
        void draw() override;
        void updateObjects(std::vector<Poly> objectList);
        void moveByVector(Vector2 move);
};

#endif