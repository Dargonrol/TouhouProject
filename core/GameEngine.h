//
// Created by dargonrol on 6/20/2024.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SDL_render.h>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run() const;

protected:
    struct {
        int width = 800;
        int height = 600;
    } resolution;

    struct {
        SDL_Renderer* renderer;
        SDL_Window* window;
    } App;

    bool eventHandler() const;


};

#endif //GAMEENGINE_H

