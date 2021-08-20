#include "DFCycle.h"
#include "DFPath.h"

int main() {
    Graph G("tinyG.txt");
    cout << G.toString() << endl;
    int source = 0;
    int target = G.getV() - 1;

    DFPath dfp(G, source);
    if (dfp.hasPathTo(target)) {
        DFCycle dfc(G);
        if (dfc.hasCycles()) {
            auto cycles = dfc.getCycles();
            for (auto cycle : cycles) {
                if (cycle.size() % 2 == 1 && dfp.hasPathTo(cycle.front())) {
                    cout << "1.NOT MOVING" << endl;
                    return 0;
                }
            }
        }
        auto path = dfp.pathTo(target);
        if (path.size() % 2 == 0) cout << "CCW" << endl;
        else                      cout << "CW" << endl;
    } else {
        cout << "2.NOT MOVING" << endl;
    }
    
    return 0;
}