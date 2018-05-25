//============================================================================
// Name        : CLinkedList.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CLinkedList.hpp"

using namespace std;

int main() {
	cout << "!!!Digital Audio Player!!!" << endl;
	CLinkedList<string> playList;
	playList.add("S");
	playList.show();

	playList.add("L");
	playList.show();

	playList.add("J");
	playList.show();

	playList.advance();
	playList.advance();
	playList.remove();
	playList.add("D");
	playList.show();

	return EXIT_SUCCESS;
}
