#include "player.h"

Player::Player(const char * image, int x, int y)
{
	xpos = x;
	ypos = y;
}

Player::~Player()
{
}

void Player::HandleEvents(SDL_Event event)
{
	switch (event.type)
	{
	case(SDL_KEYDOWN):
		switch (event.key.keysym.sym)
		{
		case(SDLK_a):
			movingLeft = true;
			break;
		case(SDLK_d):
			movingRight = true;
			break;
		case(SDLK_w):
			movingUp = true;
			break;
		case(SDLK_s):
			movingDown = true;
			break;

		default:
			break;
		}
		break;

	case(SDL_KEYUP):
		switch (event.key.keysym.sym)
		{
		case(SDLK_a):
			movingLeft = false;
			break;
		case(SDLK_d):
			movingRight = false;
			break;
		case(SDLK_w):
			movingUp = false;
			break;
		case(SDLK_s):
			movingDown = false;
			break;

		default:
			break;
		}
		break;
	};
}

void Player::Update()
{
	if (movingLeft)
	{
		xpos = xpos - speed;
		std::cout << xpos << std::endl;
	}
	else if (movingRight)
	{
		xpos = xpos + speed;
		std::cout << xpos << std::endl;
	}
	else if (movingUp)
	{
		ypos = ypos - speed;
		std::cout << ypos << std::endl;
	}
	else if (movingDown)
	{
		ypos = ypos + speed;
		std::cout << ypos << std::endl;
	}
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void Player::Render()
{
}
