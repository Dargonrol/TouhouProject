//
// Created by dargonrol on 9/16/2024.
//

#ifndef STAGE1_H
#define STAGE1_H
#include <vector>

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
    void render() override;
    void handleEvents() override;
    void addObject(GameObject* object);
    void removeObject(GameObject* object);
    void clearObjects();
    std::vector<GameObject*> getObjects();
    Sylphina* getPlayer();

private:
    //movement
    bool m_pressed_W = false;
    bool m_pressed_A = false;
    bool m_pressed_S = false;
    bool m_pressed_D = false;

};
#endif //STAGE1_H
