//============================================================================
// Name        : MergeSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MergeSort.hpp"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	list<int> S;
	typedef list<int>::iterator Itor;
	for(int i=0; i<20; i++){
		int num = rand() % 100;
		S.push_back(num);
	}

	cout << "Before sorting:" << endl;
	for(Itor p=S.begin(); p!=S.end(); ++p){
		cout << *p << " ";
	}
	cout << endl;

	cout << "After sorting:" << endl;
	Comparator<int> less;
	mergeSort(S, less);
	for(Itor p=S.begin(); p!=S.end(); ++p){
		cout << *p << " ";
	}
	cout << endl;

	return 0;
}
