#pragma once
#include <vector>
#include "enemy.h"
#include "player.h"
#include "prisoner.h"

class Level {

public:
	std::vector<Enemy*> enemies;
	Player* player;
	Prisoner* prisoner;
	void Load(const char* lvl);
	void Reset(const char* lvl);

	void Clean();






};