#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(int y, int x, int gridHeight, int gridWidth) {
    return (y >= 0 && y < gridHeight && x >= 0 && x < gridWidth);
}

void playConwayGameOfLife(int N, vector<string>& grid, const string& alive, const string& dead) {
    vector<int> ymove{-1, -1, -1,  0, 0,  1, 1, 1};
    vector<int> xmove{-1,  0,  1, -1, 1, -1, 0, 1};
    int step = ymove.size();
    int gridHeight = grid.size();
    int gridWidth = grid.front().length();
    vector<string> succesor(grid);

    for (int n = 0; n < N; n++) {
        for (int i = 0; i < gridHeight; i++) {
            for (int j = 0; j < gridWidth; j++) {
                int count = 0;
                for (int k = 0; k < step; k++) {
                    int yneighbor = i + ymove.at(k);
                    int xneighbor = j + xmove.at(k);
                    
                    if(isValid(yneighbor, xneighbor, gridHeight, gridWidth)) {
                        if(grid.at(yneighbor).at(xneighbor) == 'O') count++;
                    }
                }
                if(grid.at(i).at(j) == 'O') {
                    bool aliveCondition = false;
                    for (int cd = 0; cd < alive.length(); cd++) {
                        if(alive.at(cd) == '1' && count == cd) {
                            aliveCondition = true;
                            break;
                        }
                    }
                    if(!aliveCondition)
                        succesor.at(i).replace(j, 1, 1, '.');
                }

                if(grid.at(i).at(j) == '.') {
                    bool deadCondition = false;
                    for (int cd = 0; cd < dead.length(); cd++) {
                        if(dead.at(cd) == '1' && count == cd) {
                            deadCondition = true;
                            break;
                        }
                    }
                    if(deadCondition)
                        succesor.at(i).replace(j, 1, 1, 'O');
                }
            }
        }
        grid = succesor;
        cout << "Round: " << to_string(n + 1) << endl;
        for(string& str : grid)
            cout << str << endl;
    }
}

int main()
{
    vector<string> grid{    ".....",
                            ".OOO.",
                            ".OOO.",
                            ".OOO.",
                            "....."};

    playConwayGameOfLife(10, grid, "001100000", "000100000");
    
    cout << endl;
}