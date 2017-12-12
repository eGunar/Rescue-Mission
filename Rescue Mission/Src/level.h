#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include "prisoner.h"
#include "wall.h"

class Level {

public:
	std::vector<Enemy*> enemies;
	std::vector<Wall*> walls;
	Player* player;
	Prisoner* prisoner;
	void Load(const char* lvl);
	void Reset(const char* lvl);

	void Clean();






};