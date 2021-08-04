#include <fstream>
#include "GeneralTree.h"

using namespace std;

int main() {
    GeneralTree tree;
    string line;
    ifstream myfile("data.txt");
    int count = 0;

    if(myfile.is_open()) {
        while (getline(myfile, line)) {
            Person p(line);
            if(count == 0) {
                tree.addRoot(p);
                count++;
            } else tree.put(p);    
        }   
        myfile.close();
    }
    tree.printPreOrder();
    cout << endl;
}