#include "game.h"

Player* player;
Prisoner* prisoner;
Enemy* enemy;
Enemy* enemy2;
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
	player = new Player(400.f, 340.f);
	prisoner = new Prisoner(1000, 340);
	std::vector <Point> points;

	points.push_back(Point(700, 100));
	points.push_back(Point(700, 600));
	points.push_back(Point(500, 600));
	points.push_back(Point(500, 100));
	enemy = new Enemy(points, 600);

	std::vector <Point> points2;

	points2.push_back(Point(500, 300));
	points2.push_back(Point(400, 200));
	points2.push_back(Point(300, 600));
	points2.push_back(Point(900, 100));
	enemy2 = new Enemy(points2, 300);

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

void Game::Update(double dt)
{
	player->Update(dt);
	enemy->Update(dt);
	enemy2->Update(dt);
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render();
	prisoner->Render();
	enemy->Render();
	enemy2->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game quit..\n";
}
