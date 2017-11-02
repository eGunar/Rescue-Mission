#include "enemy.h"


Enemy::Enemy(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/enemy.png");
	pos_.x_ = x;
	pos_.y_ = y;

	srcRect.h = 44;
	srcRect.w = 44;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = pos_.x_;
	destRect.y = pos_.y_;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

}

Enemy::~Enemy()
{
}

void Enemy::Update(double dt)
{
//	if (y_ == 0)
//	{
//		ChangeDir('l');
//	}
//	else if (y_ + height_ >= 720)
//	{
//		ChangeDir('d');
//	}
	CirclePattern();
	pos_.y_ = pos_.y_ + vy_ * dt;
	pos_.x_ = pos_.x_ + vx_ * dt;

	//std::cout << "x " << int(vx_*dt*10) << " y " << int(vy_*dt*10) << " a " << a << std::endl;
	
	destRect.y = pos_.y_;
	destRect.x = pos_.x_;




}

void Enemy::Render()
{
	TextureManager::Draw(texture, srcRect, destRect);
}


void Enemy::ChangeDir(const char direction)
{
	if (direction == 'd')
	{
		vy_ = 1 * speed_;
		vx_ = 0 * speed_;
		srcRect.x = 0;
		srcRect.y = 0;
	}
	else if (direction == 'u')
	{
		vy_ = -1 * speed_;
		vx_ = 0 * speed_;
		srcRect.x = 0;
		srcRect.y = 44;

	}
	else if (direction == 'l')
	{
		vy_ = 0 * speed_;
		vx_ = -1 * speed_;
		srcRect.x = 44;
		srcRect.y = 0;

	}
	else if (direction == 'r')
	{
		vy_ = 0 * speed_;
		vx_ = 1 * speed_;
		srcRect.x = 44;
		srcRect.y = 44;

	}
}


void Enemy::CirclePattern()
{
	a++;

	if (a < 40)
	{
		ChangeDir('u');
	}

	else if ((a > 40) && (a < 80))
	{
		ChangeDir('r');
	}

	else if (a > 80 && a < 120)
	{
		ChangeDir('d');
	}
	else if (a > 120 && a < 159)
	{
		ChangeDir('l');
	}
	else if (a > 159)
	{
		a = 0;
	}
//	else
	//{
		//vy_ = 0;
	//	vx_ = 0;
	//}


}

