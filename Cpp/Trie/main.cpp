#include "Trie.h"
#include "TrieSP.h"
#include <fstream>


int main() {
    cout << "Test case 1" << endl;
    int sea = 1;
    int shells = 2;
    int shore = 3;
    int d = 4;
    int dd= 5;
    int ddd = 6;

    cout << "\nTest case 1.1: with raw pointer" << endl;
    Trie trie;
    trie.put("sea", sea);
    trie.put("shells" , shells);
    trie.put("shore", shore);
    trie.put("d", d);
    trie.put("dd", dd);
    trie.put("ddd", ddd);

    cout << "value of sea " << to_string(trie.get("sea")) << endl;
    cout << "value of shells " << to_string(trie.get("shells")) << endl;
    cout << "value of d " << to_string(trie.get("d")) << endl;
    cout << "value of dd " << to_string(trie.get("dd")) << endl;
    cout << "value of ddd " << to_string(trie.get("ddd")) << endl;
    cout << "size of trie: " << trie.size() << endl;
    trie.remove("sea");
    cout << "size of trie: " << trie.size() << endl;
    cout << "prefix of shells is " << trie.uniquePrefixOf("shells") << endl;
    cout << "prefix of sea is " << trie.uniquePrefixOf("sea") << endl;
    cout << "prefix of d is " << trie.uniquePrefixOf("d") << endl;
    cout << "prefix of dd is " << trie.uniquePrefixOf("dd") << endl;
    cout << "prefix of ddd is " << trie.uniquePrefixOf("ddd") << endl;

    cout << "\nTest case 1.2: with smart pointer" << endl;
    TrieSP triesp;
    triesp.put("sea", sea);
    triesp.put("shells" , shells);
    triesp.put("shore", shore);
    triesp.put("d", d);
    triesp.put("dd", dd);
    triesp.put("ddd", ddd);

    cout << "value of sea " << to_string(triesp.get("sea")) << endl;
    cout << "value of shells " << to_string(triesp.get("shells")) << endl;
    cout << "value of shore " << to_string(triesp.get("shore")) << endl;
    cout << "value of d " << to_string(triesp.get("d")) << endl;
    cout << "value of dd " << to_string(triesp.get("dd")) << endl;
    cout << "value of ddd " << to_string(triesp.get("ddd")) << endl;
    cout << "size of trie: " << triesp.size() << endl;
    triesp.remove("sea");
    cout << "size of trie: " << triesp.size() << endl;

    cout << "\nTest case 2" << endl;
    string line;
    int val = 0;
    ifstream myfile("data.txt");
    vector<string> words;
    
    if (myfile.is_open()) {
        while(getline(myfile, line)) {
            trie.put(line, val);
            triesp.put(line, val);
            words.push_back(line);
        }
        myfile.close();
    }

    cout << "\nTest case 2.1 with raw pointer" << endl;
    for (uint i = 0; i < words.size(); i++) {
        cout << "prefix of " << words.at(i) << " is " << trie.uniquePrefixOf(words.at(i)) << endl;
    }

    cout << "\nTest case 2.2 with smart pointer" << endl;
    for (uint i = 0; i < words.size(); i++) {
        cout << "prefix of " << words.at(i) << " is " << triesp.uniquePrefixOf(words.at(i)) << endl;
    }

    return 0;
}