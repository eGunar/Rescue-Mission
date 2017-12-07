#include "game.h"


SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized...\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created\n";
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 8, 166, 19, 255);
			std::cout << "Renderer created\n";
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	lvl = new Level();
	lvl->Load("Levels/level_1.json");
	
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	lvl->player->HandleEvents(event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(double dt)
{
	lvl->player->Update(dt);
	for (auto& enemy : lvl->enemies)
	{
		enemy->Update(dt);
		if (SDL_HasIntersection(&lvl->player->hitbox_, &enemy->hitbox_))
		{
			lvl->Reset("Levels/level_1.json");
		}
	}
	if (SDL_HasIntersection(&lvl->player->hitbox_, &lvl->prisoner->hitbox_))
	{
		lvl->Reset("Levels/level_2.json");
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	lvl->player->Render();
	lvl->prisoner->Render();
	for (auto& enemy : lvl->enemies)
	{
		enemy->Render();
	}
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	lvl->Clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game quit..\n";
}