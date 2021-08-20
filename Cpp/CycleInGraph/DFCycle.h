#ifndef DFCYCLE_H_
#define DFCYCLE_H_

#include "Graph.h"

#define WHITE   0
#define GREY    1
#define BLACK   2

class DFCycle {
public:
    DFCycle(const Graph& G);
    ~DFCycle();
    bool hasCycles() const;
    const vector<vector<int>>& getCycles() const;

protected:
    void dfs(const Graph& G, int cur, int par);

private:
    vector<int> m_color;
    vector<int> m_edgeTo;
    vector<vector<int>> m_cycles;
};

#endif /* DFCYCLE_H_*/