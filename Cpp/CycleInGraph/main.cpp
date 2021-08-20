#include "DFCycle.h"

int main() {
    Graph G("tinyG.txt");
    DFCycle dfc(G);
    if (dfc.hasCycles()) {
        auto cycles = dfc.getCycles();
        for (auto cycle : cycles) {
            for (int v : cycle) 
                cout << v << " ";
            cout << endl;
        }
    }
    return 0;
}