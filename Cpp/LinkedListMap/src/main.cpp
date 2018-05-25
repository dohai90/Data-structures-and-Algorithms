//============================================================================
// Name        : LinkedListMap.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "LinkedListMap.hpp"

using namespace std;

int main() {
	LinkedListMap<string, int> map;
	LinkedListMap<string, int>::Iterator p;

	map.insert("Rob", 28);
	map.insert("Joe", 38);
	for(LinkedListMap<string, int>::Iterator iter = map.begin(); iter != map.end(); ++iter)
		cout << "(" << iter->key() << "," << iter->value() << ")" << endl;
	cout << endl;

	map.insert("Joe", 50);
	map.insert("Sue", 75);
	for(LinkedListMap<string, int>::Iterator iter = map.begin(); iter != map.end(); ++iter)
		cout << "(" << iter->key() << "," << iter->value() << ")" << endl;
	cout << endl;

	p = map.find("Joe");
	map.erase(p);
	map.erase("Sue");
	p = map.find("Joe");
	if(p == map.end()) cout << "nonexistence" << endl;

	map.insert("Hai", 29);
	for(LinkedListMap<string, int>::Iterator iter = map.begin(); iter != map.end(); ++iter)
		cout << "(" << iter->key() << "," << iter->value() << ")" << endl;
	cout << endl;


	return 0;
}
