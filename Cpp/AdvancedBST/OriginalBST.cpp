#include "OriginalBST.h"

OriginalBST::Node::Node(int key, const string& val, shared_ptr<Node> left, shared_ptr<Node> right)
    : m_key(key), m_val(val), p_left(left), p_right(right) {}

OriginalBST::Node::~Node() {
    cout << "Delete node at " << this << endl;
}

OriginalBST::OriginalBST() : p_root(nullptr) {}

OriginalBST::~OriginalBST() {}

string OriginalBST::get(int key) {
    shared_ptr<Node> x = get(p_root, key);
    if (x == nullptr) return "";
    return x->m_val;
}

shared_ptr<OriginalBST::Node> OriginalBST::get(shared_ptr<Node> x, int key) {
    if (x == nullptr) return nullptr;
    if (key < x->m_key) return get(x->p_left, key);
    else if (key > x->m_key) return get(x->p_right, key);
    else return x;
} 

void OriginalBST::put(int key, const string& val) {
    p_root = put(p_root, key, val);
}

shared_ptr<OriginalBST::Node> OriginalBST::put(shared_ptr<Node> x, int key, const string& val) {
    if (x == nullptr) {
        x = make_shared<Node>(key, val);
        cout << "Create new node at " << x << endl;
        return x;
    }
    if (key < x->m_key) x->p_left = put(x->p_left, key, val);
    else if (key > x->m_key) x->p_right = put(x->p_right, key, val);
    else x->m_val = val;
    return x;
}