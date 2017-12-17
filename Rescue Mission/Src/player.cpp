#include "player.h"
#include "game.h"
#include "texturemanager.h"

Player::Player(float x, float y)
{
	texture = TextureManager::LoadTexture("assets/spaceman.png");

	pos_.x_ = x;
	pos_.y_ = y;
	angle_ = 180;

	srcRect.h = 65;
	srcRect.w = 54;
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
		velocity_.x_ = -speed_;
		velocity_.y_ = 0;
		angle_ = 0;
	}
	else if (movingRight)
	{
		velocity_.x_ = speed_;
		velocity_.y_ = 0;
		angle_ = 180;
	}
	else if (movingUp)
	{
		velocity_.x_ = 0;
		velocity_.y_ = -speed_;
		angle_ = 90;
	}
	else if (movingDown)
	{
		velocity_.x_ = 0;
		velocity_.y_ = speed_;
		angle_ = 270;
	}
	else
	{
		velocity_.x_ = 0;
		velocity_.y_ = 0;
	}

	velocity_.x_ = velocity_.x_ * dt;
	velocity_.y_ = velocity_.y_ * dt;

	pos_ = pos_.AddVector(velocity_);
	
	destRect.x = pos_.x_;
	destRect.y = pos_.y_;
	hitbox_ = destRect;

	if (velocity_.Length() > 0)
	{
		idle_animation = 0;
		srcRect.y = 0; 
		animation++;
		if (animation == 6)
		{
			srcRect.x += srcRect.w;
			animation = 0;
		}
		if (srcRect.x >= srcRect.w * 8)
		{
			srcRect.x = 0;
		}
	}
	else
	{
		idle_animation++;
		if (idle_animation >= 120)
		{
			srcRect.y = 65;
			animation++;
			if (animation == 6)
			{
				srcRect.x += srcRect.w;
				animation = 0;
			}
			if (srcRect.x >= srcRect.w * 14)
			{
				srcRect.x = 0;
				idle_animation = 0;
			}
		}
		else
		{
			srcRect.x = 0;
		}
	}
	if (pos_.x_ >= 1280 - destRect.w)
	{
		pos_.x_ = 1280 - destRect.w;
	}
	else if (pos_.x_ <= 0)
	{
		pos_.x_ = 0;
	}
	if (pos_.y_ >= 720 - destRect.h)
	{
		pos_.y_ = 720 - destRect.h;
	}
	else if (pos_.y_ <= 0)
	{
		pos_.y_ = 1;
	}
	
}

void Player::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, angle_);
}

