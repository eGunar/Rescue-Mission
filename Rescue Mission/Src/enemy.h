#pragma once
#include "game.h"

class Enemy
{
public:
	Enemy(int x, int y);
	~Enemy();

	void Update();
	void Render();

private:
	int width_;
	int height_;
	int speed_ = 5;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};