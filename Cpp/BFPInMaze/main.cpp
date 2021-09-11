#include "BFP.h"

int main() {
    vector<string> maze = { "##########",
                            "#...#....#",
                            "#.C.#.#..#",
                            "###.#..###",
                            "#M#......#",
                            "#.###.#..#",
                            "#.#....#.#",
                            "#..#.##..#",
                            "#........#",
                            "##########"};

    int h = maze.size();
    int w = maze.front().length();
    pair<int, int> c, m;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze.at(i).at(j) == 'M') m = make_pair(i, j);
            else if (maze.at(i).at(j) == 'C') c = make_pair(i, j);
        }
    }

    BFP bfp(maze, c);
    auto path = bfp.pathTo(m);
    for (auto p : path) {
        if(p == c || p == m) continue;
        maze.at(p.first).replace(p.second, 1, 1, '1');
    }

    for (string s : maze) 
        cout << s << endl;
    
    cout << "Distance: " << to_string((path.size() - 1) * 10) << "km" << endl;
}