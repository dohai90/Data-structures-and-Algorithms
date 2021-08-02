#include "Trie.h"

Trie::Trie() : proot(nullptr) {}

Trie::~Trie() {
    queue<string> q = keys();
    while(!q.empty()) {
        string key = q.front();
        // cout << DB_INFO << "deleting " << key << endl;
        q.pop();
        remove(key);
    }
    if(proot != nullptr) {
        delete proot;
        proot = nullptr;
    }
}

void Trie::put(const string& key, int val) {
    proot = put(proot, key, val, 0);
}

Trie::Node* Trie::put(Node* x, const string& key, int val, int d) {
    if(x == nullptr) {
        x = new Node;
        // cout << DB_INFO << "creating new node at " << x << endl;
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

int Trie::get(const string& key) const {
    Node* x = get(proot, key, 0);
    if(x == nullptr) return INT32_MIN;
    return x->val;
}

Trie::Node* Trie::get(Node* x, const string& key, int d) const {
    if(x == nullptr) return nullptr;
    if(d == key.length()) return x;
    unsigned char c = key.at(d);
    return get(x->next.at(c), key, d + 1);
}

queue<string> Trie::keys() const {
    return keysWithPrefix("");
}

queue<string> Trie::keysWithPrefix(const string& pre) const  {
    queue<string> q;
    collect(get(proot, pre, 0), pre, q);
    return q;
}

void Trie::collect(Node* x, const string& pre, queue<string>& q) const{
    if(x == nullptr) return;
    if(x->val != INT32_MIN) q.push(pre);
    for (unsigned char c = 0; c < R; c++) {
        collect(x->next.at(c), pre + string(1, c), q);
    }
}

void Trie::remove(const string& key) {
    proot = remove(proot, key, 0);
}

Trie::Node* Trie::remove(Node* x, const string& key, int d) {
    if(x == nullptr) return nullptr;
    x->count--;
    if(d == key.length()) {
        x->val = INT32_MIN;
    } else {
        unsigned char c = key.at(d);
        x->next.at(c) = remove(x->next.at(c), key, d + 1);
    }
    if(x->val != INT32_MIN) return x;

    for (unsigned char c = 0; c < R; c++) {
        if(x->next.at(c) != nullptr) return x;
    }
    // cout << DB_INFO << "deleting at " << x << endl;
    delete x;
    x = nullptr;
    return x;
}

int Trie::size() const {
    return size(proot);
}

int Trie::size(Node* x) const {
    if(x == nullptr) return 0;
    else return x->count;
}

string Trie::uniquePrefixOf(const string& key) const {
    string pre = "";
    Node* x = uniquePrefixOf(proot, key, 0, pre);
    if(x == nullptr) return "Key does not exist!";
    return pre;
}

Trie::Node* Trie::uniquePrefixOf(Node* x, const string& key, int d, string& pre) const {
    if(x == nullptr) return nullptr;
    if(size(x) == 1 || pre == key) return x; 
    unsigned char c = key.at(d);
    return uniquePrefixOf(x->next.at(c), key, d + 1, pre += c);
}