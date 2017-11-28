#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "player.h"
#include "prisoner.h"
#include "texturemanager.h"
#include "enemy.h"
#include "vector.h"
#include <vector>



class Game {

public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update(double dt);
	void Render();
	void Clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;

private:
	bool isRunning;
	SDL_Window *window;





};



