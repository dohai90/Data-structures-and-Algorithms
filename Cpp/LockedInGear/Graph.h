#ifndef GRAPH_H_
#define GRAPH_H_

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Graph {
public:
    Graph(const string& filename);
    ~Graph();
    int getV() const;
    int getE() const;
    vector<int> getAdj(int v) const;
    void addEdge(int v, int w);
    string toString() const;

protected:
    void split(const string& line, char c, vector<string>& splitted);
    float getDistBetween(const pair<int, int>& p1, const pair<int, int>& p2) const;
    bool isEqual(float d1, float d2, float epsilon = 0.00001) const;

private:
    int m_V, m_E;
    vector<vector<int>> m_adjs; // Adjacency list
    vector<pair<pair<int, int>, int>> m_vertices;
};

#endif /* GRAPH_H_ */