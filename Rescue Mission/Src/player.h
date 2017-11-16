#pragma once
#include "game.h"
#include "vector.h"


class Player
{
public:
	Player(float x, float y);
	~Player();

	void HandleEvents(const SDL_Event& event);
	void Update(double dt);
	void Render();
	Point pos_;

private:
	void ChangeDir(const char direction);

	Vector v_;
	int width_;
	int height_;
	float speed_ = 300.f;
	int animation_ = 0;

	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};
