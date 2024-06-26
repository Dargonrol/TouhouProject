//
// Created by dargonrol on 6/22/2024.
//

#ifndef TEXT_H
#define TEXT_H
#include <cmath>
#include <SDL.h>
#include <SDL_ttf.h>
#include "../GameProperties.h"

inline void getTextAndRect(SDL_Renderer* renderer, int posX, int posY, const char* text, TTF_Font* font, SDL_Texture* &texture, SDL_Rect &rect, SDL_Color textColor) {
    int text_width;
    int text_height;
    SDL_Surface *surface;;

    surface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect.w = text_width;
    rect.h = text_height;
    rect.x = posX;
    rect.y = posY;
}

inline void getTextAndRect(SDL_Renderer* renderer, int posX, int posY, const char* text, TTF_Font* font, SDL_Texture* &texture, SDL_Rect &rect) {
    getTextAndRect(renderer, posX, posY, text, font, texture, rect, {255, 255, 255, 0});
}

inline void getTextAndRect(SDL_Renderer* renderer, const char* text, TTF_Font* font, SDL_Texture* &texture, SDL_Rect &rect, SDL_Color textColor) {
    getTextAndRect(renderer, 0, 0, text, font, texture, rect, textColor);
}

inline void getTextAndRect(SDL_Renderer* renderer, const char* text, TTF_Font* font, SDL_Texture* &texture, SDL_Rect &rect) {
    getTextAndRect(renderer, 0, 0, text, font, texture, rect, {255, 255, 255, 0});
}

inline void setTextPosition(SDL_Rect &rect, int posX, int posY) {
    rect.x = posX;
    rect.y = posY;
}

inline int calculateFontSize(float multiplier) {
    return static_cast<int>(std::round((static_cast<float>(properties.resolution.height) / 20) * multiplier));
}

inline struct {
    float TITLE = 3;
    float SUBTITLE = 1.5;
    float TEXT = 1;
} fontMultiplier;

inline int fitFontSizeInButton(SDL_Rect rect, const char* fontPath, const char* text, int fontSize) {
    TTF_Font* font = TTF_OpenFont(fontPath, fontSize);
    int textWidth, textHeight;
    TTF_SizeUTF8(font, text, &textWidth, &textHeight);
    while (textWidth > rect.w || textHeight > rect.h) {
        fontSize--;
        TTF_CloseFont(font);
        font = TTF_OpenFont(fontPath, fontSize);
        TTF_SizeText(font, text, &textWidth, &textHeight);
    }
    TTF_CloseFont(font);
    return fontSize;
}

#endif //TEXT_H
