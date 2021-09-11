#include "BFP.h"
#include <queue>

BFP::BFP(const vector<string>& maze, const pair<int, int>& s) : m_maze(maze), m_s(s) {
    int h = maze.size();
    int w = maze.front().length();
    m_marked.resize(h, vector<bool>(w, false));
    bfs();
}

BFP::~BFP() {}

bool BFP::isValid(const pair<int, int>& p) {
    int h = m_maze.size();
    int w = m_maze.front().length();
    return (p.first >= 0 && p.first < h && p.second >= 0 && p.second < w && m_maze.at(p.first).at(p.second) != '#');
}

void BFP::bfs() {
    queue<pair<int, int>> q;
    q.push(m_s);
    vector<pair<int, int>> nexts = {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0)};
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto next : nexts) {
            auto w = make_pair(v.first + next.first, v.second + next.second);
            if (isValid(w) && !m_marked.at(w.first).at(w.second)) {
                m_marked.at(w.first).at(w.second) = true;
                m_edgeTo[w] = v;
                q.push(w);
            }
        }
    }
}

bool BFP::hasPathTo(const pair<int, int>& v) {
    return m_marked.at(v.first).at(v.second);
}

vector<pair<int, int>> BFP::pathTo(const pair<int, int>& v) {
    vector<pair<int, int>> path;
    if (!hasPathTo(v)) return path;
    for (auto x = v; x != m_s; x = m_edgeTo.at(x)) {
        path.insert(path.begin(), x);
    }
    path.insert(path.begin(), m_s);
    return path;
}
