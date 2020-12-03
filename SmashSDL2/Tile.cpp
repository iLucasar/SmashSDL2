#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, std::string file)
{

	this->renderer = renderer;

	this->texture = IMG_LoadTexture(this->renderer, file.c_str());

	this->position = Vector2f(0, 0);

	SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->dimension.x), &(this->dimension.y));

}

void Tile::updatePos(Vector2f v)
{
	this->position = v;
}

void Tile::updateRect()
{

	SDL_Rect newRect = SDL_Rect({ this->position.x, this->position.y, this->dimension.x, this->dimension.y });

	this->rect = &newRect;
	
}

void Tile::loadTexture(std::string file)
{

	this->texture = IMG_LoadTexture(this->renderer, file.c_str());
		
}

void Tile::copyToRenderer()
{

	this->updateRect();

	SDL_RenderCopy(this->renderer, this->texture, nullptr, this->rect);

}
