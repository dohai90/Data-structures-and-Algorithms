/*
 * ArithProgression.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#include "ArithProgression.h"

ArithProgression::ArithProgression(long i): Progression(), inc(i){}

long ArithProgression::nextValue(){
	cur += inc;
	return cur;
}
