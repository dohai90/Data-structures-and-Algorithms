/*
 * DLinkedList.hpp
 *
 *  Created on: May 3, 2018
 *      Author: dohai90
 */

#ifndef DLINKEDLIST_HPP_
#define DLINKEDLIST_HPP_

#include <cstdlib>
#include <iostream>

template <typename Item>
class DLinkedList;


template <typename Item>
class DNode{
private:
	Item item;
	DNode<Item>* next;
	DNode<Item>* prev;
	friend class DLinkedList<Item>;
};

template <typename Item>
class DLinkedList{
private:
	DNode<Item>* header;
	DNode<Item>* trailer;
protected:
	void add(DNode<Item>* v, const Item& item);		// add a node before node v
	void remove(DNode<Item>* v);					// remove node v
public:
	DLinkedList();
	~DLinkedList();
	bool isEmpty() const;
	Item& front() const;
	Item& back() const;
	void addFront(const Item& item);
	void addBack(const Item& item);
	void removeFront();
	void removeBack();
	void reverse(DLinkedList<Item>& L);
	void show() const;
};

template <typename Item>
DLinkedList<Item>::DLinkedList(){
	header = new DNode<Item>;
	trailer = new DNode<Item>;
	header->next = trailer;
	trailer->prev = header;
}

template <typename Item>
DLinkedList<Item>::~DLinkedList(){
	while(!isEmpty()) removeFront();
	delete header;
	delete trailer;
	std::cout << "destruction done!!!" << std::endl;
}

template <typename Item>
bool DLinkedList<Item>::isEmpty() const{
	return header->next == trailer;
}

template <typename Item>
Item& DLinkedList<Item>::front() const{
	return header->next->item;
}

template <typename Item>
Item& DLinkedList<Item>::back() const{
	return trailer->prev->item;
}

template <typename Item>
void DLinkedList<Item>::add(DNode<Item>* v, const Item& item){
	DNode<Item>* u = new DNode<Item>;
	u->item = item;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = u;
	v->prev = u;
}

template <typename Item>
void DLinkedList<Item>::addFront(const Item& item){
	add(header->next, item);
}

template <typename Item>
void DLinkedList<Item>::addBack(const Item& item){
	add(trailer, item);
}

template <typename Item>
void DLinkedList<Item>::remove(DNode<Item>* v){
	v->prev->next = v->next;
	v->next->prev = v->prev;
	delete v;
}

template <typename Item>
void DLinkedList<Item>::removeFront(){
	remove(header->next);
	std::cout << "remove front" << std::endl;
}

template <typename Item>
void DLinkedList<Item>::removeBack(){
	remove(trailer->prev);
}

template <typename Item>
void DLinkedList<Item>::show() const{
	for(DNode<Item>* cur=header->next; cur!=trailer; cur=cur->next)
		std::cout << cur->item << " ";
	std::cout << std::endl;
}

template <typename Item>
void DLinkedList<Item>::reverse(DLinkedList<Item>& L){
	DLinkedList<Item> T;
	while(!L.isEmpty()){
		T.addFront(L.front());
		L.removeFront();
	}

	while(!T.isEmpty()){
		L.addBack(T.front());
		T.removeFront();
	}
}

#endif /* DLINKEDLIST_HPP_ */
