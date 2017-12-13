#pragma once
#include "SDL.h"

class Wall
{
public:
	Wall(float x, float y, float angle);
	~Wall();

	void Update();
	void Render();
	SDL_Rect hitbox_;


private:
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Texture* texture;
	float angle_;

	int a = 0;
};