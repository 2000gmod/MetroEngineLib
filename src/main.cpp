#include "engine/engine.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

const int ME_Width = 960;
const int ME_Height = 540;

int main(){
    initWindow("MetroEngine Demo1", false);

    Clock clock;
    uint32_t targetDelay = 1000/FRAMERATE;

    Vector2 vec_mouse_coords(ME_Width/2, ME_Height/2);

    Vector2 vec_screen_center(ME_Width/2, ME_Height/2);
    Vector2 vec_corner_UL(0,0);
    Vector2 vec_corner_UR(0, ME_Width);
    Vector2 vec_corner_LL(0, ME_Height);
    Vector2 vec_corner_LR(ME_Width, ME_Height);

    Text t1("", 1, vec_corner_UL, ORANGE);
    Text t2("test", 1, vec_corner_UL, WHITE);

    Text title("METRO ENGINE DEMO 1", 3, Vector2(vec_screen_center.x - 300 , 0), RED);

    uint32_t metroColor = getColor(255, 0, 0, 255);
    Poly metroRombo1(metroColor, 2, FULL, {Vector2(100,100), Vector2(50,200), Vector2(100,300), Vector2(150,200)}, screenArray);
    Poly metroRombo2(metroColor, 2, FULL, {Vector2(200,100), Vector2(150,200), Vector2(200,300), Vector2(250,200)}, screenArray);
    Poly metroRombo3(metroColor, 2, FULL, {Vector2(300,100), Vector2(250,200), Vector2(300,300), Vector2(350,200)}, screenArray);

    Line line1(WHITE, 2, vec_corner_UL, vec_corner_LR, screenArray);


    PolyObject metroLogo(std::vector<Poly> {metroRombo1, metroRombo2, metroRombo3});

    Poly tri1(getColor(0, 150, 0), getColor(0, 50, 130), 6, FULL, {vec_mouse_coords, Vector2(800,400), Vector2(150,300)}, screenArray);

    //SDL_LoadWAV("audio/Tetris.wav", &wavSpec, &wavBuffer, &wavLength);
    //SDL_QueueAudio(deviceID, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceID, 0);

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
            }
        }
        //KEYBOARD
        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_Q]){
            printf("Event: Internal exit request.\n");
            break;
        }

        if(state[SDL_SCANCODE_W]) t2.p1.y -= 1;
        if(state[SDL_SCANCODE_S]) t2.p1.y += 1;

        if(state[SDL_SCANCODE_D]) t2.p1.x += 1;
        if(state[SDL_SCANCODE_A]) t2.p1.x -= 1;

        if(state[SDL_SCANCODE_KP_PLUS]) t2.size += 1;
        if(state[SDL_SCANCODE_KP_MINUS]) t2.size -= 1;
        //MOUSE
        updateMouse(&vec_mouse_coords);
        
        //DRAWING
        clearScreen(screenArray);
        metroLogo.draw();

        
        tri1.update_vertices({vec_mouse_coords, Vector2(800,400), Vector2(150,300)});
        t1.setText("X: " + std::to_string(vec_mouse_coords.x) + "\nY: " + std::to_string(vec_mouse_coords.y));

        t2.setText("upperR " + std::to_string(line1.isOnSameSide(vec_mouse_coords, vec_corner_UR)));
        t2.draw();

        title.draw();
        
        
        t1.p1 = vec_mouse_coords + Vector2(10, 6);
        //center.draw();
        //center.update_position(vec_mouse_coords);
        t1.draw();
        line1.draw();
        tri1.draw();

        

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
