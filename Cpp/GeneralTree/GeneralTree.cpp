#include "GeneralTree.h"

GeneralTree::GeneralTree() : p_root(nullptr) {}
GeneralTree::~GeneralTree() {}

void GeneralTree::addRoot(const Person& p) {
    if(p_root == nullptr) {
        p_root = make_shared<Node>();
        p_root->m_person = p;
        m_generations[p.name()] = p;
    }
}

void GeneralTree::put(const Person& p) {
    p_root = put(p_root, p);
}

shared_ptr<GeneralTree::Node> GeneralTree::put(shared_ptr<Node> parent, const Person& p) {
    if(parent->m_person == m_generations.at(p.parent())) {
        shared_ptr<Node> child = make_shared<Node>();
        child->m_person = p;
        child->p_parent = parent;
        m_generations[p.name()] = p;
        auto it = parent->p_children.begin();          
        for (; it != parent->p_children.end(); it++) {
            if(p > (*it)->m_person) { 
                parent->p_children.insert(it, child);
                break;
            }
        }
        if(it == parent->p_children.end()) {
            parent->p_children.push_back(child);
        }
        return child->p_parent;
    }

    for (auto child : parent->p_children) {
        child = put(child, p);
    }

    return parent;
}

void GeneralTree::printPreOrder() const {
    printPreOrder(p_root);
}

void GeneralTree::printPreOrder(shared_ptr<Node> x) const {
    if(x->m_person.yod() == "-" && x->m_person.religion() != "Catholic")
        cout << x->m_person.name() << endl;
    
    for (auto child : x->p_children) {
        printPreOrder(child);
    }
}