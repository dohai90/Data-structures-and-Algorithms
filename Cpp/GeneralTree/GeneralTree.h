#ifndef GENERALTREE_H_
#define GENERALTREE_H_

#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include "Person.h"
using namespace std;

class GeneralTree {
protected:
    struct Node {
        Person m_person;
        shared_ptr<Node> p_parent;
        vector<shared_ptr<Node>> p_children;
        Node() : p_parent(nullptr) {}
    };
public:
    GeneralTree();
    ~GeneralTree();
    void addRoot(const Person& p);
    void put(const Person& p);
    void printPreOrder() const;
protected:
    shared_ptr<Node> put(shared_ptr<Node> parent, const Person& p);
    void printPreOrder(shared_ptr<Node> x) const;
private:
    shared_ptr<Node> p_root;
    map<string, Person> m_generations;
};

#endif /* GENERALTREE_H_ */