/*
 * main.cpp
 *
 *  Created on: May 3, 2018
 *      Author: dohai90
 */

#include <string>

#include "SLinkedList.hpp"



using namespace std;
int main(){
	LinkedListStack<int> stack;
	LinkedListStack<string> stringstack;

	for(int i=0; i<10; i++){
		stack.push(i);
	}

	stack.show();

	stringstack.push("hello");
	stringstack.push("world");

	stringstack.show();


	LinkedListQueue<string> q;
	q.enqueue("hello");
	q.enqueue("world");

	q.show();

	return EXIT_SUCCESS;
}

