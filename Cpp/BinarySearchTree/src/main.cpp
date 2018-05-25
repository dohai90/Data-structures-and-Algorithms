//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "BinarySearchTree.hpp"
using namespace std;

int main() {

	BST<Entry<int, int> > bst;

	for(int i=0; i < 10; i++){
		int key = rand() % 100;
		int val = i + 10;
		bst.insert(key, val);
		cout << "iter: " << i << "key: " << key << endl;
	}

	BST<Entry<int, int> >::Iterator iter;
	cout << "BST has " << bst.size() << " nodes" << endl;
	for(iter=bst.begin(); !(iter==bst.end()); ++iter){
		cout << "(" <<(*iter).key() << "," << (*iter).value() << ")" << endl;
	}

	return 0;
}
