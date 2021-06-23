#include "init.hpp"

extern int ME_Width;
extern int ME_Height;

extern uint32_t *screenArray;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* screen;

SDL_AudioDeviceID deviceID;

SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer; 

static bool fullscreen = false;

void initWindow(std::string windowTitle){
    screenArray = new uint32_t[ME_Height*ME_Width]; 
    if(SDL_Init(SDL_INIT_VIDEO) < 0) exit(0);

    int fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN;
    int normalFlag = SDL_WINDOW_SHOWN;

    SDL_CreateWindowAndRenderer(ME_Width, ME_Height, (fullscreen ? fullscreenFlag : normalFlag), &window, &renderer);
    SDL_SetWindowTitle(window, windowTitle.c_str());
    //window = SDL_CreateWindow(windowTitle.c_str(), 0, 0, ME_Width, ME_Height, (fullscreen ? fullscreenFlag : normalFlag));
    //renderer = SDL_CreateRenderer(window, -1, 0);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, ME_Width, ME_Height);

    deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    return;
}

void updateFrame(){
    SDL_UpdateTexture(screen, NULL, screenArray, ME_Width * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    SDL_RenderPresent(renderer);
}

int applyConfiguration(std::string configFileName){
    //FILE* file = fopen(configFileName.c_str(), "r");
    //if (file == NULL) return 0;
    std::ifstream file(configFileName);


    std::string toCompare;
    std::string delimiter("=");

    while (getline(file, toCompare).good()){
        
        std::string tokenData = toCompare.substr(0, toCompare.find(delimiter));
        std::string token = toCompare.substr(toCompare.find(delimiter) + delimiter.length(), toCompare.find(delimiter));
        
        tokenData.erase(std::remove_if(tokenData.begin(), tokenData.end(), isspace), tokenData.end());
        
        if(token == toCompare) continue;
        token.erase(0, 1);
        
        if (tokenData == "width"){
            ME_Width = stoi(token);
        }
        if (tokenData == "height"){
            ME_Height = stoi(token);
        }
        if (tokenData == "fullscreen"){
            if (token == "true") fullscreen = true;
            else if (token == "false") fullscreen = false;
            else {
                std::cerr << "Instruction parsing error\n";
            }
        }
    }
    printf("W: %d, H: %d\n", ME_Width, ME_Height);
    //printf("\n");

    return 1;
}

