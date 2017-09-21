#pragma once
#include "game.h"


class Player
{
public:
	Player(const char* image, int x, int y);
	~Player();

	void HandleEvents();
	void Update();
	void Render();

private:
	int xpos;
	int ypos;
	int width;
	int height;

	SDL_Texture* playerImage;
	SDL_Rect srcRect, destRect;

};