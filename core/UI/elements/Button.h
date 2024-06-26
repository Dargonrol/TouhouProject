//
// Created by dargonrol on 6/24/2024.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SDL_ttf.h>

class Button {
private:
    SDL_Texture* texture{};
    SDL_Rect rect{};
    SDL_Rect textRect{};
    SDL_Texture* textTexture{};
    int fontSize{};
    SDL_Renderer* renderer{};
    SDL_Color borderColor{};
    int borderWidth = 0;
    const char* fontPath{};
    TTF_Font* font{};
    const char* text{};
    bool isDisabled = false;
    bool isMouseEnabled = true;
    SDL_Color hoverColor = {0, 255, 0, 255};
    SDL_Color clickColor = {255, 0, 0, 255};
    SDL_Color disabledColor = {128, 128, 128, 255};
    SDL_Color defaultColor = {0, 0, 0, 255};
    SDL_Color currentColor = defaultColor;
    SDL_Color textColor = {255, 255, 255, 255};
    void (*onClick)() = nullptr;
    void (*onHover)() = nullptr;
    void (*onLeave)() = nullptr;
    void (*onEnter)() = nullptr;

    bool isMouseOverRect = false;
    bool isSelected = false;
    bool dynamicTextRezising = true;

    int calcFontSize();

public:
    void update(SDL_Event event);
    void render(SDL_Renderer* renderer);
    void disable();
    void enable();
    void disableMouse();
    void enableMouse();
    void enableDynamicTextRezising();
    void disableDynamicTextRezising();

    void setOnClick(void (*onClick)());
    void setOnHover(void (*onHover)());
    void setOnLeave(void (*onLeave)());
    void setOnEnter(void (*onEnter)());

    void setHoverColor(SDL_Color color);
    void setClickColor(SDL_Color color);
    void setDisabledColor(SDL_Color color);
    void setDefaultColor(SDL_Color color);

    void setText(const char* text, const char* font, SDL_Color textColor);
    void updateText(const char* text);
    void setFontSize(int fontSize);

    void select();
    void unselect();

    void setTexture(SDL_Texture* texture);

    Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backgroundColor, SDL_Texture *texture);
    Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backroundColor, SDL_Color borderColor, int borderWidth);
    Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backroundColor);
    Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor);
    Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize);
    Button();

    ~Button();
};
#endif //BUTTON_H
