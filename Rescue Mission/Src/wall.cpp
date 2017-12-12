#include "wall.h"
#include "texturemanager.h"

Wall::Wall(float x, float y)
{
	texture = TextureManager::LoadTexture("assets/wall2.png");
	srcRect.h = 32;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

	hitbox_ = destRect;
}

Wall::~Wall()
{
}

void Wall::Update()
{
	a++;
	if (a == 6)
	{
		srcRect.x += 64;
		a = 0;
	}
	if (srcRect.x >= 64*3)
	{
		srcRect.x = 0;
	}
}

void Wall::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, 0);
}
