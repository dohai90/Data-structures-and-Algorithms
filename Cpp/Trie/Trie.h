#ifndef TRIE_H_
#define TRIE_H_

#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

#define R 128
#define DB_INFO __FUNCTION__ << "(" << __LINE__ << "): "

class Trie {
private:
    struct Node {
        Node() : val(INT32_MIN), next(R, nullptr), count(0) {}
        int val;
        int count;
        vector<Node*> next;
    };

public:
    Trie();
    ~Trie();
    void put(const string& key, int val);
    int get(const string& key) const;
    queue<string> keys() const;
    queue<string> keysWithPrefix(const string& pre) const;
    void remove(const string& key);
    int size() const;
    string uniquePrefixOf(const string& key) const;

protected:
    Node* put(Node* x, const string& key, int val, int d);
    Node* get(Node* x, const string& key, int d) const;
    void collect(Node* x, const string& pre, queue<string>& q) const;
    Node* remove(Node* x, const string& key, int d);
    int size(Node* x) const;
    Node* uniquePrefixOf(Node* x, const string& key, int d, string& pre) const;

private:
    Node* proot;
};

#endif /* TRIE_H_ */