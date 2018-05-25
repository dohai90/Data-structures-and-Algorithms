//============================================================================
// Name        : DLinkedList.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DLinkedList.hpp"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	DLinkedList<int> dll;
	for(int i=0; i<10; i++)
		dll.addBack(i);

	dll.show();

	dll.reverse(dll);
	dll.show();

	return EXIT_SUCCESS;
}
