#include "enemy.h"


Enemy::Enemy(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/enemy.png");
	x_ = x;
	y_ = y;

	srcRect.h = 44;
	srcRect.w = 44;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x_;
	destRect.y = y_;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
//	if (y_ == 0)
//	{
//		ChangeDir('l');
//	}
//	else if (y_ + height_ >= 720)
//	{
//		ChangeDir('d');
//	}
	y_ = y_ + 1 * speed_ * vy_;
	x_ = x_ + 1 * speed_ * vx_;
	destRect.y = y_;
	destRect.x = x_;
	if (!circle_active_)
	{
		CirclePattern();
	}

}

void Enemy::Render()
{
	TextureManager::Draw(texture, srcRect, destRect);
}


void Enemy::ChangeDir(const char direction)
{
	if (direction == 'd')
	{
		std::cout << "down" << std::endl;
		vy_ = vy_ * 1;
		vx_ = 0;
		srcRect.x = 0;
		srcRect.y = 0;
	}
	else if (direction == 'u')
	{
		std::cout << "up" << std::endl;
		vy_ = -1;
		vx_ = 0;
		srcRect.x = 0;
		srcRect.y = 44;

	}
	else if (direction == 'l')
	{
		std::cout << "left" << std::endl;
		vy_ = 0;
		vx_ = -1;
		srcRect.x = 44;
		srcRect.y = 0;

	}
	else if (direction == 'r')
	{
		std::cout << "right" << std::endl;
		vy_ = 0;
		vx_ = 1;
		srcRect.x = 44;
		srcRect.y = 44;

	}
	vy_ = vy_ * -1;
	if (vy_ < 0)
	{
		srcRect.x = 0;
		srcRect.y = 44;
	}
}

void Enemy::CirclePattern()
{
	circle_active_ = true;
	int walk_amount = 3;
	int start_x = x_;
	int start_y = y_;

	ChangeDir('r');

	



}