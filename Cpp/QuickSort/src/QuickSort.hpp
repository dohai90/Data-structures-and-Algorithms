/*
 * QuickSort.hpp
 *
 *  Created on: 3 Jun 2018
 *      Author: dohai90
 */

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <vector>
#include <algorithm>

template <typename E>
class Comparator {
public:
	bool operator()(const E& e1, const E& e2) const {return e1 < e2;}
};

template <typename E, typename C>
class Quick {
public:
	static void sort(std::vector<E>& S, const C& less);
protected:
	static void sort(std::vector<E>& S, unsigned int lo, unsigned int hi, const C& less);
	static unsigned int partition(std::vector<E>& S, unsigned int lo, unsigned int hi, const C& less);
};

template <typename E, typename C>
void Quick<E, C>::sort(std::vector<E>& S, const C& less){
	std::random_shuffle(S.begin(), S.end());
	std::cout << "Vector shuffling:" << std::endl;
	for(typename std::vector<E>::iterator p=S.begin(); p != S.end(); ++p)
		std::cout << *p << " ";
	std::cout << std::endl;
	sort(S, 0, S.size() - 1, less);
}

template <typename E, typename C>
void Quick<E, C>::sort(std::vector<E>& S, unsigned int lo, unsigned int hi, const C& less){
	if(hi <= lo) return;
	unsigned int j = partition(S, lo, hi, less);

	sort(S, lo, j-1, less);
	sort(S, j+1, hi, less);
}

template <typename E, typename C>
unsigned int Quick<E, C>::partition(std::vector<E>& S, unsigned int lo, unsigned int hi, const C& less){
	unsigned int i = lo;
	unsigned int j = hi + 1;
	E v = S[lo];
	while(true){
		while(less(S[++i], v)) if(i == hi) break;
		while(less(v, S[--j])) if(j == lo) break;
		if(i >= j) break;
		std::swap(S[i], S[j]);
	}
	std::swap(S[lo], S[j]);
	return j;
}


#endif /* QUICKSORT_HPP_ */
