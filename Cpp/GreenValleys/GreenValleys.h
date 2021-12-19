#ifndef GREENVALLEYS_H_
#define GREENVALLEYS_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define DEBUG_INFO __FUNCTION__ << "(" << __LINE__ << "): "
typedef pair<int, int> Point;

class CC {
public:
    CC(const string &filename);
    CC(const vector<vector<int>> &maze, uint H);
    ~CC() {}
    int getId(const Point &v) const;
    int count() const;
    int getDeepestPoint() const;
    string toString();
protected:
    void init();
    void dfs(const Point &v);
    bool isValley(const Point &v);
    void split(const string &str, char c, vector<int> &splitted);
private:
    int m_count, m_H;
    vector<vector<bool>> m_marked;
    vector<vector<int>> m_id, m_maze;
};

#endif /* GREENVALLEYS_H_ */