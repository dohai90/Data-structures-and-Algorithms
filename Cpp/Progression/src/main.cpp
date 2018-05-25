/*
 * main.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#include "Progression.h"
#include "ArithProgression.h"
#include "GeoProgression.h"
#include "FibProgression.h"

#include<cstdlib>
#include<iostream>
using namespace std;

int main(){
	Progression* prog;

	cout << "Arithmetic progression with default increment: \n";
	prog = new ArithProgression();
	prog->printProgression(10);
	cout << "Arithmetic progression with increment 5: \n";
	prog = new ArithProgression(5);
	prog->printProgression(10);

	cout << "Geometric progression with default base: \n";
	prog = new GeoProgression();
	prog->printProgression(10);
	cout << "Geometric progression with base 3: \n";
	prog = new GeoProgression(3);
	prog->printProgression(10);

	cout << "Fibonacci progression: \n";
	prog = new FibProgression();
	prog->printProgression(10);

	return EXIT_SUCCESS;
}

