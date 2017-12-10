#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include "prisoner.h"
#include "wall.h"

class Level {

public:
	std::vector<Enemy*> enemies;
	Player* player;
	Prisoner* prisoner;
	Wall* wall;
	void Load(const char* lvl);
	void Reset(const char* lvl);

	void Clean();






};