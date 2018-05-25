/*
 * LinkedListStack.hpp
 *
 *  Created on: May 3, 2018
 *      Author: dohai90
 */

#ifndef SLINKEDLIST_HPP_
#define SLINKEDLIST_HPP_

#include <cstdlib>
#include <iostream>

template <typename Item>
class LinkedListStack;

template <typename Item>
class LinkedListQueue;

template <typename Item>
class Node{
private:
	Item item;
	Node<Item>* next;
	friend class LinkedListStack<Item>;
	friend class LinkedListQueue<Item>;
};

template <typename Item>
class LinkedListStack{
private:
	Node<Item>* head;
public:
	LinkedListStack<Item>();
	~LinkedListStack<Item>();
	bool isEmpty() const;
	void push(const Item& item);
	Item& pop();
	Item& peak() const;
	void show() const;
};

template <typename Item>
LinkedListStack<Item>::LinkedListStack(): head(NULL){}

template <typename Item>
LinkedListStack<Item>::~LinkedListStack(){
	std::cout << "destruction done" << std::endl;
	while(!isEmpty()) pop();
}

template <typename Item>
bool LinkedListStack<Item>::isEmpty() const{
	return head == NULL;
}
template <typename Item>
void LinkedListStack<Item>::push(const Item& item){
	Node<Item>* oldhead = head;
	head = new Node<Item>;
	head->item = item;
	head->next = oldhead;
}

template <typename Item>
Item& LinkedListStack<Item>::pop(){
	Node<Item>* oldhead = head;
	Item& item = oldhead->item;
	head = oldhead->next;
	delete oldhead;
	return item;
}

template <typename Item>
Item& LinkedListStack<Item>::peak() const{
	return head->item;
}

template <typename Item>
void LinkedListStack<Item>::show() const{
	for(Node<Item>* cur=head; cur!=NULL; cur=cur->next){
		std::cout << cur->item << " ";
	}
	std::cout << std::endl;
}


template <typename Item>
class LinkedListQueue{
private:
	Node<Item>* head;
	Node<Item>* tail;
public:
	LinkedListQueue();
	~LinkedListQueue();
	bool isEmpty() const;
	void enqueue(const Item& item);
	Item& dequeue();
	void show() const;
};

template <typename Item>
LinkedListQueue<Item>::LinkedListQueue(): head(NULL), tail(NULL){}

template <typename Item>
LinkedListQueue<Item>::~LinkedListQueue(){
	while(!isEmpty()) dequeue();
	std::cout << "destruction done" << std::endl;
}

template <typename Item>
bool LinkedListQueue<Item>::isEmpty() const{
	return head == NULL;
}

template <typename Item>
void LinkedListQueue<Item>::enqueue(const Item& item){
	Node<Item>* oldtail = tail;
	tail = new Node<Item>;
	tail->item = item;
	tail->next = NULL;
	if(isEmpty()) head = tail;
	else oldtail->next = tail;
}

template <typename Item>
Item& LinkedListQueue<Item>::dequeue(){
	Node<Item>* oldhead = head;
	Item& item = oldhead->item;
	head = oldhead->next;
	delete oldhead;
	return item;
}

template <typename Item>
void LinkedListQueue<Item>::show() const{
	for(Node<Item>* cur=head; cur!=NULL; cur=cur->next)
		std::cout << cur->item << " ";

	std::cout << std::endl;
}


#endif /*SLINKEDLIST_HPP_ */
