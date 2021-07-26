#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "engine/include/engine.hpp"

class Planet : Drawable {
    public:
        Planet(Circle circle, Vector2 speed, float mass);
        Circle circle;

        Vector2 speed;
        Vector2 gravAcc;

        float mass;

        void draw();

};


class GravitySim : Drawable {
    public:
        GravitySim(int numPlanets);
        void generate();

        void draw();
        void step();

        static inline double randomNum() {return (double) rand() / RAND_MAX;}

    private:
        int numPlanets;
        std::vector<Planet> planets;
};


#endif