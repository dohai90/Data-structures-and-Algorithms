#include "RatInMaze.h"


RatInMaze::RatInMaze(int N) : m_N(N) {
    vector<int> row(m_N, 0);
    m_sol.resize(m_N);
    fill(m_sol.begin(), m_sol.end(), row);
}

/*
In maze, 1 is life point, 0 is dead point
*/
bool RatInMaze::isSafe(int y, int x, vector<vector<int> >& maze) const{
    return (y >= 0 && y < m_N && x >= 0 && x < m_N && maze.at(y).at(x) == 1 && m_sol.at(y).at(x) != 1);
}

bool RatInMaze::solve(int y, int x, vector<vector<int> >& maze) {
    vector<int> ymove{0,  0, 1, -1};
    vector<int> xmove{1, -1, 0,  0};

    if(isSafe(y, x, maze))
        m_sol.at(y).at(x) = 1;
    else return false;
    if(solve(y, x, ymove, xmove, maze))
        return true;
    return false;
}

bool RatInMaze::solve(int y, int x, vector<int>& ymove, vector<int>& xmove, vector<vector<int> >& maze) {
    // base case
    if(y == m_N - 1 && x == m_N - 1 && maze.at(y).at(x) == 1) 
        return true;

    for(int i = 0; i < 4; i++) {
        int ynext = y + ymove.at(i);
        int xnext = x + xmove.at(i);
        
        if(isSafe(ynext, xnext, maze)) {
            // cout << DEBUG_INFO << ynext << " " << xnext << endl;
            m_sol.at(ynext).at(xnext) = 1;
            if(solve(ynext, xnext, ymove, xmove, maze)) 
                return true;
            else {
                m_sol.at(ynext).at(xnext) = 0; // backtracking                
            }
        }
    }

    return false;
}

vector<vector<int> > RatInMaze::getSolution() const {
    return m_sol;
}