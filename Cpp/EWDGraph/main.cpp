#include <iostream>
#include <algorithm>
#include "EWDGraph.h"
#include "SP.h"

using namespace std;

int main() {
    EWDGraph G("tinyEWD.txt");
    for(int v = 0; v < G.getV(); v++) {
        cout << v << ": ";
        for(DEdge* e : G.getAdj(v)) {
            cout << e->toString() << " ";
        }
        cout << endl;
    }

    SP sp(G, 0);
    int target = 6;
    if(sp.hasPathTo(target)) {
        vector<DEdge*> path = sp.pathTo(target);
        cout << "Total weight to " << target << " is " << sp.distTo(target) << endl;
        cout << "Path to " << target << " is as follow:" << endl;
        for(DEdge* e : path) 
            cout << e->toString() << " ";
    }
    cout << endl;

    return 0;
}