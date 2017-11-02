#include "vector.h"
#include <iostream>
Point Point::AddVector(Vector v)
{
	Point p2;
	p2.x_ = x_ + v.x_;
	p2.y_ = y_ + v.y_;
	
	return p2;
}
