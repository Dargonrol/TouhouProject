//
// Created by dargonrol on 9/25/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SDL_render.h>

#include "GameObject.h"

class Player : public GameObject {
    Player();

    void update() override;
    void render() override;

private:
    SDL_Texture* m_texture;
};
#endif //PLAYER_H
