//
// Created by dargonrol on 9/16/2024.
//

#include "Stage1.h"

#include <algorithm>
#include <SDL_keyboard.h>
#include <SDL_log.h>

#include "../objects/characters/Sylphina.h"

Stage1::Stage1() : Stage() {
    auto* sylphina = new Sylphina();
    addObject(sylphina);
}

void Stage1::addObject(GameObject* object) {
    m_objects.push_back(object);
}

void Stage1::removeObject(GameObject* object) {
    auto iter = std::find(m_objects.begin(), m_objects.end(), object);
    if (iter != m_objects.end()) {
        m_objects.erase(iter);
        delete object;
    }
}

void Stage1::clearObjects() {
    for (auto& object : m_objects) {
        delete object;
    }
    m_objects.clear();
}

std::vector<GameObject*> Stage1::getObjects() {
    return m_objects;
}

Sylphina* Stage1::getPlayer() {
    for (const auto& object : m_objects) {
        if (object->getType() == "Player") {
            return dynamic_cast<Sylphina*>(object);
        }
    }
    return nullptr;
}

void Stage1::update(double deltaTime) {
    for (const auto& object : m_objects) {
        if (object != nullptr) {
            object->update(deltaTime);
            continue;
        }
        SDL_Log("object is null");
    }
}

void Stage1::render(float alpha) {
    for (const auto& object : m_objects) {
        object->render(alpha);
    }
}

void Stage1::handleEvents(SDL_Event event) {
    /*
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    m_pressed_W = state[SDL_SCANCODE_W];
    m_pressed_A = state[SDL_SCANCODE_A];
    m_pressed_S = state[SDL_SCANCODE_S];
    m_pressed_D = state[SDL_SCANCODE_D];
    */
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        if (event.key.keysym.sym == SDLK_w) {
            getPlayer()->addPlayerVelocity({0, -1});
        }
        if (event.key.keysym.sym == SDLK_a) {
            getPlayer()->addPlayerVelocity({-1, 0});
        }
        if (event.key.keysym.sym == SDLK_s) {
            getPlayer()->addPlayerVelocity({0, 1});
        }
        if (event.key.keysym.sym == SDLK_d) {
            getPlayer()->addPlayerVelocity({1, 0});
        }
    }
    if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        if (event.key.keysym.sym == SDLK_w) {
            getPlayer()->remPlayerVelocity({0, -1});
        }
        if (event.key.keysym.sym == SDLK_a) {
            getPlayer()->remPlayerVelocity({-1, 0});
        }
        if (event.key.keysym.sym == SDLK_s) {
            getPlayer()->remPlayerVelocity({0, 1});
        }
        if (event.key.keysym.sym == SDLK_d) {
            getPlayer()->remPlayerVelocity({1, 0});
        }
    }
}