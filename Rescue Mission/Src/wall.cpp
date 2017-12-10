#include "wall.h"
#include "texturemanager.h"

Wall::Wall(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/wall.png");
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
	if (a == 4)
	{
		srcRect.x += 64;
		a = 0;
	}
	if (srcRect.x >= 64*12)
	{
		srcRect.x = 0;
	}
}

void Wall::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, 0);
}
