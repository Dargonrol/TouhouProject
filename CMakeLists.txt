cmake_minimum_required(VERSION 3.22)
project(TouhouProject)
add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 26)

add_executable(${PROJECT_NAME} main.cpp
        core/GameEngine.h
        core/GameEngine.cpp
        core/StateManager.h
        core/SceneManager.h
        core/scenes/Scene.h
        core/scenes/MainMenuScene.h
        core/EventManager.cpp
        core/EventManager.h
)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})