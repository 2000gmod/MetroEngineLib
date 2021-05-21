#include "engine/engine.hpp"

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* screen;

int main(){
    initWindow("Title");
    Clock clock;
    uint32_t targetDelay = 1000/FRAMERATE;

    Vector2 vec_mouse_coords;

    Vector2 vec_screen_center(WIDTH/2, HEIGHT/2);
    Vector2 vec_corner_UL(0,0);
    Vector2 vec_corner_UR(0, WIDTH);
    Vector2 vec_corner_LL(0, HEIGHT);
    Vector2 vec_corner_LR(WIDTH, HEIGHT);

    Text t1("", 1, vec_corner_UL, ORANGE);
    Text t2("test", 1, vec_corner_UL, WHITE);

    Text title("METRO ENGINE DEMO 1", 3, Vector2(vec_screen_center.x - 300 , 0), RED);

    Poly metroRombo1(RED, 2, FULL, {Vector2(100,100), Vector2(50,200), Vector2(100,300), Vector2(150,200)}, pixel_array);
    Poly metroRombo2(RED, 2, FULL, {Vector2(200,100), Vector2(150,200), Vector2(200,300), Vector2(250,200)}, pixel_array);
    Poly metroRombo3(RED, 2, FULL, {Vector2(300,100), Vector2(250,200), Vector2(300,300), Vector2(350,200)}, pixel_array);

    Line line1(WHITE, 2, vec_corner_UL, vec_corner_LR, pixel_array);


    PolyObject metroLogo({metroRombo1, metroRombo2, metroRombo3});

    Poly tri1(GREEN, DARKRED, 6, FULL, {Vector2(WIDTH/2, HEIGHT/2), vec_mouse_coords, Vector2(0, 0)}, pixel_array);

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

        tri1.draw();
        tri1.update_vertices({Vector2(100, 100), vec_mouse_coords, Vector2(800,400)});
        t1.setText("X: " + std::to_string(vec_mouse_coords.x) + "\nY: " + std::to_string(vec_mouse_coords.y));

        t2.setText("upperR " + std::to_string(line1.isOnSameSide(vec_mouse_coords, vec_corner_UR)));
        t2.draw();

        title.draw();
        
        
        t1.p1 = vec_mouse_coords + Vector2(10, 6);
        //center.draw();
        //center.update_position(vec_mouse_coords);
        metroLogo.draw();
        t1.draw();
        //line1.draw();

        

        //screen update
        updateFrame();

        clock.Tick();
        if(clock.deltaTime < targetDelay){
            SDL_Delay(targetDelay - clock.deltaTime);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
