#ifndef TRIESP_H_
#define TRIESP_H_

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <memory>

using namespace std;
#define RSP 128
#define DB_INFO __FUNCTION__ << "(" << __LINE__ << "): "

class TrieSP {
private:
    class Node
    {
    public:
        Node() : val(INT32_MIN), next(RSP, nullptr), count(0) {};
        ~Node() {/*cout << DB_INFO << "Delete node " << this << endl;*/}
        int val;
        int count;
        vector<shared_ptr<Node> > next;
    };
public:
    TrieSP();
    ~TrieSP();
    void put(const string& key, int val);
    int get(const string& key) const;
    int size() const;
    queue<string> keys() const;
    queue<string> keysWithPrefix(const string& pre) const;
    void remove(const string& key);
    string uniquePrefixOf(const string& key) const;

protected:
    shared_ptr<Node> put(shared_ptr<Node> x, const string& key, int val, int d);
    shared_ptr<Node> get(shared_ptr<Node> x, const string& key, int d) const;
    int size(shared_ptr<Node> x) const;
    void collect(shared_ptr<Node> x, const string& pre, queue<string>& q) const;
    shared_ptr<Node> remove(shared_ptr<Node> x, const string& key, int d);
    shared_ptr<Node> uniquePrefixOf(shared_ptr<Node> x, const string& key, int d, string& pre) const;

private:
    shared_ptr<Node> proot;
};
#endif /* TRIESP_H_ */