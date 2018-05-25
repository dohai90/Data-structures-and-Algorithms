/*
 * Progression.h
 *
 *  Created on: Apr 30, 2018
 *      Author: dohai90
 */

#ifndef PROGRESSION_H_
#define PROGRESSION_H_

class Progression{
public:
	Progression(long f=0): first(f), cur(f){}
	virtual ~Progression(){}
	void printProgression(int n);
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long first;
	long cur;
};



#endif /* PROGRESSION_H_ */
