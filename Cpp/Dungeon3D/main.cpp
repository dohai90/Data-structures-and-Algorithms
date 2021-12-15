#include "bfp.h"
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

void split(const string &line, char c, vector<string> &splitted_str) {
    size_t i = 0;
    size_t j = line.find(c);
    while (j != string::npos) {
        splitted_str.push_back(line.substr(i, j - i));
        i = ++j;
        j = line.find(c, i);
    }
    if (j == string::npos) {
        splitted_str.push_back(line.substr(i));
    }
}

int main() {
    int l, r, c, ln;
    ifstream myfile("./data.txt");
    string line;
    vector<string> splitted_str;
    vector<vector<string>> maze3D;
    int layer = -1;
    Point A, S;
    if (myfile.is_open()) {
        getline(myfile, line);
        split(line, ' ', splitted_str);
        l = stoi(splitted_str.at(0));
        r = stoi(splitted_str.at(1));
        c = stoi(splitted_str.at(2));
        ln = l * (r + 1);
        cout << l << " " << r << " " << c << " " << ln << endl;
        maze3D.resize(l, vector<string>(r, ""));
        getline(myfile, line);
        for (int i = 0; i < ln; i++) {
            getline(myfile, line);
            if (i % (r + 1) == 0) {
                layer++;
                continue;
            }
            int rIdx = i % (r + 1) - 1;
            int cAIdx = line.find('A');
            int cSIdx = line.find('S');
            maze3D.at(layer).at(rIdx).assign(line.begin(), line.end());
            if (cAIdx != string::npos) {
                A = make_pair(layer, make_pair(rIdx, cAIdx));   
            }
            if (cSIdx != string::npos) {
                S = make_pair(layer, make_pair(rIdx, cSIdx));
            }
        }
    }
    
    for (int i = 0; i < l; i++) {
        for (const string &line : maze3D.at(i))
            cout << line << endl;
    }
    cout << "Anya cord: " << A.first << ", " << A.second.first << ", " << A.second.second << endl;
    cout << "Spring cord: " << S.first << ", " << S.second.first << ", " << S.second.second << endl;

    BFP bfp(maze3D, A);
    if (bfp.hasPathTo(S)) {
        vector<Point> path = bfp.pathTo(S);
        cout << "Min path length is: " << path.size() - 1 << endl;
    } else {
        cout << "NO PATH" << endl;
    }

    return 0;
}
