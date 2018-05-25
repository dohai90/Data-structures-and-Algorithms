/*
 * HashTable.hpp
 *
 *  Created on: May 15, 2018
 *      Author: dohai90
 */

#ifndef HASHTABLE_HPP_
#define HASHTABLE_HPP_

#include <functional>
#include <list>
#include <vector>

template <typename K, typename V>
class HashTable {
public:
	class Entry {
	private:
		K _key;
		V _val;
	public:
		Entry(const K& k = K(), const V& v = V())
			: _key(k), _val(v) {}
		const K& key() const { return _key; }
		const V& value() const { return _val; }
		void setKey(const K& k) { _key = k; }
		void setValue(const V& v) { _val = v; }
	};

protected:
	typedef std::list<Entry> Bucket;
	typedef std::vector<Bucket> BktArray;
	typedef typename Bucket::iterator EIter;
	typedef typename BktArray::iterator BIter;

public:
	class Iterator {
	private:
		EIter ent;
		BIter bkt;
		const BktArray* ba;
	public:
		Iterator(const BktArray& _ba, const BIter& _bkt, const EIter& _ent = EIter())
			: ba(&_ba), bkt(_bkt), ent(_ent) {}
		Entry& operator*() const;
		Iterator& operator++();
		bool operator==(const Iterator& p) const;
		friend class HashTable;
	};

private:
	unsigned int N;
	unsigned int M;
	std::hash<K> hash;
	BktArray BA;

protected:
	Iterator finder(const K& k);
	Iterator inserter(const Iterator& p, const Entry& e);
	void eraser(const Iterator& p);
	static bool endOfBkt(const Iterator& p);
	static void nextEntry(Iterator& p);

public:
	HashTable(unsigned int _N=0, unsigned int _M=5)
		: N(_N), M(_M), BA(M) {}
	unsigned int size() const;
	bool empty() const;
	Iterator find(const K& k);
	Iterator put(const K& k, const V& v);
	void erase(const Iterator& p);
	void erase(const K& k);
	Iterator begin();
	Iterator end();
};

template <typename K, typename V>
typename HashTable<K, V>::Entry& HashTable<K, V>::Iterator::operator *() const {
	return *ent;
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator& HashTable<K, V>::Iterator::operator ++() {
	++ent;
	if(endOfBkt(*this)){
		++bkt;
		while(bkt != ba->end() && bkt->empty()) ++bkt;
		if(bkt == ba->end()) return *this;
		ent = bkt->begin();
	}
	return *this;
}

template <typename K, typename V>
bool HashTable<K, V>::Iterator::operator ==(const Iterator& p) const {
	if(ba != p.ba || bkt != p.bkt) return false;
	else if(bkt == ba->end()) return true;
	else return ent == p.ent;
}

template <typename K, typename V>
bool HashTable<K, V>::endOfBkt(const Iterator& p) {
	return p.ent == p.bkt->end();
}

template <typename K, typename V>
void HashTable<K, V>::nextEntry(Iterator& p) {
	++p.ent;
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::finder(const K& k) {
	unsigned int i = (hash(k) & 0x7fffffff) % M;
	BIter bkt = BA.begin() + i;
	Iterator p(BA, bkt, bkt->begin());
	while(!endOfBkt(p) && (*p).key() != k)
		nextEntry(p);
	return p;
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::inserter(const Iterator& p, const Entry& e){
	EIter ins = p.bkt->insert(p.ent, e);
	N++;
	return Iterator(BA, p.bkt, ins);
}

template <typename K, typename V>
void HashTable<K, V>::eraser(const Iterator& p) {
	p.bkt->erase(p.ent);
	N--;
}

template <typename K, typename V>
unsigned int HashTable<K, V>::size() const {
	 return N;
}

template <typename K, typename V>
bool HashTable<K, V>::empty() const {
	return N == 0;
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::begin() {
	if(empty()) return end();
	BIter bkt = BA.begin();
	while(bkt->empty()) ++bkt;
	return Iterator(BA, bkt, bkt->begin());
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::end() {
	return Iterator(BA, BA.end());
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::find(const K& k) {
	Iterator p = finder(k);
	if(endOfBkt(p))
		return end();
	else
		return p;
}

template <typename K, typename V>
typename HashTable<K, V>::Iterator HashTable<K, V>::put(const K& k, const V& v) {
	Iterator p = finder(k);
	if(endOfBkt(p)){
		return inserter(p, Entry(k, v));
	}else {
		p.ent->setValue(v);
		return p;
	}
}

template <typename K, typename V>
void HashTable<K, V>::erase(const Iterator& p) {
	p.bkt->erase(p.ent);
}

template <typename K, typename V>
void HashTable<K, V>::erase(const K& k){
	Iterator p = finder(k);
	if(!endOfBkt(p)) erase(p);
}
#endif /* HASHTABLE_HPP_ */
