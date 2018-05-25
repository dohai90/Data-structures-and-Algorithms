/*
 * FibProgression.h
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#ifndef FIBPROGRESSION_H_
#define FIBPROGRESSION_H_

#include "Progression.h"

class FibProgression: public Progression{
public:
	FibProgression(long s=1);
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long second;
	long prev;
};



#endif /* FIBPROGRESSION_H_ */
