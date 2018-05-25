/*
 * LinkedBinaryTree.hpp
 *
 *  Created on: May 8, 2018
 *      Author: dohai90
 */

#ifndef LINKEDBINARYTREE_HPP_
#define LINKEDBINARYTREE_HPP_

#include <cstdlib>
#include <list>

typedef int Elem;

class LinkedBinaryTree {
protected:
	struct Node {
		Elem e;
		Node* parent;
		Node* left;
		Node* right;
		Node() : e(), parent(NULL), left(NULL), right(NULL) {}
	};

public:
	class Position {
	private:
		Node* v;
	public:
		Position(Node* _v=NULL);
		Elem& operator*() const;
		Position parent() const;
		Position left() const;
		Position right() const;
		bool isRoot() const;
		bool isExternal() const;
		friend class LinkedBinaryTree;
	};

protected:
	typedef std::list<Position> PositionList;

public:
	LinkedBinaryTree();
	~LinkedBinaryTree();
	bool empty() const;
	unsigned int size() const;
	Position root() const;
	PositionList positions() const;
	void addRoot();
	void expandExternal(const Position& p);
	Position removeAboveExternal(const Position& p);
	void removeExternal(const Position& p);

protected:
	void preorder(Node* v, PositionList& pl) const;

private:
	Node* _root;
	unsigned int N;
};



#endif /* LINKEDBINARYTREE_HPP_ */
