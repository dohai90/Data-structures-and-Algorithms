#ifndef SPBST_H_
#define SPBST_H_

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define DB_INFO __FUNCTION__ << "(" << __LINE__ << "): "
class SPBST;

class SPBST {
private:
    class Node {
    public:
        Node(const pair<long, long>& key, const string& val, shared_ptr<Node> mom = nullptr, shared_ptr<Node> dad = nullptr, shared_ptr<Node> left = nullptr, shared_ptr<Node> right = nullptr);
        ~Node();
        friend class SPBST;
    private:
        pair<long, long> m_key;
        string m_val;
        shared_ptr<Node> p_mom, p_dad, p_left, p_right; 
    };
public:
    SPBST();
    ~SPBST();
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
#endif /* SPBST_H_ */