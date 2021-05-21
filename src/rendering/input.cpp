#include "input.hpp"

void updateMouse(vector2* mouse){
    int x, y;
    SDL_GetMouseState(&x, &y);
    mouse->x = x;
    mouse->y = y;
    return;
}