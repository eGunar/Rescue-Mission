#include "enemy.h"


Enemy::Enemy(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/enemy.png");
	pos_.x_ = x;
	pos_.y_ = y;
	start_pos_ = pos_;

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

	pos_ = pos_.AddVector(v_);


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
		v_.x_ = 0 * speed_;
		v_.y_ = 1 * speed_;
		srcRect.x = 0;
		srcRect.y = 0;
	}
	else if (direction == 'u')
	{
		v_.x_ = 0 * speed_;
		v_.y_ = -1 * speed_;
		srcRect.x = 0;
		srcRect.y = 44;

	}
	else if (direction == 'l')
	{
		v_.x_ = -1 * speed_;
		v_.y_ = 0 * speed_;
		srcRect.x = 44;
		srcRect.y = 0;

	}
	else if (direction == 'r')
	{
		v_.x_ = 1 * speed_;
		v_.y_ = 0 * speed_;
		srcRect.x = 44;
		srcRect.y = 44;

	}
}


void Enemy::CirclePattern()
{
	//a++;
	std::cout << pos_.x_ << pos_.y_ << std::endl;
	std::cout << start_pos_.x_ << start_pos_.y_ << std::endl;
	if ((pos_.x_ == start_pos_.x_) && (pos_.y_ == start_pos_.y_))
	{
		ChangeDir('u');
	}

	else if ((pos_.x_ == start_pos_.x_) && (pos_.y_ == start_pos_.y_ - distance))
	{
		ChangeDir('r');
	}

	else if ((pos_.x_ == start_pos_.x_ + distance) && (pos_.y_ == start_pos_.y_ - distance))
	{
		ChangeDir('d');
	}
	else if ((pos_.x_ == start_pos_.x_ + distance) && (pos_.y_ == start_pos_.y_))
	{
		ChangeDir('l');	
	}

//	else
	//{
		//vy_ = 0;
	//	vx_ = 0;
	//}


}

