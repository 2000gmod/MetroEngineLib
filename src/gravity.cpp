#include "gravity.hpp"

GravitySim::GravitySim(int numPlanets){
    this->numPlanets = numPlanets;
}

void GravitySim::generate(){
    for (int i = 0; i < numPlanets; i++){
        u_int32_t genColor = getColor((int) 155*randomNum() + 100, (int) 155*randomNum() + 100, (int) 155*randomNum() + 100); 
        Planet planet(Circle(genColor, 1, Vector2(ME_Height*randomNum(), ME_Height*randomNum()), 5, screenArray), Vector2(2 * randomNum() - 1, 2 * randomNum() - 1), 5);
        planets.push_back(planet);
    }
}

void GravitySim::draw(){
    for (Planet& planet : planets) planet.draw();
}

void GravitySim::step(){
    float gravityC = 1.0;
    for (Planet& planetToUpdate : planets){
        planetToUpdate.gravAcc = Vector2(0, 0);
        //update acc
        for (Planet& otherPlanet : planets){
            if (&planetToUpdate == &otherPlanet) continue;

            float dist = (planetToUpdate.circle.p1 - otherPlanet.circle.p1).magnitude();

            planetToUpdate.gravAcc = planetToUpdate.gravAcc + (otherPlanet.circle.p1 - planetToUpdate.circle.p1) * ((otherPlanet.mass)/(dist * dist));
        }
        planetToUpdate.gravAcc = planetToUpdate.gravAcc * gravityC;

        planetToUpdate.speed = planetToUpdate.speed + planetToUpdate.gravAcc;

        planetToUpdate.circle.p1 =  (planetToUpdate.speed * ((float) 1 / FRAMERATE)) + planetToUpdate.circle.p1;
    }

}