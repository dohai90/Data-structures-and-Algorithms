/*
 * FibProgression.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#include "FibProgression.h"

FibProgression::FibProgression(long s):Progression(), second(s), prev(second - first){}

long FibProgression::firstValue(){
	cur = first;
	prev = second - first;
	return cur;
}

long FibProgression::nextValue(){
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}


