#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "Console.h"
#include "Errors.h"
#include "Vector2f.h"

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

	//std::vector <Entity*> EntitiesList;

	int WindowRefreshRate;

public:

	Engine(std::string, Vector2f);
	~Engine();

	static void start();
	void GFXUpdate();

	bool shouldUpdate();

	bool isRunning();

};

