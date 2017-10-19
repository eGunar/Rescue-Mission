#include "game.h"

Player* player;
Prisoner* prisoner;
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
	player = new Player(400, 340);
	prisoner = new Prisoner(1000, 340);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	player->HandleEvents(event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update()
{
	player->Update();
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render();
	prisoner->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game quit..\n";
}
