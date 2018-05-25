/*
 * GeoProgression.h
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#ifndef GEOPROGRESSION_H_
#define GEOPROGRESSION_H_

#include "Progression.h"

class GeoProgression: public Progression{
public:
	GeoProgression(long b=2);
protected:
	virtual long nextValue();
protected:
	long base;
};



#endif /* GEOPROGRESSION_H_ */
