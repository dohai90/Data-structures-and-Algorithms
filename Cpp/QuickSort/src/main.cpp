//============================================================================
// Name        : QuickSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "QuickSort.hpp"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	vector<int> a;
	for(unsigned int i=0; i<20; i++){
		int num = rand() % 100;
		a.push_back(num);
	}

	cout << "Vector before sorting:" << endl;
	for(unsigned int i=0; i<a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;

	Comparator<int> less;
	Quick<int, Comparator<int> >::sort(a, less);

	cout << "Vector after sorting:" << endl;
	for(unsigned int i=0; i<a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
