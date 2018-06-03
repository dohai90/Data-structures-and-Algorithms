/*
 * MergeSort.hpp
 *
 *  Created on: 2 Jun 2018
 *      Author: dohai90
 */

#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

#include <list>

template <typename E>
class Comparator{
public:
	bool operator()(const E& e1, const E& e2) const{
		return e1 < e2;
	}
};

template <typename E, typename C>
void merge(std::list<E>& S1, std::list<E>& S2, std::list<E>& S, const C& less){
	typedef typename std::list<E>::iterator Itor;
	Itor p1 = S1.begin();
	Itor p2 = S2.begin();
	while (p1 != S1.end() && p2 != S2.end()){
		if(less(*p1, *p2)){
			S.push_back(*p1++);
		}else {
			S.push_back(*p2++);
		}
	}

	// copy the rest of S1 or S2 into S
	while (p1 != S1.end()){
		S.push_back(*p1++);
	}
	while (p2 != S2.end()){
		S.push_back(*p2++);
	}
}

template <typename E, typename C>
void mergeSort(std::list<E>& S, const C& less){
	typedef typename std::list<E>::iterator Itor;
	int n = S.size();
	if(n<=1) return;
	std::list<E> S1, S2;
	Itor p = S.begin();

	// copy elements of S into first half S1 and second half S2
	for(int i = 0; i < n/2; i++) S1.push_back(*p++);
	for(int i = n/2; i < n; i++) S2.push_back(*p++);
	S.clear();

	// recur
	mergeSort(S1, less);
	mergeSort(S2, less);

	// merge
	merge(S1, S2, S, less);
}



#endif /* MERGESORT_HPP_ */
