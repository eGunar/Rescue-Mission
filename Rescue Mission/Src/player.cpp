#include "player.h"


Player::Player(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/player.png");
	x_ = x;
	y_ = y;

	srcRect.h = 44;
	srcRect.w = 44;
	srcRect.x = 44;
	srcRect.y = 44;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

}

Player::~Player()
{
}

void Player::HandleEvents(const SDL_Event& event)
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
		srcRect.x = 44;
		srcRect.y = 0;
		x_ = x_ - speed_;
	}
	else if (movingRight)
	{
		srcRect.x = 44;
		srcRect.y = 44;
		x_ = x_ + speed_;
	}
	else if (movingUp)
	{
		srcRect.x = 0;
		srcRect.y = 44;
		y_ = y_ - speed_;
	}
	else if (movingDown)
	{
		srcRect.x = 0;
		srcRect.y = 0;
		y_ = y_ + speed_;
	}


	destRect.x = x_;
	destRect.y = y_;
	
}

void Player::Render()
{
	TextureManager::Draw(texture, srcRect, destRect);
}
