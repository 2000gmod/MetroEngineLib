#include "gravity.hpp"

GravitySim::GravitySim(int numPlanets){
    this->numPlanets = numPlanets;
}

void GravitySim::generate(){
    planets.clear();
    for (int i = 0; i < numPlanets; i++){
        u_int32_t genColor = getColor((int) 155*randomNum() + 100, (int) 155*randomNum() + 100, (int) 155*randomNum() + 100); 
        Planet planet(Circle(genColor, 1, Vector2(ME_Width*randomNum(), ME_Height*randomNum()), 1, screenArray), Vector2(0, 0), 5);
        planets.push_back(planet);
    }
}

void GravitySim::draw(){
    for (Planet& planet : planets) planet.draw();
}

void GravitySim::step(){
    float gravityC = 1;

    for (unsigned int i = 0; i < planets.size(); i++){
        Planet& planetToUpdate = planets[i];
        Vector2 gravAcc;
        //update acc
        for (unsigned int j = 0; j < planets.size(); j++){
            Planet& otherPlanet = planets[j];
            if (&planetToUpdate == &otherPlanet) continue;

            float dist = (planetToUpdate.circle.p1 - otherPlanet.circle.p1).magnitude();

            if (dist < planetToUpdate.circle.radius + otherPlanet.circle.radius) {
                float totalMass = planetToUpdate.mass + otherPlanet.mass;
                Vector2 totalMomentum = planetToUpdate.speed * planetToUpdate.mass + otherPlanet.speed * otherPlanet.mass;
                Vector2 totalVel = totalMomentum / totalMass;
                planetToUpdate.speed = totalVel;

                planetToUpdate.circle.radius *= sqrt(totalMass / planetToUpdate.mass); 
                planetToUpdate.mass = totalMass;

                planetToUpdate.circle.p1 = (planetToUpdate.circle.p1 * (planetToUpdate.mass / totalMass) + otherPlanet.circle.p1 * (otherPlanet.mass / totalMass));

                planets.erase(planets.begin() + j);
                continue;
            }
            gravAcc = gravAcc + (otherPlanet.circle.p1 - planetToUpdate.circle.p1) * ((otherPlanet.mass)/(dist * dist));
        }
        gravAcc = gravAcc * gravityC;
        planetToUpdate.speed = planetToUpdate.speed + gravAcc;
        //planetToUpdate.speed = planetToUpdate.speed * 0.85;

        planetToUpdate.circle.p1 =  (planetToUpdate.speed * ((float) 1 / (FRAMERATE * 100))) + planetToUpdate.circle.p1;
    }

}