#include "level.h"
#include "rapidjson/document.h"
#include <fstream>
#include <streambuf>

using namespace rapidjson;


void Level::Load(const char* lvl)
{
	std::ifstream t(lvl);
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
		enemies.push_back(new Enemy(points, guard["speed"].GetFloat()));
	}
	player = new Player(400.f, 340.f);
	prisoner = new Prisoner(1000, 340);
}

void Level::Reset(const char * lvl)
{
	enemies.clear();
	player = nullptr;
	prisoner = nullptr;
	Load(lvl);
}

void Level::Clean()
{
	for (auto& enemy : enemies)
	{
		delete enemy;
	}
	delete player;
	delete prisoner;
}
