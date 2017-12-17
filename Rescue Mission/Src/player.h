#pragma once

#include "vector.h"
#include "SDL.h"

class Player
{
public:
	Player(float x, float y);
	~Player();

	void HandleEvents(const SDL_Event& event);
	void Update(double dt);
	void Render();
	SDL_Rect hitbox_;

private:
	Point pos_;
	Vector velocity_;
	float speed_ = 300.f;
	int animation = 0;
	int idle_animation = 0;



	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	double angle_;
};
