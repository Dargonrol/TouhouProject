//
// Created by dargonrol on 6/24/2024.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

class Button {
private:
    SDL_Texture* texture{};
    SDL_Rect rect{};
    SDL_Renderer* renderer{};
    SDL_Color borderColor{};
    int borderWidth = 0;
    bool isDisabled = false;
    bool isMouseEnabled = true;
    SDL_Color hoverColor = {0, 255, 0, 255};
    SDL_Color clickColor = {255, 0, 0, 255};
    SDL_Color disabledColor = {128, 128, 128, 255};
    SDL_Color defaultColor = {0, 0, 0, 255};
    SDL_Color currentColor = defaultColor;
    void (*onClick)() = nullptr;
    void (*onHover)() = nullptr;
    void (*onLeave)() = nullptr;
    void (*onEnter)() = nullptr;

    bool isMouseOverRect = false;
    bool isSelected = false;

public:
    void update(SDL_Event event);
    void render(SDL_Renderer* renderer);
    void disable();
    void enable();
    void disableMouse();
    void enableMouse();

    void setOnClick(void (*onClick)());
    void setOnHover(void (*onHover)());
    void setOnLeave(void (*onLeave)());
    void setOnEnter(void (*onEnter)());

    void setHoverColor(SDL_Color color);
    void setClickColor(SDL_Color color);
    void setDisabledColor(SDL_Color color);
    void setDefaultColor(SDL_Color color);

    void select();
    void unselect();

    void setTexture(SDL_Texture* texture);

    Button(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color backgroundColor, SDL_Texture *texture);
    Button(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color backroundColor, SDL_Color borderColor, int borderWidth);
    Button(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color backroundColor);
    Button(SDL_Renderer* renderer, SDL_Rect rect);
    Button();

    ~Button();
};
#endif //BUTTON_H
