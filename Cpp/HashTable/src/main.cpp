//============================================================================
// Name        : HashTable.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashTable.hpp"
using namespace std;

int main() {
	HashTable<string, int> ht;
	ht.put("Joe", 25);
	ht.put("Mike", 50);
	ht.put("Alice",7);
	ht.put("Bob", 36);

	for(HashTable<string, int>::Iterator p=ht.begin(); !(p==ht.end()); ++p){
		cout << "(" << (*p).key() << "," << (*p).value() << ")" << endl;
	}
	cout << endl;

	ht.put("Joe", 26);
	ht.erase("Mike");
	for(HashTable<string, int>::Iterator p=ht.begin(); !(p==ht.end()); ++p){
		cout << "(" << (*p).key() << "," << (*p).value() << ")" << endl;
	}
	return 0;
}
