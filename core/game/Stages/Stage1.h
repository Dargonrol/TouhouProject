//
// Created by dargonrol on 9/16/2024.
//

#ifndef STAGE1_H
#define STAGE1_H
#include <SDL_events.h>

#include "Stage.h"
#include "../objects/GameObject.h"
#include "../objects/characters/Sylphina.h"

class Stage1 : public Stage {
private:
    std::vector<GameObject*> m_objects;

public:
    Stage1();
    ~Stage1() override = default;
    void update(double deltaTime) override;
    void render(float alpha) override;
    void handleEvents(SDL_Event event) override;
    void addObject(GameObject* object);
    void removeObject(GameObject* object);
    void clearObjects();
    std::vector<GameObject*> getObjects();
    Sylphina* getPlayer();
};
#endif //STAGE1_H
