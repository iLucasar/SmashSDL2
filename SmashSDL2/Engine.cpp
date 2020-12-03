#include "Engine.h"

Engine::Engine(std::string wTitle, Vector2f wDim)
{

    this->WindowPtr = SDL_CreateWindow(wTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wDim.x, wDim.y, SDL_WINDOW_ALLOW_HIGHDPI);

    this->RendererPtr = SDL_CreateRenderer(WindowPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    this->running = true;
    this->update = false;

    this->accumulator = 0;

    lastUpdate = SDL_GetTicks();

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(this->WindowPtr), 0, &mode);
    this->WindowRefreshRate = mode.refresh_rate;

}

Engine::~Engine()
{

    SDL_DestroyWindow(this->WindowPtr);
    SDL_DestroyRenderer(this->RendererPtr);
}

void Engine::start()
{
    // Inizializazione SDL2 e gestione errori

    Console::generic("Starting SDL2...");

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        Console::error(std::string("Error code: " + GENERIC_INIT_FAIL));
    else
        Console::success("SDL2 initialization complete!");

    return;

}

void Engine::GFXUpdate()
{

    SDL_RenderClear(this->RendererPtr);

    SDL_RenderPresent(this->RendererPtr);
    
}

bool Engine::shouldUpdate()
{
    
    int currentTicks = SDL_GetTicks();

    this->accumulator = currentTicks - this->lastUpdate;

    if (this->accumulator >= UPDATE_PERIOD_TICKS)
    {

        this->accumulator -= UPDATE_PERIOD_TICKS;
        
        this->lastUpdate = currentTicks;

        return true;

    }
    else
        return false;
}

bool Engine::isRunning()
{
    return this->running;
}
