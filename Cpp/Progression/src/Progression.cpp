//============================================================================
// Name        : Progression.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Progression.h"

using namespace std;

void Progression::printProgression(int n){
	cout << firstValue();
	for(int i=2; i<=n; i++){
		cout << " " << nextValue();
	}
	cout << endl;
}

long Progression::firstValue(){
	cur = first;
	return cur;
}

long Progression::nextValue(){

	return ++cur;
}
