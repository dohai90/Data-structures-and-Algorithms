#ifndef WPBST_H_
#define WPBST_H_

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define DB_INFO __FUNCTION__ << "(" << __LINE__ << "): "
class WPBST;

class WPBST {
private: 
    class Node {
    public:
        Node(const pair<long, long>& key, const string& val, shared_ptr<Node> mom = nullptr, shared_ptr<Node> dad = nullptr, shared_ptr<Node> left = nullptr, shared_ptr<Node> right = nullptr);
        ~Node();
        friend class WPBST;
    private:
        pair<long, long> m_key;
        string m_val;
        weak_ptr<Node> p_mom, p_dad;
        shared_ptr<Node> p_left, p_right; 
    };
public:
    WPBST();
    ~WPBST();
    pair<long, long> get(const string& dir);
    string get(const pair<long, long>& key);
protected:
    void put(const pair<long, long>& key, const string& val = "");
    shared_ptr<Node> put(shared_ptr<Node> x, shared_ptr<Node> mom, shared_ptr<Node> dad, const pair<long, long>& key, const string& val);
    shared_ptr<Node> get(shared_ptr<Node> x, const pair<long, long>& key);
    int compareKey(const pair<long, long>& p1, const pair<long, long>& p2);
    long getGCD(long a, long b);
private:
    shared_ptr<Node> p_root, p_rootMom, p_rootDad;
};
#endif /* TESTBST_H_ */