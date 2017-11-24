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
	if (!points_.empty())
	{
		Point& next_point = points_[current_point_];
		Vector to_point = Vector(next_point.x_ - pos_.x_, next_point.y_ - pos_.y_);
		float distance_to_point = to_point.Length();
		Vector motion = to_point;
		motion.x_ = motion.x_ / distance_to_point * speed_ * dt;
		motion.y_ = motion.y_ / distance_to_point * speed_ * dt;
		float motion_distance = motion.Length();

		if (motion_distance >= distance_to_point)
		{
			pos_ = next_point;

			current_point_ = (current_point_ + 1) % points_.size();
		}
		else
		{
			pos_ = pos_.AddVector(motion);
		}
	}

	destRect.y = pos_.y_;
	destRect.x = pos_.x_;

}

void Enemy::Render()
{
	TextureManager::Draw(texture, srcRect, destRect);
}
