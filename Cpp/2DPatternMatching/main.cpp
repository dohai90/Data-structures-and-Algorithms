#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG_INFO __FUNCTION__ << "(" << __LINE__ << "): "

size_t search(const string& segment, const string& obj1D, size_t pos) {
    size_t segmentLen = segment.length();
    size_t obj1DLen = obj1D.length();

    for (size_t i = pos; i <= segmentLen - obj1DLen; i++) {
        size_t j;
        for (j = 0; j< obj1DLen; j++) {
            if(obj1D.at(j) == '*' && segment.at(i + j) != '.') break;
        }
        if(j == obj1DLen) return i;
    }
    return string::npos;
}

bool isMatched(const string& grid1D, size_t grid2DWidth, const vector<string>& obj2D, vector<uint>& res) {
    if(!res.empty()) res.clear();
    size_t obj2DWidth = obj2D.front().length();
    size_t obj2DHeight = obj2D.size();
    
    for (size_t i = 0; i < grid1D.length(); i++) {
        size_t j = 0;
        size_t k = search(grid1D, obj2D.at(j++), i);
        if(k == string::npos) break;
        size_t startRow = k / grid2DWidth;
        size_t endRow = (k + obj2DWidth - 1) / grid2DWidth;
        if(startRow != endRow) continue;
        i = k;
        
        while(j < obj2DHeight) {
            size_t matchedAt = search(grid1D, obj2D.at(j), k + grid2DWidth);
            if(matchedAt == k + grid2DWidth) {
                k += grid2DWidth;
                j++;
            } else break;
        }
        if(j == obj2DHeight) {
            cout << "Full matched at " << i << endl; 
            res.push_back(i);
        }
    }

    return res.empty()? false : true;
}

void insertObj(string& segment, const string& obj1D, size_t pos) {
    size_t obj1DLen = obj1D.length();
    for(size_t j = 0; j < obj1DLen; j++) {
        if(obj1D.at(j) == '*') segment.replace(pos + j, 1, 1, '*');
    }
}

int main() {
    vector<string> grid{    "#..#######",
                            "#.##..####",
                            "###..##...",
                            "####.#####",
                            "##.#######",
                            "##......##",
                            "##.....###",
                            "########.."};

    vector<string> obj2D{ ".*",
                        "**",
                        ".*"};

    // vector<string> grid{    ".#.#",
    //                         "##..",
    //                         "....",
    //                         "##.#"};
    // vector<string> pat{"**"};
                            
    string grid1D = "";
    for (string& str : grid) grid1D += str;
     
    vector<uint> matchedAt;
    size_t d = grid.front().length();
    if(isMatched(grid1D, d, obj2D, matchedAt)) {
        cout << matchedAt.size() << endl;
        if(matchedAt.size() == 1) {
            uint i = matchedAt.front();
            for (string& str : obj2D) {
                insertObj(grid1D, str, i);
                i += d;
            }
            uint j = 0;
            while(j < grid1D.length()) {
                cout << grid1D.substr(j, d) << endl;
                j += d;    
            }   
        }
    } else cout << matchedAt.size() << endl;

    return 0;
}