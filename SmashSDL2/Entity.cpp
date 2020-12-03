#include "Entity.h"

Entity::Entity(SDL_Renderer* renderer, std::string file)
{

	this->renderer = renderer;

	this->texture = IMG_LoadTexture(this->renderer, file.c_str());

	this->position = Vector2f(0, 0);

	SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->dimension.x), &(this->dimension.y));

}

void Entity::calculateNewPosition()
{

	this->position + speed;

}

void Entity::updatePos(Vector2f v)
{
	this->position = v;
}

void Entity::updateRect()
{

	SDL_Rect gino = SDL_Rect({ this->position.x, this->position.y, this->dimension.x, this->dimension.y });
	this->rect = &(gino);

}

void Entity::loadTexture(std::string file)
{

	this->texture = IMG_LoadTexture(this->renderer, file.c_str());

}

void Entity::copyToRenderer()
{

	this->updateRect();

	SDL_RenderCopy(this->renderer, this->texture, nullptr, this->rect);

}