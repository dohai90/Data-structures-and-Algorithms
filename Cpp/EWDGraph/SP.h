#ifndef SP_H_
#define SP_H_

#include <limits>
#include <queue>
#include "EWDGraph.h"

using namespace std;

#define POSITIVE_INFINITY numeric_limits<double>::max()

/* Dijkstra's algorithm */
class SP {
public:
    SP(const EWDGraph& G, int s);
    ~SP();
    double distTo(int v) const;
    bool hasPathTo(int v) const;
    vector<DEdge*> pathTo(int v) const;

protected:
    void relax(const EWDGraph& G, int v);
private:
    vector<DEdge*> m_edgeTo;
    vector<double> m_distTo;
    //Weight (or distance) is used as first item  of pair because first item is used to compare two pairs by default
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
};

#endif /* END SP_H_*/