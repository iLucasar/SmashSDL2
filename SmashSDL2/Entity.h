#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "Console.h"
#include "Errors.h"
#include "Vector2f.h"

class Entity
{

private:

	// Dimensioni tile

	Vector2f dimension;

	// Posizione

	Vector2f position;

	// Rect

	SDL_Rect* rect;

	// Texture

	SDL_Texture* texture;

	// Renderer

	SDL_Renderer* renderer;

	// Funzione di update del rect
	void updateRect();

	Vector2f speed;

public:

	Entity(SDL_Renderer*, std::string);

	// Aggiornamento fisica

	Vector2f* getState() { return &(this->speed); }

	void calculateNewPosition();

	// Funzione di update della posizione

	void updatePos(Vector2f);
	Vector2f* getPos() { return &(this->position); }

	// Funzione di update texture
	void loadTexture(std::string);

	// Funzione per presentare la texture

	void copyToRenderer();


};