#ifndef DFPATH_H_
#define DFPATH_H_

#include "Graph.h"

class DFPath {
public:
    DFPath(const Graph& G, int s);
    ~DFPath();
    bool hasPathTo(int v) const;
    vector<int> pathTo(int v) const;

protected:
    void dfs(const Graph& G, int v);

private:
    int m_s;
    vector<bool> m_marked;
    vector<int> m_edgeTo;
};

#endif /* DFPATH_H_ */