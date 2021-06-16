#include "RatInMaze.h"

int main() {
    RatInMaze rat(4);

    vector<vector<int> > maze { { 1, 1, 0, 1 },
                                { 1, 1, 0, 1 },
                                { 1, 1, 0, 1 },
                                { 1, 1, 1, 1 } };

    int ystart = 0;
    int xstart = 0;
    if(rat.solve(ystart, xstart, maze)) {
        cout << DEBUG_INFO << "Found a path!" << endl;
        vector<vector<int> > sol = rat.getSolution();
        for(auto it1 = sol.begin(); it1 != sol.end(); ++it1) {
            for(auto it2 = it1->begin(); it2 != it1->end(); ++it2) 
                cout << *it2 << " ";
            cout << endl;
        }
    }
    return 0;
}