#include "GameEngine.h"
#include <chrono>
#include <thread>

void GameEngine::run() {
    StateManager::getInstance().changeStateRequest(MAIN_MENU);

    const float FIXED_TIMESTEP = 1.0f / 60.0f;
    using clock = std::chrono::high_resolution_clock;
    auto lastTime = clock::now();
    auto fpsStartTime = lastTime; // Zeitstempel für die FPS-Berechnung

    float accumulator = 0.0f;
    int frameCount = 0;           // Anzahl der gerenderten Frames
    int fps = 0;
    int updateCount = 0;           // Anzahl der Updates
    int updateFps = 0;             // Update-FPS-Wert

    auto currentTime = clock::now();
    auto fpsCurrentTime = clock::now();
    float deltaTime = 0.0f;
    float alpha;

    while (eventManager.running) {
        currentTime = clock::now();
        std::chrono::duration<float> frameTime = currentTime - lastTime;
        lastTime = currentTime;

        deltaTime = frameTime.count(); // Zeit zwischen den Frames
        accumulator += deltaTime; // Zeit dem Accumulator hinzufügen

        eventManager.handleEvents(); // Event-Handling

        // Update-Schleife
        while (accumulator >= FIXED_TIMESTEP) {
            sceneManager.updateSceneQueue(FIXED_TIMESTEP); // Verwende FIXED_TIMESTEP für Updates
            accumulator -= FIXED_TIMESTEP;

            updateCount++;  // Zähle die Updates
        }

        // Berechne das Verhältnis für die Interpolation
        alpha = accumulator / FIXED_TIMESTEP;


        sceneManager.renderSceneQueue(alpha); // Rendern unter Verwendung von Alpha für Interpolation

        // FPS-Berechnung: Zähle die Frames
        frameCount++;
        // Berechne die verstrichene Zeit seit der letzten FPS-Anzeige (z.B. jede Sekunde)
        fpsCurrentTime = clock::now();
        std::chrono::duration<float> fpsDuration = fpsCurrentTime - fpsStartTime;
        if (fpsDuration.count() >= 1.0f) {  // Wenn eine Sekunde vergangen ist
            fps = frameCount;               // FPS = Anzahl der gerenderten Frames in einer Sekunde
            frameCount = 0;                 // Zurücksetzen des Zählers
            fpsStartTime = fpsCurrentTime;  // FPS-Startzeit aktualisieren

            updateFps = updateCount;           // Update-FPS = Anzahl der Updates in einer Sekunde
            updateCount = 0;                   // Zurücksetzen des Zählers

            // FPS in der Konsole ausgeben
            SDL_Log("Render-FPS: %d", fps);
            SDL_Log("Update-FPS: %d", updateFps);
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    SDL_Log("Quitting...");
    // GameEngine::~GameEngine(); gets called automatically
    SDL_Quit();
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
