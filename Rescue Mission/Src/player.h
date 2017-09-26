#pragma once
#include "game.h"


class Player
{
public:
	Player(const char* image, int x, int y);
	~Player();

	void HandleEvents(SDL_Event event);
	void Update();
	void Render();

private:
	int xpos;
	int ypos;
	int width;
	int height;
	int speed = 5;
	SDL_Texture* texture;

	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;

	SDL_Texture* playerImage;
	SDL_Rect srcRect, destRect;

};