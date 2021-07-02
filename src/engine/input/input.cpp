#include "../include/input.hpp"

void updateMouse(Vector2* mouse){
    int x, y;
    SDL_GetMouseState(&x, &y);
    mouse->x = x;
    mouse->y = y;
    return;
}