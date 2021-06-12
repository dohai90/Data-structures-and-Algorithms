#include <iostream>
#include "HuffmanTrie.h"

Node::Node(char ch, Node* left, Node* right) : m_ch(ch), m_pleft(left), m_pright(right) {}

Node::~Node() {}

bool Node::isLeaf() const {
    return (m_pleft == nullptr) && (m_pright == nullptr);
}

HuffmanTrie::HuffmanTrie() {
    m_proot = new Node('\0');
}

HuffmanTrie::HuffmanTrie(const string& filename) {
    m_proot = new Node('\0');
    string line;
    string bitstream;
    ifstream myfile(filename);
    vector<string> splitted_str;
    if(myfile.is_open()) {
        while(getline(myfile, line)) {
            splitted_str.clear();
            split(line, ' ', splitted_str);
            if(splitted_str.size() != 0) {
                string key = splitted_str.at(0);
                string val = splitted_str.at(1);
                buildTrie(key, static_cast<char>(stoi(val)));
            }else{
                if(line.length() != 0)
                    bitstream = line;
            }
        }
        myfile.close();
    }
    
    string res = expand(bitstream);
    cout << DEBUG_INFO << res << endl;
}

HuffmanTrie::~HuffmanTrie() {
    while(!m_proot->isLeaf())
        removeTrie(m_proot);
    removeTrie(m_proot);
}

void HuffmanTrie::buildTrie(const string& key, char val) {
    Node* parent = m_proot;
    unsigned int len = key.length();
    for(unsigned int i = 0; i < len; i++) {
        if(key.at(i) == '0') {
            if(parent->m_pleft == nullptr) {
                Node* child = new Node('\0');
                // cout << DEBUG_INFO << "[Created]child address: " << child << endl; 
                parent->m_pleft = child;
            }
            parent = parent->m_pleft;
        }else {
            if(parent->m_pright == nullptr) {
                Node* child = new Node('\0');
                // cout << DEBUG_INFO << "[Created]child address: " << child << endl;
                parent->m_pright = child;
            }
            parent = parent->m_pright;
        }
    }
    parent->m_ch = val;
}

string HuffmanTrie::expand(const string& bitstream) {
    string res = "";
    unsigned int len = bitstream.length();
    unsigned int idx = 0;
    Node* x = m_proot;

    for(unsigned int i = 0; i < len; i++) {               
        if(bitstream.at(i) == '0') { 
            x = x->m_pleft;   
        }else {
            x = x->m_pright;
        }
        
        if(x == nullptr) {
            res = "DECODE FAIL AT INDEX " + to_string(i - idx);
            return res;
        }

        idx++; //valid step
        if(x->isLeaf()) { 
            res += x->m_ch;
            cout << DEBUG_INFO << res << endl;
            idx = 0;
            x = m_proot;
        }    
    }
    
    if(x != m_proot) {
        res = "DECODE FAIL AT INDEX " + to_string(len - idx);
    }
    return res;
}

void HuffmanTrie::removeTrie(Node*& x) {
    if(x == nullptr) return;
    if(x->isLeaf()) {
        delete x;
        // cout << DEBUG_INFO << "[Deleting]child address: " << x << endl;
        x = nullptr;
        return;
    }
    removeTrie(x->m_pleft);
    removeTrie(x->m_pright);
}


void HuffmanTrie::split(const string& input, char del, vector<string>& v) {
    string::size_type i = 0;
    string::size_type j = input.find(del);
    while(j != string::npos) {
        v.push_back(input.substr(i, j - i));
        i = ++j;
        j = input.find(del, i);
        if(j == string::npos) 
            v.push_back(input.substr(i));
    }
}
