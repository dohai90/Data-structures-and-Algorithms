#ifndef RATINMAZE_H_
#define RATINMAZE_H_

#include <iostream>
#include <vector>

using namespace std;

#define DEBUG_INFO __FUNCTION__ << "(" << __LINE__ << "): "

class RatInMaze {
public:
    RatInMaze(int N);
    ~RatInMaze() {}
    bool isSafe(int y, int x, vector<vector<int> >&  maze) const;
    bool solve(int y, int x, vector<vector<int> >&  maze);
    vector<vector<int> > getSolution() const;

protected:
    bool solve(int y, int x, vector<int>& ymove, vector<int>& xmove, vector<vector<int> >&  maze);

private:
    int m_N;
    vector<vector<int> > m_sol;
};

#endif