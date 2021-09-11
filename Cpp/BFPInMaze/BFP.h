#ifndef BFP_H_
#define BFP_H_

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class BFP {
public:
    BFP(const vector<string>& maze, const pair<int, int>& s);
    ~BFP();
    bool hasPathTo(const pair<int, int>& v);
    vector<pair<int, int>> pathTo(const pair<int, int>& v);
protected:
    void bfs();
    bool isValid(const pair<int, int>& p);
private:
    vector<vector<bool>> m_marked;
    map<pair<int, int>, pair<int, int>> m_edgeTo;
    pair<int, int> m_s;
    vector<string> m_maze;
};

#endif /* BFP_H_ */