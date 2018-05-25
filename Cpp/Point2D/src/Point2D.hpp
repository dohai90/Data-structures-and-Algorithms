/*
 * Point2D.hpp
 *
 *  Created on: May 11, 2018
 *      Author: dohai90
 */

#ifndef POINT2D_HPP_
#define POINT2D_HPP_

#include <iostream>

class Point2D {
private:
	float x;
	float y;
public:
	Point2D(float _x=0.0, float _y=0.0)
		: x(_x), y(_y) {}
	float getX() const { return x; }
	float getY() const { return y; }
};

class LeftRight {
public:
	bool operator()( Point2D p, const Point2D& q) const {

		return p.getX() > q.getX();
	}
};

class BottomTop {
public:
	bool operator()(const Point2D& p, const Point2D& q) const {
		return p.getY() < q.getY();
	}
};


#endif /* POINT2D_HPP_ */
