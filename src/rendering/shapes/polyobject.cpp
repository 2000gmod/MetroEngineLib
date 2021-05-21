#include "shapes.hpp"

/*
class PolyObject{
    public:
        std::vector<Poly> objects;

        PolyObject(std::vector<Poly> objectList);
        
        void draw();
        void updateObjects(std::vector<Poly> objectList);
        void moveByVector(vector2 move);
};*/

PolyObject::PolyObject(std::vector<Poly> objectList){
    objects = objectList;
}

void PolyObject::draw(){
    for (Poly poly : objects){
        poly.draw();
    }
}

void PolyObject::updateObjects(std::vector<Poly> objectList){
    objects = objectList;
}

void PolyObject::moveByVector(vector2 move){
    for (Poly poly : objects){
        poly.moveByVector(move);
    }
}
