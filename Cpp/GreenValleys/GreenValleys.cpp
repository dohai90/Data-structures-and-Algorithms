#include "GreenValleys.h"
#include <fstream>

CC::CC(const string &filename) : m_count(0) {
    ifstream myfile(filename);
    string line;
    vector<int> splitted;
    uint ln = 0;
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            split(line, ' ', splitted);
            if (ln == 0) {
                m_H = static_cast<uint>(splitted.front());
            } else if (ln == 1) {
                // do nothing
            } else {
                m_maze.push_back(splitted);
            }
            ln++;
        }
        init();
        myfile.close();
    }
}

CC::CC(const vector<vector<int>> &maze, uint H) : m_count(0), m_H(H), m_maze(maze) {
    init();
}

void CC::init() {
    uint h = m_maze.size();
    uint w = m_maze.front().size();
    m_marked.resize(h, vector<bool>(w, false));
    m_id.resize(h, vector<int>(w, 0));
    for (uint i = 0; i < h; i++) {
        for (uint j = 0; j < w; j++) {
            Point s = make_pair(i, j);
            if (isValley(s) && !m_marked.at(i).at(j)) {
                m_count++;
                dfs(s);
            }
        }
    }
}

void CC::dfs(const Point &v) {
    m_marked.at(v.first).at(v.second) = true;
    m_id.at(v.first).at(v.second) = m_count;
    vector<Point> nexts = { make_pair(0, 1),
                            make_pair(0, -1),
                            make_pair(-1, 0),
                            make_pair(1, 0)};
    for (auto next : nexts) {
        Point w = make_pair(v.first + next.first, v.second + next.second);
        if (isValley(w) && !m_marked.at(w.first).at(w.second)) dfs(w);
    }
}

bool CC::isValley(const Point &v) {
    uint h = m_maze.size();
    uint w = m_maze.front().size();
    return (v.first >= 0 && v.first < h 
            && v.second >= 0 && v.second < w
            && m_maze.at(v.first).at(v.second) <= m_H);
}

int CC::count() const {
    return m_count;
}

int CC::getId(const Point &v) const {
    return m_id.at(v.first).at(v.second);
}

void CC::split(const string &line, char c, vector<int> &splitted) {
    splitted.clear();
    size_t i = 0;
    size_t j = line.find(c);
    while(j != string::npos) {
        splitted.push_back(stoi(line.substr(i, j - i)));
        i = ++j;
        j = line.find(c, i);
    }
    if (j == string::npos) 
        splitted.push_back(stoi(line.substr(i)));
}

int CC::getDeepestPoint() const {
    vector<vector<Point>> valleys(m_count);
    uint h = m_maze.size();
    uint w = m_maze.front().size();
    for (int id = 1; id <= m_count; id++) {
        for (uint i = 0; i < h; i++) {
            for (uint j = 0; j < w; j++) {
                if (m_id.at(i).at(j) == id) {
                    valleys.at(id - 1).push_back(make_pair(i, j));
                } 
            }
        }
    }

    // finding largest area
    int largestValleyArea = 0;
    for (uint i = 0; i < m_count; i++) {
        int valleyArea = valleys.at(i).size();
        largestValleyArea = max(largestValleyArea, valleyArea);
    }

    // finding deepest point among areas
    int deepestPoint = INT32_MAX;
    for (uint i = 0; i < m_count; i++) {
        int valleyArea = valleys.at(i).size();
        if (valleyArea == largestValleyArea) {
            for (uint j = 0; j < valleyArea; j++) {
                auto p = valleys.at(i).at(j);
                deepestPoint = min(deepestPoint, m_maze.at(p.first).at(p.second));
            }
        }
    }
    
    return (m_count == 0)? 0 : deepestPoint;
}

string CC::toString() {
    string s = "";
    uint h = m_maze.size();
    uint w = m_maze.front().size();
    for (uint i = 0; i < h; i++) {
        for (uint j = 0; j < w; j++) {
            s += to_string(m_id.at(i).at(j)) + " ";
        }
        s += "\n";
    }
    return s;
}