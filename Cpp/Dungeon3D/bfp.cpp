#include "bfp.h"
#include <queue>
#include <iostream>

BFP::BFP(const vector<vector<string>> &maze, const Point &s) : m_maze(maze), m_s(s) {
    int l = maze.size();
    int h = maze.front().size();
    int w = maze.front().front().size();
    m_marked.resize(l, vector<string>(h, string(w, '0'))); 
    bfs();   
}

void BFP::bfs() {
    queue<Point> q;
    m_marked.at(m_s.first).at(m_s.second.first).at(m_s.second.second) = '1';
    q.push(m_s);
    vector<Point> nexts = { make_pair(0, make_pair(0, 1)), 
                            make_pair(0, make_pair(0, -1)), 
                            make_pair(0, make_pair(1, 0)), 
                            make_pair(0, make_pair(-1, 0)),
                            make_pair(1, make_pair(0, 0)),
                            make_pair(-1, make_pair(0, 0))};
    while (!q.empty()) {
        Point v = q.front();
        q.pop();
        for (auto next : nexts) {
            Point w = make_pair(v.first + next.first, make_pair(v.second.first + next.second.first, v.second.second + next.second.second));
            if (isValid(w) && m_marked.at(w.first).at(w.second.first).at(w.second.second) == '0') {
                m_marked.at(w.first).at(w.second.first).at(w.second.second) = '1';
                m_edgeTo[w] = v;
                q.push(w);
            }
        }
    }
}

bool BFP::isValid(const Point &v) {
    int l = m_maze.size();
    int h = m_maze.front().size();
    int w = m_maze.front().front().size();
    return (v.first >= 0 && v.first < l 
            && v.second.first >= 0 && v.second.first < h
            && v.second.second >= 0 && v.second.second < w
            && m_maze.at(v.first).at(v.second.first).at(v.second.second) != '#');
}

bool BFP::hasPathTo(const Point &v) {
    return m_marked.at(v.first).at(v.second.first).at(v.second.second) == '1';
}

vector<Point> BFP::pathTo(const Point &v) {
    vector<Point> path;
    for (auto x = v; x != m_s; x = m_edgeTo.at(x)) {
        path.insert(path.begin(), x);
    }
    path.insert(path.begin(), m_s);
    return path;
}