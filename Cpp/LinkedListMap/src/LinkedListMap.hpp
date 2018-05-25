/*
 * LinkedListMap.hpp
 *
 *  Created on: May 14, 2018
 *      Author: dohai90
 */

#ifndef LINKEDLISTMAP_HPP_
#define LINKEDLISTMAP_HPP_

#include <list>

template <typename K, typename V>
class LinkedListMap {
public:
	class Entry {
	private:
		K _key;
		V _val;
	public:
		Entry(const K& k=K(), const V& v=V())
			: _key(k), _val(v) {}
		const K& key() const { return _key; }
		const V& value() const { return _val; }
		void setKey(const K& k) { _key = k; }
		void setValue(const V& v) { _val = v; }
	};

	typedef typename std::list<Entry>::iterator Iterator;

private:
	std::list<Entry> L;

public:
	unsigned int size() const;
	bool empty() const;
	Iterator begin();
	Iterator end();
	Iterator find(const K& k);
	Iterator insert(const K& k, const V& v);
	void erase(const Iterator& p);
	void erase(const K& k);
};

template <typename K, typename V>
unsigned int LinkedListMap<K, V>::size() const {
	return L.size();
}

template <typename K, typename V>
bool LinkedListMap<K, V>::empty() const {
	return L.empty();
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator LinkedListMap<K, V>::begin() {
	return L.begin();
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator LinkedListMap<K, V>::end() {
	return L.end();
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator LinkedListMap<K, V>::find(const K& k) {
	Iterator p;
	for(p = begin(); p != end(); ++p)
		if(p->key() == k) break;
	return p;
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator LinkedListMap<K, V>::insert(const K& k, const V& v) {
	Iterator p = find(k);
	if(p != end()){
		p->setValue(v);
	}else {
		Entry e(k, v);
		L.push_back(e);
		--p;
	}
	return p;
}

template <typename K, typename V>
void LinkedListMap<K, V>::erase(const Iterator& p) {
	L.erase(p);
}

template <typename K, typename V>
void LinkedListMap<K, V>::erase(const K& k) {
	Iterator p = find(k);
	erase(p);
}

#endif /* LINKEDLISTMAP_HPP_ */
