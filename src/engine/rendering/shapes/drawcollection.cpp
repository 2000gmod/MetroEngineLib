#include "shapes.hpp"

DrawableCollection::DrawableCollection(){
    shapes = {};
}

DrawableCollection::DrawableCollection(std::vector<Drawable*> shapesVector){
    shapes = shapesVector;
}

void DrawableCollection::draw(){
    for(Drawable* element : shapes){
        element->draw();
    }
}
