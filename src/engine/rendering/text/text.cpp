#include "text.hpp"


extern const int ME_Width;
extern const int ME_Height;

extern uint32_t *screenArray;

Text::Text(){
    body = "";
    color = 0;
    p1 = Vector2(0,0);
}

Text::Text(std::string input, double _size, Vector2 location, uint32_t _color){
    body = input;
    size = _size;
    p1 = location;
    color = _color;
}

void Text::setText(std::string input){
    body = input;
}

std::string Text::getText(){
    std::string retString = body;
    return retString;
}

void Text::draw(){
    int horizontalOffset = 0;
    int verticalOffset = 0;
    for(const unsigned char& c : body){
        if(c == '\n'){ 
            verticalOffset += size*(CHAR_ME_Height + LINE_ME_Height);
            horizontalOffset = 0;
            continue;
        }
        if(c > 127) continue;
        int index = c;
        
        const uint8_t* chr = font[index];

        for(int i = 0; i < CHAR_ME_Height; i++){
            for(int j = 0; j < CHAR_ME_Width; j++){
                if(chr[i] & (0x01 << j)){
                    Vector2 currPixel(p1.x + j*size + horizontalOffset, p1.y + i*size + verticalOffset);
                        drawPixelSize(screenArray, currPixel, color, size);
                }
            }
        }
    
    horizontalOffset += size*(CHAR_ME_Width + SPACE_ME_Width);
    }
}

Vector2 Text::getCenter(){
    double horizontalOffset = 0;
    double maxHorizontal = 0;
    double verticalOffset = 0;

    for(const unsigned char& c : body){
        horizontalOffset += size*(CHAR_ME_Width + SPACE_ME_Width);
        if(c == '\n'){ 
            verticalOffset += size*(CHAR_ME_Height + LINE_ME_Height);
            if(horizontalOffset > maxHorizontal) maxHorizontal = horizontalOffset;
            horizontalOffset = 0;
        }
    }
    return Vector2(maxHorizontal/2, verticalOffset/2);
}