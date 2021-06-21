#include "shapes.hpp"

DrawableCollection::DrawableCollection(){
    shapes = {};
}

DrawableCollection::DrawableCollection(std::vector<Drawable*> shapesVector){
    shapes = shapesVector;
}

void DrawableCollection::draw(){
    for(Drawable* shape : shapes) shape->draw();
}

Drawable* DrawableCollection::operator [] (int& index){
    return shapes[index];
}