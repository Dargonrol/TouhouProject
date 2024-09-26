#include "GameEngine.h"

void GameEngine::run() {
    const double MS_PER_UPDATE = 16.6667; // Targeting 60 updates per second (1000ms / 60)

    double previous = SDL_GetPerformanceCounter();
    double lag = 0.0;

    double deltaTime = 0.0;

    const int sampleSize = 100; // Number of frames to average over
    std::vector<double> frameTimes(sampleSize, 0.0);
    int frameIndex = 0;
    double totalFrameTime = 0.0;
    int frameCount = 0;

    double avgFrameTime = 0.0;
    double avgFPS = 0.0;

    double secondCounter = 0.0; // Counter to track elapsed time for one second

    Uint64 lastRenderTime = SDL_GetPerformanceCounter();
    int renderCount = 0;
    double totalRenderTime = 0.0;
    double avgRenderFPS = 0.0;

    double thousend = 1000.0;

    StateManager::getInstance().changeStateRequest(MAIN_MENU);

    while (eventManager.running) {
        double current = SDL_GetPerformanceCounter();
        deltaTime = (double)((current - previous) * thousend / SDL_GetPerformanceFrequency());
        previous = current;
        lag += deltaTime;
        secondCounter += deltaTime;

        // Process input
        eventManager.handleEvents();

        // Update game logic
        while (lag >= MS_PER_UPDATE) {
            sceneManager.updateSceneQueue(deltaTime); // Pass deltaTime to update function
            lag -= MS_PER_UPDATE;
        }

        // Render scene
        sceneManager.renderSceneQueue(); // Pass deltaTime to render function

        // Calculate frame time
        double frameEnd = SDL_GetPerformanceCounter();
        auto frameTime = (double)((frameEnd - current) * thousend / SDL_GetPerformanceFrequency());

        // Update frame time statistics
        totalFrameTime -= frameTimes[frameIndex];
        frameTimes[frameIndex] = frameTime;
        totalFrameTime += frameTime;

        frameIndex = (frameIndex + 1) % sampleSize;
        if (frameCount < sampleSize) {
            frameCount++;
        }

        // Update render time statistics
        renderCount++;
        totalRenderTime += deltaTime;
        auto elapsedSinceLastRender = (double)((frameEnd - lastRenderTime) * thousend / SDL_GetPerformanceFrequency());
        if (elapsedSinceLastRender >= 1000.0) {
            avgRenderFPS = renderCount / (totalRenderTime / 1000.0);
            SDL_Log("Render FPS: %f", avgRenderFPS);
            renderCount = 0;
            totalRenderTime = 0.0;
            lastRenderTime = frameEnd;
        }

        // Update statistics every second
        if (secondCounter >= 1000.0) {
            avgFrameTime = totalFrameTime / frameCount;
            avgFPS = 1000.0 / avgFrameTime;
            SDL_Log("Average Frame Time: %f ms, Average Game Loop FPS: %f", avgFrameTime, avgFPS);
            secondCounter = 0.0;
        }

        // Optional: Delay to ensure the game doesn't run too fast
        if (frameTime < MS_PER_UPDATE) {
            SDL_Delay((Uint32)(MS_PER_UPDATE - frameTime));
        }
    }

    SDL_Log("Quitting...");
    // GameEngine::~GameEngine(); gets called automatically
    SDL_Quit();
}

void GameEngine::setFPS(int fps) {
    properties.FPS = fps;
    properties.frameDelay = 1000 / fps - properties.mainGameLoopUpdateDelay;
}

void GameEngine::init() {
    SDL_Log("Init SDL...");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_LogCritical(1, "SDL_Init failed: %s", SDL_GetError());
        throw std::runtime_error("SDL_Init failed");
    }
    if (TTF_Init() != 0) {
        SDL_LogCritical(1, "TTF_Init failed: %s", TTF_GetError());
        SDL_Quit();
        throw std::runtime_error("TTF_Init failed");
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        SDL_LogCritical(1, "IMG_Init failed: %s", IMG_GetError());
        TTF_Quit();
        SDL_Quit();
        throw std::runtime_error("IMG_Init failed");
    }
    SDL_Log("SDL initialized.");

    SDL_DisplayMode displayMode;

    SDL_Log("fetching display resolution");
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        SDL_LogCritical(1, "SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        SDL_Log("setting default resolution to default: 800x600");
        properties.resolution.height = 600;
        properties.resolution.width = 800;
    } else {
        properties.resolution.height = displayMode.h / 2;
        properties.resolution.width = displayMode.w / 2;
        SDL_Log("setting resolution to %dx%d", properties.resolution.width, properties.resolution.height);
    }

    SDL_Log("creating window...");
    properties.app.window = SDL_CreateWindow(
        properties.GAME_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        properties.resolution.width,
        properties.resolution.height,
        SDL_WINDOW_SHOWN
    );

    if (properties.app.window == nullptr) {
        SDL_LogCritical(1, "Failed to create window: %s", SDL_GetError());
        throw std::runtime_error("Failed to create window");
    }
    SDL_Log("Window created.");

    SDL_Log("creating renderer...");
    properties.app.renderer = SDL_CreateRenderer(properties.app.window, -1, SDL_RENDERER_ACCELERATED);

    if (properties.app.renderer == nullptr) {
        SDL_LogCritical(1, "Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(properties.app.window);
        SDL_Quit();
        throw std::runtime_error("Failed to create renderer");
    }
    SDL_Log("Renderer created.");

    SDL_Log("Current Video Driver: %s", SDL_GetCurrentVideoDriver());

    SDL_SetRenderDrawBlendMode(properties.app.renderer, SDL_BLENDMODE_BLEND);
    SDL_DisableScreenSaver();

    //SDL_RenderSetVSync(properties.app.renderer, SDL_TRUE);

    // initialize language
    Parser::parseLanguage(ENGLISH);
}

GameEngine::GameEngine() : eventManager(EventManager::getInstance()), sceneManager(SceneManager::getInstance()), stateManager(StateManager::getInstance()) { }
GameEngine::GameEngine(GameEngine const &copy) : eventManager(EventManager::getInstance()), sceneManager(SceneManager::getInstance()), stateManager(StateManager::getInstance()) { }
GameEngine &GameEngine::operator=(GameEngine const &copy) { return *this; }

GameEngine &GameEngine::getInstance() {
    static GameEngine instance;
    return instance;
}

GameEngine::~GameEngine() {
    SDL_Log("cleaning up");
    SDL_DestroyRenderer(properties.app.renderer);
    SDL_DestroyWindow(properties.app.window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
