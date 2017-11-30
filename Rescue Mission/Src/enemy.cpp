#include "enemy.h"


Enemy::Enemy(std::vector<Point> points, float speed)
{
	texture = TextureManager::LoadTexture("assets/enemy.png");
	points_ = points;
	speed_ = speed;
	if (!points_.empty())
	{
		pos_ = points_[0];
		angle_ = Point::Get_Angle(pos_, Point(points_[1].x_, points_[1].y_));
	}

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
			angle_ = Point::Get_Angle(pos_, Point(points_[current_point_].x_, points_[current_point_].y_));
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
	TextureManager::Draw(texture, srcRect, destRect, angle_);
}
