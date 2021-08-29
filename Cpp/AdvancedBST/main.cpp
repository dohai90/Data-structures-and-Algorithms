#include "OriginalBST.h"
#include "SPBST.h"
#include "WPBST.h"

int main() {
    SPBST spbst;
    cout << spbst.get(make_pair(1, 2)) << endl;
    cout << spbst.get(make_pair(3, 5)) << endl;
    cout << spbst.get(make_pair(5, 2)) << endl;
    cout << spbst.get(make_pair(6, 2)) << endl;
    string dir = "LLRRR";
    auto spkey = spbst.get(dir);
    cout << "Key of " << dir << " is: " << spkey.first << "/" << spkey.second << endl;

    cout << "WPBST start:" << endl;
    WPBST wpbst; 
    cout << wpbst.get(make_pair(1, 2)) << endl;
    cout << wpbst.get(make_pair(3, 5)) << endl;
    cout << wpbst.get(make_pair(5, 2)) << endl;
    cout << wpbst.get(make_pair(6, 2)) << endl;
    dir = "LLRRR";
    auto wpkey = wpbst.get(dir);
    cout << "Key of " << dir << " is: " << wpkey.first << "/" << wpkey.second << endl;
    return 0;
}