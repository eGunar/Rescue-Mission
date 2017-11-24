#pragma once
#include "game.h"
#include "vector.h"
#include <vector>

class Enemy
{
public:
	Enemy(int x, int y);
	~Enemy();

	void Update(double dt);
	void Render();
	Point pos_;
	std::vector<Point> points_;

private:
	int width_ = 44;
	int height_ = 44;
	float speed_ = 300.f;
	bool circle_active_ = false;
	int a = 0;
	Vector v_;
	Point start_pos_;
	float distance = 200.f;

	Point turn_up;
	Point turn_down;
	Point turn_right;
	Point turn_left;

	int current_point_ = 0;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};

