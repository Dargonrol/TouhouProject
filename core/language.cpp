//
// Created by dargonrol on 6/23/2024.
//

#include "language.h"

#include <SDL.h>

void Language::setLanguageValue(std::string key, std::string &value, const std::string category1, const std::string category2) {
        if (category1 == "labels") {
            if (category2 == "mainMenuScene") {
                if (key == "title") {
                    getInstance().language.labels.mainMenuScene.title = value;
                } else {
                    SDL_LogError(1, "Unknown key: %s", key.c_str());
                }
            } else if (category2 == "settingsScene") {
                if (key == "title") {
                    getInstance().language.labels.settingsScene.Scenetitle = value;
                } else {
                    SDL_LogError(1, "Unknown key: %s", key.c_str());
                }
            } else {
                SDL_LogError(1, "key: %s is not a catergory2", key.c_str());
            }
        } else {
            SDL_LogError(1, "key: %s is not a catergory1", key.c_str());
        }
}

void Language::setLanguageValue(std::string key, std::string value, const std::string category1) {
        if (category1 == "buttons") {
            if (key == "newGame") {
                Language::getInstance().language.buttons.newGame = value.c_str();
            } else if (key == "settings") {
                //language.buttons.settings = *value;
            } else if (key == "quit") {
                getInstance().language.buttons.quit = value;
            } else if (key == "watchReplays") {
                getInstance().language.buttons.watchReplays = value;
            } else {
                SDL_LogError(1, "Unknown key: %s", key.c_str());
            }
        } else if (category1 == "credits") {
            if (key == "story") {
                getInstance().language.credits.story = value;
            } else if (key == "graphicDesign") {
                getInstance().language.credits.graphicDesign = value;
            } else {
                SDL_LogError(1, "Unknown key: %s", key.c_str());
            }
        } else {
            SDL_LogError(1, "key: %s is not a catergory1", key.c_str());
        }
}

Language::Language() {}
Language::Language(Language const &copy) {}
Language &Language::operator=(Language const &copy) { return *this; }

Language &Language::getInstance() {
    static Language instance;
    return instance;
}
