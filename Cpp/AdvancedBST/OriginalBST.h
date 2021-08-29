#ifndef ORIGINALBST_H_
#define ORIGINALBST_H_

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class OriginalBST;

class OriginalBST {
private:
    class Node {
    public:
        Node(int key, const string& val, shared_ptr<Node> left = nullptr, shared_ptr<Node> right = nullptr);
        ~Node();
        friend class OriginalBST;
    private:
        int m_key;
        string m_val;
        shared_ptr<Node> p_left, p_right;
    };
public:
    OriginalBST();
    ~OriginalBST();
    void put(int key, const string& val = "");
    string get(int key);
protected:
    shared_ptr<Node> put(shared_ptr<Node> x, int key, const string& val);
    shared_ptr<Node> get(shared_ptr<Node> x, int key);
private:
    shared_ptr<Node> p_root;
};

#endif /* ORIGINALBST_H_ */