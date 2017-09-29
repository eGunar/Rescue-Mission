#pragma once
#include "game.h"



class Player
{
public:
	Player(int x, int y);
	~Player();

	void HandleEvents(SDL_Event event);
	void Update();
	void Render();
	int xpos;
	int ypos;

private:
	int width;
	int height;
	int speed = 5;

	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

};