#include "wall.h"
#include "texturemanager.h"
#include <iostream>

Wall::Wall(float x, float y, float angle)
{
	texture = TextureManager::LoadTexture("assets/laser3.png");
	srcRect.h = 17;
	srcRect.w = 98;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

	angle_ = angle;
	if (angle_ == 0)
	{
		hitbox_.x = destRect.x + 16;
		hitbox_.y = destRect.y + 7;
		hitbox_.w = 66;
		hitbox_.h = 3;
	}
	else if (angle_ == 90)
	{
		hitbox_.x = destRect.x + destRect.w / 2 + 7;
		hitbox_.y = destRect.y - destRect.h / 2 - 16;
		hitbox_.w = 3;
		hitbox_.h = 66;
	}
}

Wall::~Wall()
{
}

void Wall::Update()
{
	a++;
	if (a == 6)
	{
		srcRect.y += 17;
		a = 0;
	}
	if (srcRect.y >= 17*6)
	{
		srcRect.y = 0;
	}
}

void Wall::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, angle_);
}
