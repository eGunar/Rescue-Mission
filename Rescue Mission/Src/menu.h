#pragma once

class Menu{
public:
	Menu();
	~Menu();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update(double dt);
	void Render();
	void Clean();
};