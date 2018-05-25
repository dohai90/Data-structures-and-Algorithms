/*
 * MyListPQ.hpp
 *
 *  Created on: May 11, 2018
 *      Author: dohai90
 */

#ifndef LISTPQ_HPP_
#define LISTPQ_HPP_


#include <list>

template <typename E, typename C>
class ListPQ {
private:
	std::list<E> L;
	C isLess;
public:
	bool empty() const;
	unsigned int size() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
};

template <typename E>
class Less {
public:
	bool operator() (const E& p, const E& q) { return p < q; }
};

template <typename E, typename C>
bool ListPQ<E, C>::empty() const {
	return L.empty();
}

template <typename E, typename C>
unsigned int ListPQ<E, C>::size() const {
	return L.size();
}

template <typename E, typename C>
void ListPQ<E, C>::insert(const E& e) {
	typename std::list<E>::iterator p;
	p = L.begin();
	while(!L.empty() && !isLess(e, *p)) ++p;
	L.insert(p, e);
}

template <typename E, typename C>
const E& ListPQ<E, C>::min() const {
	return L.front();
}

template <typename E, typename C>
void ListPQ<E, C>::removeMin() {
	L.pop_front();
}


#endif /* LISTPQ_HPP_ */
