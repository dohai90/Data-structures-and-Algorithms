//============================================================================
// Name        : MyListPQ.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ListPQ.hpp"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ListPQ<int, Less<int> > pq;
	for(int i=10; i>=0; i--)
		pq.insert(i);

	cout << "number of elements: " << pq.size() << endl;
	while(!pq.empty()){
		cout << pq.min() << endl;
		pq.removeMin();
	}

	return 0;
}
