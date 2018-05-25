//============================================================================
// Name        : Point2D.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include "Point2D.hpp"

using namespace std;

template <typename E, typename C>
bool isSmaller(const E& p, const E& q, const  C& isLess){

	return isLess(p, q);
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Point2D p(1.3, 5.7), q(2.5, 0.6);

	LeftRight leftRight;
	BottomTop bottomTop;
	if(isSmaller(p, q, leftRight)){
		cout << "p is at left of q" << endl;
	}else{
		cout << "p is not at left of q" << endl;
	}

	if(isSmaller(p, q, bottomTop)){
		cout << "p is at bottom of q" << endl;
	}else{
		cout << "p is not at bottom of q" << endl;
	}

	priority_queue<Point2D, vector<Point2D>, LeftRight> pq;
	pq.push(p);
	pq.push(q);
	pq.push(Point2D(8.5, 4.6));

	cout << pq.top().getX() << "," << pq.top().getY() << endl; pq.pop();
	cout << pq.top().getX() << "," << pq.top().getY() << endl; pq.pop();
	cout << pq.top().getX() << "," << pq.top().getY() << endl; pq.pop();

	return 0;
}
