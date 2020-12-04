#include "Engine.h"

Engine::Engine(std::string wTitle, Vector2f wDim)
{

    this->WindowPtr = SDL_CreateWindow(wTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wDim.x, wDim.y, SDL_WINDOW_ALLOW_HIGHDPI);

    this->RendererPtr = SDL_CreateRenderer(this->WindowPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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

void Engine::stop()
{

    this->running = false;

}

void Engine::GFXUpdate()
{

    SDL_RenderClear(this->RendererPtr);

    for (auto t : this->TilesList)
        t.second->copyToRenderer();

    for (auto e : this->EntitiesList)
        e.second->copyToRenderer();
        
    SDL_RenderPresent(this->RendererPtr);
    
}

void Engine::PHUpdate()
{

    for (auto e : this->EntitiesList)
    {
        e.second->calculateNewPosition();
        if (e.second->getPos()->y < (720 - e.second->getDim().y))
            e.second->getState()->y += 2;
        else if (e.second->getState()->y > 0)
        {
            e.second->getPos()->y = 720 - e.second->getDim().y;
            e.second->getState()->y = 0;
        }
        else
            e.second->getState()->x *= 0.75;
         
        
    }
        
}

void Engine::addTile(std::string name, Tile* newTile)
{

    this->TilesList.insert({ name, newTile });

}

void Engine::removeTile(std::string name)
{

    this->TilesList.erase(name);

}

void Engine::addEntity(std::string name, Entity* newTile)
{

    this->EntitiesList.insert({ name, newTile });
}

void Engine::removeEntity(std::string name)
{

    this->EntitiesList.erase(name);

}

Tile* Engine::getTile(std::string name)
{
    return this->TilesList.find(name)->second;
}

Entity* Engine::getEntity(std::string name)
{
    return this->EntitiesList.find(name)->second;
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
