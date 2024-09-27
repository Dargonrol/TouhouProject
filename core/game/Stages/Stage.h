//
// Created by dargonrol on 9/25/2024.
//

#ifndef STAGE_H
#define STAGE_H

class Stage {
public:
    virtual ~Stage() = default;

    virtual void handleEvents(SDL_Event event) = 0;
    virtual void update(double deltaTime) = 0;
    virtual void render(float alpha) = 0;

protected:
    Stage() = default;


};

#endif //STAGE_H

