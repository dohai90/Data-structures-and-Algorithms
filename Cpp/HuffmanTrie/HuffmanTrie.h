#ifndef HUFFMANTRIE_H_
#define HUFFMANTRIE_H_

#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define DEBUG_INFO __FUNCTION__ << "(" << __LINE__ << "): "

class HuffmanTrie;

class Node {
public:
    Node(char ch, Node* left = nullptr, Node* right = nullptr);
    ~Node();
    bool isLeaf() const;

private:
    char m_ch;
    Node* m_pleft;
    Node* m_pright;
    friend class HuffmanTrie;
};

class HuffmanTrie {
public:
    HuffmanTrie();
    HuffmanTrie(const string& filename);
    ~HuffmanTrie();
    void buildTrie(const string& key, char val);
    string expand(const string& bitstream);

private:
    void removeTrie(Node*& x);
    void split(const string& input, char del, vector<string>& v);

private:
    Node* m_proot;
};

#endif