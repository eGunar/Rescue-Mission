#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameTime = 1000 / FPS;


	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double dt = 0;

	game = new Game();

	game->Init("Rescue Mission", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running())
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		dt = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() ) * 0.001;


		game->HandleEvents();
		game->Update(dt);
		game->Render();


		if (frameTime > dt)
		{
			SDL_Delay(frameTime - dt);
		}
	}

	game->Clean();

	return 0;
}