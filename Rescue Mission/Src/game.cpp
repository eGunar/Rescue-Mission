#include "game.h"
#include "rapidjson/document.h"
Player* player;
Prisoner* prisoner;
SDL_Renderer* Game::renderer = nullptr;
using namespace rapidjson;

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
	LoadLevel();
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
	for (auto& enemy : enemies)
	{
		enemy->Update(dt);
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render();
	prisoner->Render();
	for (auto& enemy : enemies)
	{
		enemy->Render();
	}
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	for (auto& enemy : enemies)
	{
		delete enemy;
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game quit..\n";
}

void Game::LoadLevel()
{
	std::ifstream t("Levels/level_1.json");
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	Document document;
	document.Parse(str.c_str());

	for (auto& guard : document["guards"].GetArray())
	{
		std::vector <Point> points;
		for (auto& point : guard["points"].GetArray())
		{
			points.push_back(Point(point["x"].GetFloat(), point["y"].GetFloat()));
		}
		enemies.push_back( new Enemy(points, guard["speed"].GetFloat()));
	}
}
