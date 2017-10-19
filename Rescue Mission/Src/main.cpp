#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int dt = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->Init("Rescue Mission", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;
		if (dt > frameTime)
		{
			SDL_Delay(dt - frameTime);
		}
	}

	game->Clean();

	return 0;
}