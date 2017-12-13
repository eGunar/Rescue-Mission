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

	if (document.HasMember("guards"))
	{
		for (auto& guard : document["guards"].GetArray())
		{
			std::vector <Point> points;
			for (auto& point : guard["points"].GetArray())
			{
				points.push_back(Point(point["x"].GetFloat(), point["y"].GetFloat()));
			}
			enemies.push_back(new Enemy(points, guard["speed"].GetFloat()));
		}
	}
	if (document.HasMember("walls"))
	{
		for (auto& wall : document["walls"].GetArray())
		{
			walls.push_back(new Wall(wall["x"].GetFloat(), wall["y"].GetFloat(), wall["rotation"].GetFloat()));
		}
	}
	player = new Player(100.f, 340.f);
	prisoner = new Prisoner(1000, 340);

}

void Level::Reset(const char * lvl)
{
	Clean();
	enemies.clear();
	walls.clear();
	Load(lvl);
}

void Level::Clean()
{
	for (auto& enemy : enemies)
	{
		delete enemy;
	}
	for (auto& wall : walls)
	{
		delete wall;
	}
	delete player;
	delete prisoner;
}
