#ifndef BFP_H_
#define BFP_H_

#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair<int, pair<int, int>> Point;

class BFP {
public:
    BFP(const vector<vector<string>> &maze, const Point &s);
    ~BFP() {}
    bool hasPathTo(const Point &v);
    vector<Point> pathTo(const Point &v);

protected:
    bool isValid(const Point &v);
    void bfs();

private:
    Point m_s;
    vector<vector<string>> m_maze;
    vector<vector<string>> m_marked;
    map<Point, Point> m_edgeTo;
};

#endif // BFP_H_