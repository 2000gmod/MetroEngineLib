#include "shapes.hpp"

Poly::Poly(){
    color = WHITE;
}

Poly::Poly(uint32_t color_init, int thick, std::vector<Vector2> vertexList, uint32_t* drawingBuffer){
    color = color_init;
    thickness = thick;
    vertices = vertexList;
    pixelBuffer = drawingBuffer;
}

void Poly::draw(){
    if (vertices.size() <= 1) return;
    Line line(color, thickness, Vector2(0,0), Vector2(0,0), pixelBuffer);
    for (uint64_t i = 0; i < vertices.size() - 1; i++){
        line.p1 = vertices[i];
        line.p2 = vertices[i+1];
        line.draw();
    }
    line.p1 = vertices[0];
    line.draw();
}

void Poly::update_vertices(std::vector<Vector2> vertexList){
    vertices = vertexList;
}

void Poly::update_color(uint32_t new_color){
    color = new_color;
}

void Poly::moveByVector(Vector2 move){
    for (Vector2 vert : vertices){
        vert = vert + move;
    }
}
