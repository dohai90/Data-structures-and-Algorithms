/*
 * EulerTour.hpp
 *
 *  Created on: May 10, 2018
 *      Author: dohai90
 */

#ifndef EULERTOUR_HPP_
#define EULERTOUR_HPP_

#include "LinkedBinaryTree.hpp"

template <typename E, typename R>
class EulerTour {
protected:
	struct Result {
		R leftResult;
		R rightResult;
		R finalResult;
	};
	typedef LinkedBinaryTree BinaryTree;
	typedef typename LinkedBinaryTree::Position Position;
protected:
	const BinaryTree* tree;
public:
	virtual ~EulerTour();
	void initialize(const BinaryTree& T) { tree = &T; }
protected:
	R eulerTour(const Position& p) const;

	virtual void visitExternal(const Position& p, Result& r) const {}
	virtual void visitLeft(const Position& p, Result& r) const {}
	virtual void visitBelow(const Position& p, Result& r) const {}
	virtual void visitRight(const Position& p, Result& r) const {}
	Result initResult() const { return Result(); }
	R result(const Result& r) const { return r.finalResult;}
};


template <typename E, typename R>
R EulerTour<E, R>::eulerTour(const Position& p) const {
	Result r = initResult();
	if(p.isExternal()) {
		visitExternal(p, r);
	}else {
		visitLeft(p, r);
		r.leftResult = eulerTour(p);
		visitBelow(p, r);
		r.rightResult = eulerTour(p);
		visitRight(p, r);
	}
	return result(r);

}


#endif /* EULERTOUR_HPP_ */
