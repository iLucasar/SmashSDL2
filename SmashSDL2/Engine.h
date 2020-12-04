#pragma once

#include <SDL.h>

#include "Errors.h"
#include "Console.h"

#include <iostream>
#include <vector>
#include <map>

#include "Vector2f.h"

#include "Entity.h"
#include "Tile.h"

// UPDATES_PER_SECOND indica gli aggiornamenti della fisica al secondo
// UPDATE_PERIOD_TICKS indica il numero di tick massimi per update

#define UPDATES_PER_SECOND 60
#define UPDATE_PERIOD_TICKS 1000 / UPDATES_PER_SECOND

class Engine
{
private:

	// Puntatori finestra e renderer

	SDL_Window* WindowPtr;
	SDL_Renderer* RendererPtr;

	// Variabili booleane per sapere se sta girando il gioco e se c'è bisogno di fare un update

	bool running;
	bool update;

	// Variabili temporali

	int lastUpdate;
	
	int accumulator;

	// Lista tile ed entità

	std::map <std::string, Tile*> TilesList;
	std::map <std::string, Entity*> EntitiesList;

	int WindowRefreshRate;

public:

	// Costruttori e decostruttori
	
	Engine(std::string, Vector2f);
	~Engine();

	// Funziona per ottenere il renderer

	SDL_Renderer* getRenderer() { return this->RendererPtr; }

	// Funzione per avviare il motore SDL

	static void start();
	void stop();

	// Funzione di update della grafica e fisica

	void GFXUpdate();

	void PHUpdate();

	// Gestione tile e sprite

	void addTile(std::string, Tile*);
	void removeTile(std::string);

	void addEntity(std::string, Entity *);
	void removeEntity(std::string);

	// Puntatore ad una specifica tile o sprite

	Tile* getTile(std::string);
	Entity* getEntity(std::string);

	bool shouldUpdate();

	bool isRunning();

};

