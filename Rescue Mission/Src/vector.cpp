#include "vector.h"
#include <iostream>
Point Point::AddVector(Vector v)
{
	Point p2;
	p2.x_ = x_ + v.x_;
	p2.y_ = y_ + v.y_;
	
	return p2;
}

float Point::Distance(Point a, Point b)
{
	float dx = a.x_ - b.x_;
	float dy = a.y_ - b.y_;

	return sqrt(dx*dx + dy*dy);
}

float Vector::Length()
{
	return sqrtf(x_ * x_ + y_ *y_);
}
