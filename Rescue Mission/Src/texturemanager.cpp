#include "texturemanager.h"
#include "game.h"
#include "SDL_image.h"



SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dest, double angle)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RenderCopyEx(Game::renderer, texture, &src, &dest, angle, NULL, flip);
}
