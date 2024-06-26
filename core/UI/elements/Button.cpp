//
// Created by dargonrol on 6/24/2024.
//

#include "Button.h"
#include "../text.h"

void Button::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, this->currentColor.r, this->currentColor.g, this->currentColor.b, this->currentColor.a);
    SDL_RenderFillRect(renderer, &rect);
    if (this->borderWidth > 0) {
        SDL_SetRenderDrawColor(renderer, this->borderColor.r, this->borderColor.g, this->borderColor.b, this->borderColor.a);
        for (int i = 0; i < this->borderWidth; i++) {
            SDL_Rect tempRect = { rect.x - i, rect.y - i, rect.w + 2 * i, rect.h + 2 * i };
            SDL_RenderDrawRect(renderer, &tempRect);
        }
    }
    if (this->texture != nullptr) {
        SDL_RenderCopy(renderer, this->texture, nullptr, &rect);
    }

    SDL_SetRenderDrawColor(renderer, this->currentColor.r, this->currentColor.g, this->currentColor.b, this->currentColor.a);

    TTF_Font* font = TTF_OpenFont(fontPath, this->calcFontSize());
    getTextAndRect(renderer, this->text, font, this->textTexture, this->textRect);
    setTextPosition(this->textRect, this->rect.x, this->rect.y);
    SDL_RenderCopy(renderer, this->textTexture, nullptr, &this->textRect);
    TTF_CloseFont(font);
}

void Button::update(SDL_Event event) {
    if (this->isDisabled) { return; }
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (isMouseEnabled && (x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.h + rect.y)) {
        if (!this->isMouseOverRect) {
            this->isMouseOverRect = true;
            this->isSelected = true;
            SDL_Log("on enter");
            this->currentColor = this->hoverColor;
            if (this->onEnter != nullptr) { this->onEnter(); }
        }
        if (this->onHover != nullptr) { this->onHover(); }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_Log("clicked");
            if (this->onClick != nullptr) { this->onClick(); }
        }
    }
    if (isMouseEnabled && !((x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.h + rect.y)) && this->isMouseOverRect) {
        this->isMouseOverRect = false;
        this->isSelected = false;
        SDL_Log("on leave");
        this->currentColor = this->defaultColor;
        if (this->onLeave != nullptr) { this-> onLeave(); }
    }
}

void Button::select() { this->isSelected = true; }
void Button::unselect() { this->isSelected = false; }

void Button::setTexture(SDL_Texture *texture) { this->texture = texture; }
void Button::setText(const char* text, const char* fontPath, SDL_Color textColor) {
    this->text = text;
    this->fontPath = fontPath;
    this->defaultColor = textColor;
}
void Button::updateText(const char* text) {
    this->text = text;
}
void Button::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}


void Button::setClickColor(SDL_Color color) { this->clickColor = color; }
void Button::setHoverColor(SDL_Color color) { this->hoverColor = color; }
void Button::setDisabledColor(SDL_Color color) { this->disabledColor = color; }
void Button::setDefaultColor(SDL_Color color) { this->defaultColor = color; }

void Button::setOnClick(void (*onClick)()) { this->onClick = onClick; }
void Button::setOnHover(void (*onHover)()) { this->onHover = onHover; }
void Button::setOnLeave(void (*onLeave)()) { this->onLeave = onLeave; }
void Button::setOnEnter(void (*onEnter)()) { this->onEnter = onEnter; }

void Button::disable() {
    this->isDisabled = true;
    this->currentColor = this->disabledColor;
}
void Button::enable() {
    this->isDisabled = false;
    this->currentColor = this->defaultColor;
}
void Button::disableMouse() { this->isMouseEnabled = false; }
void Button::enableMouse() { this->isMouseEnabled = true; }
void Button::enableDynamicTextRezising() { this->dynamicTextRezising = true; }
void Button::disableDynamicTextRezising() { this->dynamicTextRezising = false; }

Button::Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backgroundColor, SDL_Texture *texture) {
    this->renderer = renderer;
    this->rect = rect;
    this->text = text;
    this->fontSize = fontSize;
    this->textColor = textColor;
    this->defaultColor = backgroundColor;
    this->borderColor = {0, 0, 0, 0};
    this->texture = texture;
    this->fontPath = fontPath;
}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backgroundColor, SDL_Color borderColor, int borderWidth) {
    this->renderer = renderer;
    this->rect = rect;
    this->text = text;
    this->fontSize = fontSize;
    this->textColor = textColor;
    this->defaultColor = backgroundColor;
    this->borderColor = borderColor;
    this->borderWidth = borderWidth;
    this->texture = nullptr;
    this->fontPath = fontPath;
}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor, SDL_Color backgroundColor)
    : Button(renderer, rect, text, fontPath, fontSize, textColor, backgroundColor, {0, 0, 0, 0}, 0) {}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize, SDL_Color textColor)
    : Button(renderer, rect, text, fontPath, fontSize, textColor, {128, 128, 128}, {0, 0, 0, 0}, 0) {}

Button::Button(SDL_Renderer* renderer, SDL_Rect rect, const char* text, const char* fontPath, int fontSize)
    : Button(renderer, rect, text, fontPath, fontSize, {255, 255, 255}, {128, 128, 128}, {0, 0, 0, 0}, 0) {}
Button::Button() = default;

int Button::calcFontSize() {
    if (!this->dynamicTextRezising) { return this->fontSize; }
    while ((this->textRect.w + this->textRect.x > this->rect.x + this->rect.w)
        || (this->textRect.h + this->textRect.y > this->rect.y + this->rect.h))
    {
        this->fontSize--;
        TTF_CloseFont(this->font);
        this->font = TTF_OpenFont(this->fontPath, this->fontSize);
        getTextAndRect(renderer, this->text, this->font, this->textTexture, this->textRect);
        setTextPosition(this->textRect, this->rect.x, this->rect.y);
    }
    return this->fontSize;
}

Button::~Button() {
    SDL_DestroyTexture(this->texture);
    SDL_DestroyTexture(this->textTexture);
    TTF_CloseFont(this->font);
}
