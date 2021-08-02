#include "TrieSP.h"

TrieSP::TrieSP() : proot(nullptr) {}

TrieSP::~TrieSP() {}

void TrieSP::put(const string& key, int val) {
    proot = put(proot, key, val, 0);
}

shared_ptr<TrieSP::Node> TrieSP::put(shared_ptr<Node> x, const string& key, int val, int d) {
    if(x == nullptr) {
        x = make_shared<Node>();
        // cout << DB_INFO << "Created at " << x << endl;
    }
    x->count++;
    if(d == key.length()) {
        x->val = val;
        return x;
    }
    unsigned char c = key.at(d);
    x->next.at(c) = put(x->next.at(c), key, val, d + 1);
    return x;
}

int TrieSP::get(const string& key) const {
    shared_ptr<Node> x = get(proot, key, 0);
    if(x == nullptr) return INT32_MIN;
    return x->val;
}

shared_ptr<TrieSP::Node> TrieSP::get(shared_ptr<Node> x, const string& key, int d) const {
    if(x == nullptr) return nullptr;
    if(d == key.length()) return x;
    unsigned char c = key.at(d);
    return get(x->next.at(c), key, d + 1);
}

int TrieSP::size() const {
    return size(proot);
}

int TrieSP::size(shared_ptr<Node> x) const {
    if(x == nullptr) return 0;
    return x->count;
}

queue<string> TrieSP::keys() const {
    return keysWithPrefix("");
}

queue<string> TrieSP::keysWithPrefix(const string& pre) const {
    queue<string> q;
    collect(get(proot, pre, 0), pre, q);
    return q;
}

void TrieSP::collect(shared_ptr<Node> x, const string& pre, queue<string>& q) const {
    if(x == nullptr) return;
    if(x->val != INT32_MIN) q.push(pre);
    for (unsigned char c = 0; c < RSP; c++) {
        collect(x->next.at(c), pre + string(1, c), q);
    }
}

void TrieSP::remove(const string& key) {
    proot = remove(proot, key, 0);
}

shared_ptr<TrieSP::Node> TrieSP::remove(shared_ptr<Node> x, const string& key, int d) {
    if(x == nullptr) return nullptr;
    x->count--;
    if(d == key.length()) {
        x->val = INT32_MIN;
    } else {
        unsigned char c = key.at(d);
        x->next.at(c) = remove(x->next.at(c), key, d + 1);
    }

    if(x->val != INT32_MIN) return x;
    for (unsigned char c = 0; c < RSP; c++) {
        if(x->next.at(c) != nullptr) return x;
    }

    return nullptr;
}

string TrieSP::uniquePrefixOf(const string& key) const {
    string pre = "";
    shared_ptr<Node> x = uniquePrefixOf(proot, key, 0, pre);
    if(x == nullptr) return "Key does not exist!";
    return pre;
}

shared_ptr<TrieSP::Node> TrieSP::uniquePrefixOf(shared_ptr<Node> x, const string& key, int d, string& pre) const {
    if(x == nullptr) return nullptr;
    if(size(x) == 1 || pre == key) return x;
    unsigned char c = key.at(d);
    return uniquePrefixOf(x->next.at(c), key, d + 1, pre += c);
}