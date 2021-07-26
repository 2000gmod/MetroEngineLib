#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "shapes.hpp"
#include "text.hpp"
#include <functional>

class Button : Drawable{
    public:
        Button();
        Button(std::string text, Rectangle& box);
        void draw() override;
        void setAction(std::function<void(Vector2&)> action);

    private:
        Rectangle box;
        Text text;
        std::function<void(Vector2&)> action;
};

#endif