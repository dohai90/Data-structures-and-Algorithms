#include "SPBST.h"

SPBST::Node::Node(const pair<long, long>& key, const string& val, shared_ptr<Node> mom, shared_ptr<Node> dad, shared_ptr<Node> left, shared_ptr<Node> right)
    : m_key(key), m_val(val), p_mom(mom), p_dad(dad), p_left(left), p_right(right) {}

SPBST::Node::~Node() {
    cout << DB_INFO << "Delete node at: " << this << endl; 
}

SPBST::SPBST() {
    p_rootMom = make_shared<Node>(make_pair(0, 1), "");
    cout << DB_INFO << "Create Mom at: " << p_rootMom.get() << endl;
    p_rootDad = make_shared<Node>(make_pair(1, 0), "");
    cout << DB_INFO << "Create Dad at: " << p_rootDad.get() << endl;
    p_root = make_shared<Node>(make_pair(1, 1), "", p_rootMom, p_rootDad);
    cout << DB_INFO << "Create root at: " << p_root.get() << endl;
    p_rootMom->p_right = p_root;
    p_rootDad->p_left = p_root;
}

SPBST::~SPBST() {
    cout << DB_INFO << "Ref count of Mom: " << p_rootMom.use_count() << endl;
    cout << DB_INFO << "Ref count of Dad: " << p_rootDad.use_count() << endl;
    cout << DB_INFO << "Ref count of root: " << p_root.use_count() << endl;
}

void SPBST::put(const pair<long, long>& key, const string& val) {
    p_root = put(p_root, p_rootMom, p_rootDad, key, val);
}

shared_ptr<SPBST::Node> SPBST::put(shared_ptr<Node> x, shared_ptr<Node> mom, shared_ptr<Node> dad, const pair<long, long>& key, const string& val) {
    if (x == nullptr) {
        if (val.back() == 'L') {
            auto left_key = make_pair(dad->p_mom->m_key.first + dad->m_key.first, dad->p_mom->m_key.second + dad->m_key.second);
            x = make_shared<Node>(left_key, val, dad->p_mom, dad);
            cout << DB_INFO << "Create new node at: " << x.get() << endl;
            if (compareKey(key, left_key) == 0) return x;
        } else {
            auto right_key = make_pair(mom->p_dad->m_key.first + mom->m_key.first, mom->p_dad->m_key.second + mom->m_key.second);
            x = make_shared<Node>(right_key, val, mom, mom->p_dad);
            cout << DB_INFO << "Create new node at: " << x.get() << endl;
            if (compareKey(key, right_key) == 0) return x;
        }
    }

    if (compareKey(key, x->m_key) < 0) x->p_left = put(x->p_left, x->p_mom, x, key, val + "L");
    else if (compareKey(key, x->m_key) > 0) x->p_right = put(x->p_right, x, x->p_dad, key, val + "R");
    else x->m_val = val;
    return x;
}

int SPBST::compareKey(const pair<long, long>& p1, const pair<long, long>& p2) {
    if ((p1.first * 1.0 / p1.second) > (p2.first * 1.0 / p2.second)) return 1;
    else if ((p1.first * 1.0 / p1.second) < (p2.first * 1.0 / p2.second)) return -1;
    return 0;
}

string SPBST::get(const pair<long, long>& key) {
    shared_ptr<Node> x = get(p_root, key);
    if (x == nullptr) {
        put(key);
        x = get(p_root, key);
    }
    return x->m_val;
}

shared_ptr<SPBST::Node> SPBST::get(shared_ptr<Node> x, const pair<long, long>& key) {
    if (x == nullptr) return nullptr;
    if (compareKey(key, x->m_key) < 0) return get(x->p_left, key);
    else if (compareKey(key, x->m_key) > 0) return get(x->p_right, key);
    else return x;
}

pair<long, long> SPBST::get(const string& dir) {
    shared_ptr<Node> x = p_root;
    for (uint i = 0; i < dir.length(); i++) {
        if (dir.at(i) == 'L') {
            if(x->p_left == nullptr) {
                auto left_key = make_pair(x->p_mom->m_key.first + x->m_key.first, x->p_mom->m_key.second + x->m_key.second);
                x->p_left = make_shared<Node>(left_key, dir.substr(0, i + 1), x->p_mom, x);
            }
            x = x->p_left;
        } else {
            if(x->p_right == nullptr) {
                auto right_key = make_pair(x->p_dad->m_key.first + x->m_key.first, x->p_dad->m_key.second + x->m_key.second);
                x->p_right = make_shared<Node>(right_key, dir.substr(0, i + 1), x, x->p_dad);
            }
            x = x->p_right;
        }
    }
    return x->m_key;
}

long SPBST::getGCD(long a, long b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}