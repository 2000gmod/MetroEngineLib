#include "engine/include/engine.hpp"

#include "gravity.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

int ME_Width = 960;
int ME_Height = 540;

int main(){
    if (! applyConfiguration("config/meconfig.cfg")) return 2;
    initWindow("MetroEngine Demo1");
    srand(time(0));

    Clock clock;
    uint32_t targetDelay = 1000/FRAMERATE;

    //playIntroAnimation(screenArray);

    Vector2 vec_mouse_coords(ME_Width/2, ME_Height/2);

    Vector2 vecScreenCenter(ME_Width/2, ME_Height/2);
    Vector2 vec_corner_UL(0,0);
    Vector2 vec_corner_UR(0, ME_Width);
    Vector2 vec_corner_LL(0, ME_Height);
    Vector2 vec_corner_LR(ME_Width, ME_Height);

    //SDL_LoadWAV("audio/Tetris.wav", &wavSpec, &wavBuffer, &wavLength);
    //SDL_QueueAudio(deviceID, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceID, 0);

    GravitySim sim1(50);
    sim1.generate();

    //GAMELOOP
    //SDL_Delay(500);
    while(1){
        //EVENTS
        
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    printf("Event: External exit request.\n");
                    goto exit;
                case SDL_MOUSEWHEEL:
                    //if(event.wheel.y > 0) printf("Event: Scroll up\n");
                    //if(event.wheel.y < 0) printf("Event: Scroll down\n");
                    break;

                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    printf("Resized!\n");
                    delete screenArray;
                    SDL_GetWindowSize(window, &ME_Width, &ME_Height);
                    screenArray = new uint32_t[ME_Width*ME_Height];
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT){
                        //printf("Left click.\n");
                    }
                    break;
                    
            }
        }
        //KEYBOARD
        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_Q]){
            printf("Event: Internal exit request.\n");
            break;
        }
        //MOUSE
        updateMouse(&vec_mouse_coords);
        
        //DRAWING
        clearScreen(screenArray);

        sim1.step();
        sim1.draw();



        //screen update
        updateFrame();

        clock.Tick();
        if(clock.deltaTime < targetDelay){
            SDL_Delay(targetDelay - clock.deltaTime);
        }
    }
exit:
    SDL_CloseAudioDevice(deviceID);
    SDL_FreeWAV(wavBuffer);

    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("Exiting.\n");

    delete screenArray;

    return 0;
}
