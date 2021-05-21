#include "engineh.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

int main(){
    initWindow("MetroEngine::Demo1 || Made by 2000gmod");
    Clock clock;
    uint32_t targetDelay = 1000/FRAMERATE;

    vector2 vec_mouse_coords;

    vector2 vec_screen_center(WIDTH/2, HEIGHT/2);
    vector2 vec_corner_UL(0,0);
    vector2 vec_corner_UR(0, WIDTH);
    vector2 vec_corner_LL(HEIGHT, 0);
    vector2 vec_corner_LR(HEIGHT, WIDTH);

    Text t1("", 1, vec_screen_center, ORANGE);
    Text t2("test", 1, vec_screen_center, WHITE);
    t2.p1 = vector2(WIDTH/2, HEIGHT/2);
    Circle center(RED, 2, vec_mouse_coords, 50, pixel_array);

    Poly poly1(TEAL, 2, {vector2(500,500), vector2(600,300), vector2(700,50)}, pixel_array);
    Poly metroRombo1(RED, 2, {vector2(100,100), vector2(50,200), vector2(100,300), vector2(150,200)}, pixel_array);
    Poly metroRombo2(RED, 2, {vector2(200,100), vector2(150,200), vector2(200,300), vector2(250,200)}, pixel_array);
    Poly metroRombo3(RED, 2, {vector2(300,100), vector2(250,200), vector2(300,300), vector2(350,200)}, pixel_array);


    PolyObject metroLogo({metroRombo1, metroRombo2, metroRombo3});

    //GAMELOOP
    while(1){
        //KEYBOARD
        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_Q]) break;

        if(state[SDL_SCANCODE_W]) t2.p1.y -= 1;
        if(state[SDL_SCANCODE_S]) t2.p1.y += 1;

        if(state[SDL_SCANCODE_D]) t2.p1.x += 1;
        if(state[SDL_SCANCODE_A]) t2.p1.x -= 1;

        if(state[SDL_SCANCODE_KP_PLUS]) t2.size += 1;
        if(state[SDL_SCANCODE_KP_MINUS]) t2.size -= 1;
        //MOUSE
        updateMouse(&vec_mouse_coords);
        
        //DRAWING
        clearScreen(pixel_array);
        t1.setText("X: " + std::to_string(vec_mouse_coords.x) + "\nY: " + std::to_string(vec_mouse_coords.y));

        t2.setText("Current size: " + std::to_string(t2.size));
        t2.draw();
        
        
        t1.p1 = vec_mouse_coords + vector2(10, 6);
        //center.draw();
        //center.update_position(vec_mouse_coords);
        poly1.draw();
        metroLogo.draw();
        poly1.update_vertices({vector2(500,500), vector2(600,300), vec_mouse_coords});
        t1.draw();

        //screen update
        updateFrame();

        clock.Tick();
        if(clock.deltaTime < targetDelay){
            SDL_Delay(targetDelay - clock.deltaTime);
        }
    }

    return 0;
}
