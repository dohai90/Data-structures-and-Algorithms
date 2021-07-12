#ifndef EWDGRAPH_H_
#define EWDGRAPH_H_

#include <vector>
#include "DEdge.h"

class EWDGraph {
public:
    EWDGraph(const string& filename);
    ~EWDGraph();
    void addEdge(DEdge* e);
    int getV() const;
    int getE() const;
    vector<DEdge*> getAdj(int v) const;

protected:
    void split(const string& line, char c, vector<string>& splitted_str);

private:
    int m_V;
    int m_E;
    vector<vector<DEdge*> > m_adjs;
};

#endif /* End EDGRAPH_H_ */