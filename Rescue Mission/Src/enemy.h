#pragma once
#include "game.h"
#include "vector.h"

class Enemy
{
public:
	Enemy(int x, int y);
	~Enemy();

	void Update(double dt);
	void Render();
	Point pos_;

private:
	int width_ = 44;
	int height_ = 44;
	float speed_ = 300.f;
	bool circle_active_ = false;
	int a = 0;
	Vector v_;
	Vector motion_;
	Point start_pos_;
	float distance = 200.f;

	void ChangeDir(const char direction);
	void CirclePattern();

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};

