#include "SP.h"

SP::SP(const EWDGraph& G, int s) {
    int V = G.getV();
    m_edgeTo.resize(V, nullptr);
    m_distTo.resize(V, POSITIVE_INFINITY);
    m_distTo.at(s) = 0;
    pq.push(make_pair(m_distTo.at(s), s));
    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        relax(G, v);
    }
    
    for(int v = 0; v < V; v++)
        cout << v << " edgeTo: " << (v != s? m_edgeTo.at(v)->toString() : "nullptr") << " distTo: " << m_distTo.at(v) << endl;
}

SP::~SP() {}

double SP::distTo(int v) const {
    return m_distTo.at(v);
}

bool SP::hasPathTo(int v) const {
    return m_distTo.at(v) < POSITIVE_INFINITY;
}

vector<DEdge*> SP::pathTo(int v) const {
    vector<DEdge*> path;
    if(!hasPathTo(v)) {
        path.resize(0);
        return path;
    }
    for (DEdge* e = m_edgeTo.at(v); e != nullptr; e = m_edgeTo.at(e->from())) 
        path.insert(path.begin(), e);
    return path;
}

void SP::relax(const EWDGraph& G, int v) {
    for (DEdge* e : G.getAdj(v)) {
        int w = e->to();
        if(m_distTo.at(w) > m_distTo.at(v) + e->getWeight()) {
            m_distTo.at(w) = m_distTo.at(v) + e->getWeight();
            m_edgeTo.at(w) = e;
            pq.push(make_pair(m_distTo.at(w), w)); // (Even if w is already there)
        }
    }
}