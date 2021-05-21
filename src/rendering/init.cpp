#include "init.hpp"

extern uint32_t pixel_array[WIDTH*HEIGHT];

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* screen;

void initWindow(std::string windowTitle){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(windowTitle.c_str(), 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    return;
}

void updateFrame(){
    SDL_UpdateTexture(screen, NULL, pixel_array, WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    SDL_RenderPresent(renderer);
}