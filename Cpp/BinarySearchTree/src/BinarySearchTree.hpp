/*
 * BinarySearchTree.hpp
 *
 *  Created on: May 23, 2018
 *      Author: dohai90
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <cstdlib>
#include <list>
#include <iostream>

template <typename K, typename V>
class Entry {
private:
	K _key;
	V _val;
public:
	typedef K Key;
	typedef V Value;
public:
	Entry(const K& k=K(), const V& v=V())
		: _key(k), _val(v) {}
	const K& key() const { return _key; }
	const V& value() const { return _val; }
	void setKey(const K& k) { _key = k; }
	void setValue(const V& v) { _val = v;}
};

template <typename K, typename V>
class BinaryTree {
protected:
	struct Node {
		Entry<K, V> e;
		Node* parent;
		Node* left;
		Node* right;
		Node(): e(), parent(NULL), left(NULL), right(NULL) {}
	};

public:
	class Position {
	private:
		Node* _v;
	public:
		Position(Node* v=NULL);
		Entry<K, V>& operator*() const;
		bool operator==(const Position& p) const;
		Position parent() const;
		Position left() const;
		Position right() const;
		bool isRoot() const;
		bool isExternal() const;
		friend class BinaryTree<K, V>;
	};

protected:
	typedef std::list<Position> PositionList;

private:
	Node* _root;
	unsigned int n;

public:
	BinaryTree();
	~BinaryTree();
	unsigned int size() const;
	bool empty() const;
	PositionList positions() const;
	Position root() const;
	void addRoot();
	void expandExternal(const Position& p);
	void removeExternal(const Position& p);
	Position removeAboveExternal(const Position& p);

protected:
	void preorder(Node* v, PositionList& pl) const;
};

template <typename E>
class BST {
public:
	typedef typename E::Key K;
	typedef typename E::Value V;
	class Iterator;

private:
	BinaryTree<K, V> T;
	unsigned int n;

public:
	BST();
	unsigned int size() const;
	bool empty() const;
	Iterator find(const K& k);
	Iterator insert(const K& k, const V& x);
	void erase(const K& k);
	void erase(const Iterator& p);
	Iterator begin();
	Iterator end();

protected:
	typedef typename BinaryTree<K, V>::Position TPos;
	TPos root() const;	// get virtual root
	TPos finder(const K& k, const TPos& v);
	TPos inserter(const K& k, const V& x);
	TPos eraser(TPos& v);

public:
	class Iterator {
	private:
		TPos v;
	public:
		Iterator(const TPos& vv=TPos()) : v(vv) {}
		const E& operator*() const { return *v; }
		E& operator*() { return *v; }
		bool operator==(const Iterator& p) { return v == p.v; }
		Iterator& operator++();
		friend class BST<E>;
	};
};


template <typename K, typename V>
BinaryTree<K, V>::Position::Position(Node* v)
	: _v(v) {}

template <typename K, typename V>
Entry<K, V>& BinaryTree<K, V>::Position::operator *() const {
	return _v->e;
}

template <typename K, typename V>
bool BinaryTree<K, V>::Position::operator ==(const Position& p) const {
	return _v == p._v;
}
template <typename K, typename V>
typename BinaryTree<K, V>::Position BinaryTree<K, V>::Position::parent() const {
	return Position(_v->parent);
}

template <typename K, typename V>
typename BinaryTree<K, V>::Position BinaryTree<K, V>::Position::left() const {
	return Position(_v->left);
}

template <typename K, typename V>
typename BinaryTree<K, V>::Position BinaryTree<K, V>::Position::right() const {
	return Position(_v->right);
}

template <typename K, typename V>
bool BinaryTree<K, V>::Position::isRoot() const {
	return _v->parent == NULL;
}

template <typename K, typename V>
bool BinaryTree<K, V>::Position::isExternal() const {
	return (_v->left == NULL && _v->right == NULL);
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree()
	: _root(NULL), n(0) {}

template <typename K, typename V>
BinaryTree<K, V>::~BinaryTree() {
	std::cout << "Need to remove: " << size() << " nodes" << std::endl;
	while(!empty()) {
		removeExternal(Position(_root));
	}
}

template <typename K, typename V>
unsigned int BinaryTree<K, V>::size() const {
	return n;
}

template <typename K, typename V>
bool BinaryTree<K, V>::empty() const {
	return n == 0;
}

template <typename K, typename V>
typename BinaryTree<K, V>::Position BinaryTree<K, V>::root() const {
	return Position(_root);
}

template <typename K, typename V>
void BinaryTree<K, V>::addRoot() {
	_root = new Node;
	n = 1;
}

template <typename K, typename V>
void BinaryTree<K, V>::expandExternal(const Position& p) {
	Node* v = p._v;
	v->left = new Node;
	v->left->parent = v;
	v->right = new Node;
	v->right->parent = v;
	n += 2;
}

template <typename K, typename V>
typename BinaryTree<K, V>::Position BinaryTree<K, V>::removeAboveExternal(const Position& p) {
	Node* v = p._v;
	Node* w = v->parent;
	Node* sib = (v == w->left)? w->right:w->left;
	if(w == _root) {
		_root = sib;
		sib->parent = NULL;
	}else {
		Node* gpar = w->parent;
		if(w == gpar->left){
			gpar->left = sib;
		}else {
			gpar->right = sib;
		}
		sib->parent = gpar;
	}
	delete v;
	delete w;
	n -= 2;
	return Position(sib);
}

template <typename K, typename V>
void BinaryTree<K, V>::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));
	if(v->left != NULL) preorder(v->left, pl);
	if(v->right != NULL) preorder(v->right, pl);
}

template <typename K, typename V>
typename BinaryTree<K, V>::PositionList BinaryTree<K, V>::positions() const {
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}

template <typename K, typename V>
void BinaryTree<K, V>::removeExternal(const Position& p) {
	if(p._v == NULL) return;
	if(p.isExternal()){
		if(p._v != _root){
			if(p._v == p._v->parent->left) p._v->parent->left = NULL;
			else p._v->parent->right = NULL;
		}
		delete p._v;
		n--;
		std::cout << "Remove external node" << std::endl;
		return;
	}

	removeExternal(Position(p._v->left));
	removeExternal(Position(p._v->right));
}


template <typename E>
typename BST<E>::Iterator& BST<E>::Iterator::operator ++() {
	TPos w = v.right();
	if(!w.isExternal()) {
		while(!w.isExternal()){
			v = w;
			w = w.left();
		}
	}else {
		w = v.parent();
		while(v == w.right()){
			v = w;
			w = w.parent();
		}
		v = w;
	}

	return *this;
}


template <typename E>
BST<E>::BST() : T(), n(0) {
	T.addRoot();					// create super root
	T.expandExternal(T.root());
}

template <typename E>
typename BST<E>::TPos BST<E>::root() const {
	return T.root().left();
}

template <typename E>
unsigned int BST<E>::size() const {
	return n;
}

template <typename E>
bool BST<E>::empty() const {
	return n == 0;
}

template <typename E>
typename BST<E>::Iterator BST<E>::begin() {
	TPos v = root();
	while(!v.isExternal()){
		v = v.left();
	}

	return Iterator(v.parent());
}

template <typename E>
typename BST<E>::Iterator BST<E>::end() {
	return Iterator(T.root());
}

template <typename E>
typename BST<E>::TPos BST<E>::finder(const K& k, const TPos& v) {
	if(v.isExternal()) return v;
	if(k < (*v).key()) finder(k, v.left());
	else if((*v).key() < k) finder(k, v.right());
	else return v;
}

template <typename E>
typename BST<E>::Iterator BST<E>::find(const K& k) {
	TPos v = finder(k, root());
	if(v.isExternal()) return end();
	else return Iterator(v);
}

template <typename E>
typename BST<E>::TPos BST<E>::inserter(const K& k, const V& x) {
	TPos v = finder(k, root());
	if(!v.isExternal()) {
		(*v).setValue(x);
	}else {
		T.expandExternal(v);
		(*v).setKey(k);
		(*v).setValue(x);
		n++;
	}
	return v;
}

template <typename E>
typename BST<E>::Iterator BST<E>::insert(const K& k, const V& x){
	TPos v = inserter(k, x);
	return Iterator(v);
}

template <typename E>
typename BST<E>::TPos BST<E>::eraser(TPos& v) {
	TPos w;
	if(v.left().isExternal()) w = v.left();
	else if(v.right().isExternal()) w = v.right();
	else {
		w = v.right();
		while(!w.isExternal()) {
			w = w.left();
		}
		TPos u = w.parent();
		(*v).setKey((*u).key());
		(*v).setValue((*u).value());
	}

	n--;
	return T.removeAboveExternal(w);
}

template <typename E>
void BST<E>::erase(const K& k) {
	TPos v = finder(k, root());
	if(!v.isExternal()) eraser(v);
}

template <typename E>
void BST<E>::erase(const Iterator& p) {
	erase(p.v);
}
#endif /* BINARYSEARCHTREE_HPP_ */
