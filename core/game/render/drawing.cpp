//
// Created by dargonrol on 9/27/2024.
//

#include "drawing.h"

#include "../../GameProperties.h"

namespace drawing {
    void drawCircle(Eigen::Vector2d centerPos, int radius) {
        int x = 0;
        int y = radius;
        int d = 3 - 2 * radius;  // Entscheidungsvariable

        while (x <= y) {
            drawCirclePoints(centerPos, x, y);
            if (d <= 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }

    void drawCirclePoints(Eigen::Vector2d centerPos, int x, int y) {
        SDL_Renderer* renderer = properties.app.renderer;
        SDL_RenderDrawPoint(renderer, centerPos[0] + x, centerPos[1] + y);
        SDL_RenderDrawPoint(renderer, centerPos[0] - x, centerPos[1] + y);
        SDL_RenderDrawPoint(renderer, centerPos[0] + x, centerPos[1] - y);
        SDL_RenderDrawPoint(renderer, centerPos[0] - x, centerPos[1] - y);
        SDL_RenderDrawPoint(renderer, centerPos[0] + y, centerPos[1] + x);
        SDL_RenderDrawPoint(renderer, centerPos[0] - y, centerPos[1] + x);
        SDL_RenderDrawPoint(renderer, centerPos[0] + y, centerPos[1] - x);
        SDL_RenderDrawPoint(renderer, centerPos[0] - y, centerPos[1] - x);
    }
}
