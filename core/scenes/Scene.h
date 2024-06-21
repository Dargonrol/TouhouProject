//
// Created by dargonrol on 6/21/2024.
//

#ifndef SCENE_H
#define SCENE_H
#include <SDL.h>

class Scene {
public:
    virtual int getID() {
        return ID;
    }
    virtual void setID(int id) {
        ID = id;
    }
    virtual void update(SDL_Renderer* renderer) = 0;
    virtual void render(SDL_Renderer* renderer) {
        SDL_RenderClear(renderer); // Clear the screen
        SDL_RenderPresent(renderer); // Update the screen
    }

protected:
    int ID = -1;
};
#endif //SCENE_H
