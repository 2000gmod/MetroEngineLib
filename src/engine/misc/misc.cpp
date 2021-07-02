#include "../include/misc.hpp"

extern int ME_Width;
extern int ME_Height;

void playIntroAnimation(uint32_t* pixelBuffer){
    uint32_t targetDelay = 1000/FRAMERATE;
    float animationLen = 3;

    Text logo1("Powered by:", 2, Vector2(ME_Width/2 - 100, ME_Height/2 - 10), getColor(255, 255, 255, 0));
    Text logo2("METRO ENGINE", 4, Vector2(ME_Width/2 - 200, ME_Height/2 + 10), getColor(255, 50, 50, 0));
    Clock clock;

    const float midPoint = animationLen * 1000 / 2;
    const float endPoint = midPoint * 2;
    while (clock.totalTime <= midPoint){
        clearScreen(pixelBuffer);
        logo1.draw();
        logo2.draw();

        logo1.color = getColor(255, 255, 255, (clock.totalTime / midPoint) * 255);
        logo2.color = getColor(255, 50, 50, (clock.totalTime / midPoint) * 255);

        updateFrame();

        clock.Tick();
        if(clock.deltaTime < targetDelay){
            SDL_Delay(targetDelay - clock.deltaTime);
        }
    }

    while (clock.totalTime <= endPoint){
        clearScreen(pixelBuffer);

        logo1.draw();
        logo2.draw();

        float colorChannel = ((-255/midPoint)*(clock.totalTime - midPoint) + 255);
        const float multiplier2 = 50/255;
        
        logo1.color = getColor(colorChannel, colorChannel, colorChannel);
        logo2.color = getColor(colorChannel, multiplier2*colorChannel, multiplier2*colorChannel);

        updateFrame();

        clock.Tick();
        if(clock.deltaTime < targetDelay){
            SDL_Delay(targetDelay - clock.deltaTime);
        }
    }
}