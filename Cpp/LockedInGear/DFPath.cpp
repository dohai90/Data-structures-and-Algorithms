#include "DFPath.h"

DFPath::DFPath(const Graph& G, int s) : m_s(s) {
    int V = G.getV();
    m_marked.resize(V, false);
    m_edgeTo.resize(V, -1);
    dfs(G, m_s);
}

DFPath::~DFPath() {}

bool DFPath::hasPathTo(int v) const {
    return m_marked.at(v);
}

vector<int> DFPath::pathTo(int v) const {
    vector<int> path;
    if (!hasPathTo(v)) return path;
    for (int x = v; x != m_s; x = m_edgeTo.at(x)) {
        path.insert(path.begin(), x);
    }
    path.insert(path.begin(), m_s);
    return path;
}

void DFPath::dfs(const Graph& G, int v) {
    m_marked.at(v) = true;
    for (int w : G.getAdj(v)) {
        if (!m_marked.at(w)) {
            m_edgeTo.at(w) = v;
            dfs(G, w);
        }
    }
}