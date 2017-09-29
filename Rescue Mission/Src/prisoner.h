#pragma once
#include "game.h"


class Prisoner
{
public:
	Prisoner(int x, int y);
	~Prisoner();

	void Update();
	void Render();



private:
	SDL_Rect srcRect, destRect;
	SDL_Texture* texture;
};