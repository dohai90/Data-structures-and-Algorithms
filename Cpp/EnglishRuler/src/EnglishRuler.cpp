//============================================================================
// Name        : EnglishRuler.cpp
// Author      : dohai90
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void drawOneTick(int tickLength, int tickLabel = -1){
	for(int i=0; i<tickLength; i++)
		cout<< "-";
	if(tickLabel >= 0) cout << " " << tickLabel;
	cout << endl;
}

void drawTicks(int tickLength){
	if(tickLength > 0){
		drawTicks(tickLength - 1);
		drawOneTick(tickLength);
		drawTicks(tickLength - 1);
	}
}

void drawRuler(int nInches, int majorLength){
	drawOneTick(majorLength, 0);
	for(int i=1; i<=nInches; i++){
		drawTicks(majorLength-1);
		drawOneTick(majorLength, i);
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int nInches = 1;
	int majorLength = 5;
	drawRuler(nInches, majorLength);
	return 0;
}
