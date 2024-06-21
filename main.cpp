#include <SDL.h>
#include "core/GameEngine.h"

#ifndef PROJECT_NAME
#define PROJECT_NAME "dummy, name defined in CMakeLists.txt"
#endif

int main(int argc, char* args []) {
    GameEngine::getInstance().init();
    GameEngine::getInstance().run();
    return 0;
}