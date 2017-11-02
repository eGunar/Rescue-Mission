#pragma once


class Vector 
{
public:
	float x_;
	float y_;

};

class Point
{
public:
	Point AddVector(Vector v);

	float x_;
	float y_;
};