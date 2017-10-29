#pragma once
#include "game.h"



class Player
{
public:
	Player(int x, int y);
	~Player();

	void HandleEvents(const SDL_Event& event);
	void Update();
	void Render();
	int x_;
	int y_;

private:
	int width_;
	int height_;
	int speed_ = 5;

	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;

	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

};