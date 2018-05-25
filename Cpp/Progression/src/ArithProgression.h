/*
 * ArithProgression.h
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#ifndef ARITHPROGRESSION_H_
#define ARITHPROGRESSION_H_

#include "Progression.h"

class ArithProgression : public Progression{
public:
	ArithProgression(long i=1);
protected:
	virtual long nextValue();
protected:
	long inc;
};



#endif /* ARITHPROGRESSION_H_ */
