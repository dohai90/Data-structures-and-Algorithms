/*
 * LinkedBinaryTree.cpp
 *
 *  Created on: May 8, 2018
 *      Author: dohai90
 */

#include "LinkedBinaryTree.hpp"

LinkedBinaryTree::Position::Position(Node* _v)
	: v(_v) {}

Elem& LinkedBinaryTree::Position::operator *() const {
	return v->e;
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::parent() const {
	return Position(v->parent);
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::left() const {
	return Position(v->left);
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::right() const {
	return Position(v->right);
}

bool LinkedBinaryTree::Position::isRoot() const {
	return v->parent == NULL;
}

bool LinkedBinaryTree::Position::isExternal() const {
	return (v->left == NULL && v->right == NULL);
}

LinkedBinaryTree::LinkedBinaryTree()
	: _root(NULL), N(0) {}

LinkedBinaryTree::~LinkedBinaryTree() {

	while(!empty()) {
		removeExternal(Position(_root));
	}

}

bool LinkedBinaryTree::empty() const {
	return N == 0;
}

unsigned int LinkedBinaryTree::size() const {
	return N;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
	return Position(_root);
}

void LinkedBinaryTree::addRoot() {
	_root = new Node;
	N = 1;
}


void LinkedBinaryTree::expandExternal(const Position& p) {
	Node* v = p.v;
	v->left = new Node;
	v->left->parent = v;
	v->right = new Node;
	v->right->parent = v;
	N += 2;
}

LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
	Node* w = p.v;
	Node* v = w->parent;
	Node* sib = (w == v->left)? v->right : v->left;
	if(v == _root) {
		_root = sib;
		sib->parent = NULL;
	}else {
		Node* gpar = v->parent;
		if(v == gpar->left){
			gpar->left = sib;
		}else {
			gpar->right = sib;
		}
		sib->parent = gpar;
	}
	delete w;
	delete v;
	N -= 2;
	return Position(sib);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));
	if(v->left != NULL) preorder(v->left, pl);
	if(v->right != NULL) preorder(v->right, pl);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl); // if write return pl; pl is destructed before returning
}

void LinkedBinaryTree::removeExternal(const Position& p) {
	if(p.isExternal()) {
		delete p.v;
		N--;
	}
	removeExternal(Position(p.v->left));
	removeExternal(Position(p.v->right));
}
