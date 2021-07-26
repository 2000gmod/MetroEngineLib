#include "gravity.hpp"

Planet::Planet(Circle circle, Vector2 speed, float mass){
    this->circle = circle;
    this->speed = speed;
    this-> mass = mass;
}

void Planet::draw(){
    circle.draw();
}