#pragma once
#include "game.h"

class Enemy
{
public:
	Enemy(int x, int y);
	~Enemy();

	void Update();
	void Render();
	int x_;
	int y_;

private:
	int width_ = 44;
	int height_ = 44;
	int speed_ = 5;
	int vy_ = 1;
	int vx_ = 0;
	bool circle_active_ = false;

	void ChangeDir(const char direction);
	void CirclePattern();
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};