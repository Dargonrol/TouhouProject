cmake_minimum_required(VERSION 3.22)
project(TouhouProject)
add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 26)

add_executable(${PROJECT_NAME} main.cpp
        core/GameEngine.h
        core/GameEngine.cpp
        core/StateManager.h
        core/StateManager.cpp
        core/SceneManager.h
        core/SceneManager.cpp
        core/UI/scenes/Scene.h
        core/UI/scenes/MainMenuScene.h
        core/EventManager.cpp
        core/EventManager.h
        core/UI/scenes/settingsMenuScene.h
        core/GameProperties.h
        core/UI/text.h
        core/utility.h
        core/UI/language.h
        core/file/parser.cpp
        core/file/parser.h
        core/UI/language.cpp
        core/UI/elements/Button.cpp
        core/UI/elements/Button.h
        core/UI/scenes/GameScene.cpp
        core/UI/scenes/GameScene.h
        core/game/Stages/Stage1.cpp
        core/game/Stages/Stage1.h
        core/game/Stages/States.h
        core/game/Stages/Stage.h
        core/UI/scenes/MainMenuScene.cpp
        core/UI/scenes/SettingsMenuScene.cpp
        core/game/objects/Player.cpp
        core/game/objects/Player.h
        core/game/objects/GameObject.h
        core/game/objects/characters/Sylphina.cpp
        core/game/objects/characters/Sylphina.h
)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "SDL2/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})