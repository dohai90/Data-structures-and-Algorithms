#include "DFCycle.h"

DFCycle::DFCycle(const Graph& G) {
    int V = G.getV();
    m_color.resize(V, WHITE);
    m_edgeTo.resize(V, -1);
    for (int v = 0; v < V; v++) {
        if (m_color.at(v) == WHITE) dfs(G, v, v);
    }
}

DFCycle::~DFCycle() {}

void DFCycle::dfs(const Graph& G, int cur, int par) {
    if (m_color.at(cur) == BLACK) return;
    if (m_color.at(cur) == GREY) {
        vector<int> cycle;
        for (int x = par; x != cur; x = m_edgeTo.at(x)) {
            cycle.push_back(x);
        }
        cycle.push_back(cur);
        m_cycles.push_back(cycle);
        return;
    }

    m_color.at(cur) = GREY;
    m_edgeTo.at(cur) = par;
    for (int w : G.getAdj(cur)) {
        if (w != par) dfs(G, w, cur);
    }
    m_color.at(cur) = BLACK;
}

bool DFCycle::hasCycles() const {
    return !m_cycles.empty();
}

const vector<vector<int>>& DFCycle::getCycles() const {
    return m_cycles;
}