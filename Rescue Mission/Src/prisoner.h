#pragma once
#include "game.h"


class Prisoner
{
public:
	Prisoner(int x, int y);
	~Prisoner();

	void Update();
	void Render();
	SDL_Rect hitbox_;


private:
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Texture* texture;

};