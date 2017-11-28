#include "player.h"


Player::Player(float x, float y)
{
	texture = TextureManager::LoadTexture("assets/player.png");

	pos_.x_ = x;
	pos_.y_ = y;
	angle_ = 180;

	srcRect.h = 44;
	srcRect.w = 44;
	srcRect.x = 0;
	srcRect.y = 0;

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

void Player::Update(double dt)
{
	if (movingLeft)
	{
		ChangeDir('l');
	}
	else if (movingRight)
	{
		ChangeDir('r');
	}
	else if (movingUp)
	{
		ChangeDir('u');
	}
	else if (movingDown)
	{
		ChangeDir('d');
	}
	else
	{
		v_.x_ = 0;
		v_.y_ = 0;
	}
	Vector motion = v_;
	motion.x_ *= dt;
	motion.y_ *= dt;
	pos_ = pos_.AddVector(motion);

	destRect.x = pos_.x_;
	destRect.y = pos_.y_;

	
}

void Player::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, angle_);
}



void Player::ChangeDir(const char direction)
{
	if (direction == 'd')
	{
		v_.x_ = 0 * speed_;
		v_.y_ = 1 * speed_;
		angle_ = 270;
	}
	else if (direction == 'u')
	{
		v_.x_ = 0 * speed_;
		v_.y_ = -1 * speed_;
		angle_ = 90;

	}
	else if (direction == 'l')
	{
		v_.x_ = -1 * speed_;
		v_.y_ = 0 * speed_;
		angle_ = 0;

	}
	else if (direction == 'r')
	{
		v_.x_ = 1 * speed_;
		v_.y_ = 0 * speed_;
		angle_ = 180;

	}
}