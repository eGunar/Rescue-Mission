#include "prisoner.h"
#include "texturemanager.h"


Prisoner::Prisoner(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/prisoner.png");
	destRect.x = x;
	destRect.y = y;
	srcRect.h = 46;
	srcRect.w = 82;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;

	hitbox_ = destRect;
}

Prisoner::~Prisoner()
{
}

void Prisoner::Update()
{

}

void Prisoner::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, 0);
}
