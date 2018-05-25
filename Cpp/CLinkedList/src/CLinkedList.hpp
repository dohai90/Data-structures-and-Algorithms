/*
 * CLinkedList.hpp
 *
 *  Created on: May 4, 2018
 *      Author: dohai90
 */

#ifndef CLINKEDLIST_HPP_
#define CLINKEDLIST_HPP_

#include <cstdlib>
#include <iostream>

template <typename Item>
class CLinkedList;

template <typename Item>
class CNode{
private:
	Item item;
	CNode* next;
	friend class CLinkedList<Item>;
};

template <typename Item>
class CLinkedList{
private:
	CNode<Item>* cursor;
public:
	CLinkedList();
	~CLinkedList();
	bool isEmpty() const;
	Item& front() const;
	Item& back() const;
	void advance();
	void add(const Item& item);
	void remove();
	void show() const;
};

template <typename Item>
CLinkedList<Item>::CLinkedList()
	: cursor(NULL){}

template <typename Item>
CLinkedList<Item>::~CLinkedList(){
	while(!isEmpty()) remove();
	std::cout << "destruction done!!!" << std::endl;
}

template <typename Item>
bool CLinkedList<Item>::isEmpty() const{
	return cursor == NULL;
}

template <typename Item>
Item& CLinkedList<Item>::front() const{
	return cursor->next->item;
}

template <typename Item>
Item& CLinkedList<Item>::back() const{
	return cursor->item;
}

template <typename Item>
void CLinkedList<Item>::advance(){
	cursor = cursor->next;
}

template <typename Item>
void CLinkedList<Item>::add(const Item& item){
	CNode<Item>* v = new CNode<Item>;
	v->item = item;
	if(isEmpty()){
		v->next = v;
		cursor = v;
	}else{
		v->next = cursor->next;
		cursor->next = v;
	}
}

template <typename Item>
void CLinkedList<Item>::remove(){
	CNode<Item>* v = cursor->next;
	if(v == cursor){
		cursor = NULL;
	}else{
		cursor->next = v->next;
	}
	delete v;
}

template <typename Item>
void CLinkedList<Item>::show() const{
	CNode<Item>* cur;
	for(cur=cursor->next; cur!=cursor; cur=cur->next)
		std::cout << cur->item << " ";
	std::cout << cur->item << std::endl;
}

#endif /* CLINKEDLIST_HPP_ */
