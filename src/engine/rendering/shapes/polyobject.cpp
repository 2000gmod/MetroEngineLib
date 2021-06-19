#include "shapes.hpp"

/*
class PolyObject{
    public:
        std::vector<Poly> objects;

        PolyObject(std::vector<Poly> objectList);
        
        void draw();
        void updateObjects(std::vector<Poly> objectList);
        void moveByVector(Vector2 move);
};*/

PolyObject::PolyObject(std::vector<Poly> objectList){
    objects = objectList;
}

void PolyObject::draw(){
    for(uint64_t i = 0; i < objects.size(); i++){
        objects[i].draw();
    }
}

void PolyObject::updateObjects(std::vector<Poly> objectList){
    objects = objectList;
}

void PolyObject::moveByVector(Vector2 move){
    for (Poly poly : objects){
        poly.moveByVector(move);
    }
}
