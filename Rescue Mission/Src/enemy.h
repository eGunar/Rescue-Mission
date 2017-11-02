#pragma once
#include "game.h"

class Enemy
{
public:
	Enemy(int x, int y);
	~Enemy();

	void Update(double dt);
	void Render();
	Point pos_;
	float x_;
	float y_;

private:
	int width_ = 44;
	int height_ = 44;
	float speed_ = 500.f;
	float vy_ = 0.f;
	float vx_ = 0.f;
	bool circle_active_ = false;
	int a = 0;

	void ChangeDir(const char direction);
	void CirclePattern();

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};

