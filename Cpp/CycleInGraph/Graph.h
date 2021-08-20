#ifndef GRAPH_H_
#define GRAPH_H_

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(const string& filename);
    ~Graph();
    int getV() const;
    int getE() const;
    vector<int> getAdj(int v) const;
    void addEdge(int v, int w);

protected:
    void split(const string& line, char c, vector<string>& splitted);

private:
    int m_V, m_E;
    vector<vector<int>> m_adjs; // Adjacency list
};

#endif /* GRAPH_H_ */