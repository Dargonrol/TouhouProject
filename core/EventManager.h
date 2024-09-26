//
// Created by dargonrol on 6/21/2024.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <SDL.h>
#include "SceneManager.h"

class EventManager {
private:
    EventManager();
    EventManager(EventManager const& copy);
    EventManager& operator=(EventManager const& copy);

public:
    bool running = true;
    static EventManager& getInstance();
    void handleEvents();
};
#endif //EVENTMANAGER_H
