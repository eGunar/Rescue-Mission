#include "prisoner.h"

Prisoner::Prisoner(int x, int y)
{
	texture = TextureManager::LoadTexture("assets/prisoner.png");
	destRect.x = x;
	destRect.y = y;
	srcRect.h = 46;
	srcRect.w = 82;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.h = 46;
	destRect.w = 82;
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
