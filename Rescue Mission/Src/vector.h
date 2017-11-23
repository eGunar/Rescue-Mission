#pragma once
#include <cmath>

class Vector 
{
public:
	Vector(float x, float y)
	{
		x_ = x;
		y_ = y;
	}
	Vector() {}
	float x_;
	float y_;

	float Length();
};

class Point
{
public:
	Point(float x, float y) 
	{
		x_ = x;
		y_ = y;
	}
	Point() {}
	Point AddVector(Vector v);
	static float Distance(Point a, Point b);
	float x_;
	float y_;
};