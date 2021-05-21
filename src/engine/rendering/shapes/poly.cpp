#include "shapes.hpp"

Poly::Poly(){
    color = WHITE;
}

Poly::Poly(uint32_t color_init, int thick, bool paintedInside, std::vector<Vector2> vertexList, uint32_t* drawingBuffer){
    color = color_init;
    fillColor = color_init;
    thickness = thick;
    full = paintedInside;
    vertices = vertexList;
    pixelBuffer = drawingBuffer;
    updateMinMax();
}

Poly::Poly(uint32_t color_init, uint32_t fill_color_init, int thick, bool paintedInside,std::vector<Vector2> vertexList, uint32_t* drawingBuffer){
    color = color_init;
    fillColor = fill_color_init;
    thickness = thick;
    full = paintedInside;
    vertices = vertexList;
    pixelBuffer = drawingBuffer;
    updateMinMax();
}

void Poly::draw(){
    if (vertices.size() <= 2) return;

    if(full){
        std::vector<Line> edges;
        for (uint64_t v = 0; v < vertices.size() - 1; v++){
            edges.push_back(Line(WHITE, 1, vertices[v], vertices[v+1], NULL));
        }
        edges.push_back(Line(WHITE, 1, vertices.back(), vertices.front(), NULL));

        for(int curY = minY; curY <= maxY; curY++){
            std::vector<Vector2> intersections;
            bool drawEnabled = true;
            for(Line line : edges){
                if((line.p1.y < curY && line.p2.y < curY) || (line.p1.y >= curY && line.p2.y >= curY)) continue;
                intersections.push_back(Vector2(((curY - line.p1.y)*(line.p1.x - line.p2.x))/(line.p1.y - line.p2.y) + line.p1.x, curY));
                drawEnabled = !drawEnabled;
                if (drawEnabled){
                    Line drawer(fillColor, 1, intersections.back(), Vector2(0,0), pixelBuffer);
                    intersections.pop_back();
                    drawer.p2 = intersections.back();
                    intersections.pop_back();
                    drawer.draw();
                }
            }
        }
    }

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
    updateMinMax();
}

void Poly::update_color(uint32_t new_color, uint32_t new_color_fill){
    color = new_color;
    fillColor = new_color_fill;
}

void Poly::moveByVector(Vector2 move){
    for (Vector2 vert : vertices){
        vert = vert + move;
    }
    updateMinMax();
}
bool Poly::isInside(Vector2 point){
    std::vector<Line> edges;
    int collisions = 0;

    for (uint64_t v = 0; v < vertices.size() - 1; v++){
        edges.push_back(Line(WHITE, 1, vertices[v], vertices[v+1], NULL));
    }
    edges.push_back(Line(WHITE, 1, vertices.back(), vertices.front(), NULL));

    for(int i = (int) round(point.x); i <= maxX; i++){
        Vector2 pointA = point;
        Vector2 pointB(point.x + 1, point.y);
        for (Line edge : edges){
            if (!edge.isOnSameSide(pointA, pointB)) collisions++;
        }
        pointA.x++;
        pointB.x++;
    }
    if(collisions % 2 != 0) return true;
    else return false;
}

void Poly::updateMinMax(){
    for(uint32_t i = 0; i < vertices.size(); i++){
        if(vertices[i].x < minX) minX   =   (int) round(vertices[i].x);
        if(vertices[i].x >= maxX) maxX  =   (int) round(vertices[i].x);
        if(vertices[i].y < minY) minY   =   (int) round(vertices[i].y);
        if(vertices[i].y >= maxY) maxY  =   (int) round(vertices[i].y);
    }
}