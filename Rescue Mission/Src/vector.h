#pragma once
#include <cmath>

class Vector 
{
public:
	float x_;
	float y_;

	float Length();
};

class Point
{
public:
	Point AddVector(Vector v);

	float x_;
	float y_;
};