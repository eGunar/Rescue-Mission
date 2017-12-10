#pragma once
#include "SDL.h"

class Wall
{
public:
	Wall(int x, int y);
	~Wall();

	void Update();
	void Render();
	SDL_Rect hitbox_;


private:
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Texture* texture;

	int a;
};