#include "color.hpp"

uint32_t getColor(uint8_t red, uint8_t green, uint8_t blue){
    uint32_t colorOut = 0;
    colorOut += red;
    colorOut <<= 8;
    colorOut += green;
    colorOut <<= 8;
    colorOut += blue;
    colorOut <<= 8;
    colorOut += 0xFF;
    return colorOut;
}

uint32_t getColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    uint32_t colorOut = 0;
    colorOut += red;
    colorOut <<= 8;
    colorOut += green;
    colorOut <<= 8;
    colorOut += blue;
    colorOut <<= 8;
    colorOut += alpha;
    return colorOut;
}