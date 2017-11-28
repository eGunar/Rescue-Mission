#pragma once
#include "game.h"
#include "vector.h"
#include <vector>

class Enemy
{
public:
	Enemy(std::vector<Point> points, float speed);
	~Enemy();

	void Update(double dt);
	void Render();
	Point pos_;



private:
	std::vector<Point> points_;
	float speed_;
	int width_ = 44;
	int height_ = 44;
	bool circle_active_ = false;
	int a = 0;
	Vector v_;
	Point start_pos_;
	float distance = 200.f;

	Point turn_up;
	Point turn_down;
	Point turn_right;
	Point turn_left;

	int current_point_ = 1;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	double angle_;

};

