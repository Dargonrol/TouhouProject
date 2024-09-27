//
// Created by dargonrol on 6/21/2024.
//

#include "EventManager.h"

EventManager::EventManager() {}
EventManager::EventManager(EventManager const &copy) {}
EventManager &EventManager::operator=(EventManager const &copy) { return *this; }

EventManager &EventManager::getInstance() {
    static EventManager instance;
    return instance;
}

void EventManager::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            default:
                SceneManager::getInstance().handleEvents(event);
                break;
        }

    }
}





