#include "init.hpp"

extern const int ME_Width;
extern const int ME_Height;

extern uint32_t *pixel_array;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* screen;

SDL_AudioDeviceID deviceID;

SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer; 

void initWindow(std::string windowTitle, bool fullscreen){
    SDL_Init(SDL_INIT_EVERYTHING);
    int fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN;
    int normalFlag = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(windowTitle.c_str(), 0, 0, ME_Width, ME_Height, fullscreen ? fullscreenFlag : normalFlag);
    renderer = SDL_CreateRenderer(window, -1, 0);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, ME_Width, ME_Height);

    deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    return;
}

void updateFrame(){
    SDL_UpdateTexture(screen, NULL, pixel_array, ME_Width * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    SDL_RenderPresent(renderer);
}