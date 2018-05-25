/*
 * GeoProgression.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#include "GeoProgression.h"

GeoProgression::GeoProgression(long b):Progression(1), base(b){}

long GeoProgression::nextValue(){
	cur*=base;
	return cur;
}

