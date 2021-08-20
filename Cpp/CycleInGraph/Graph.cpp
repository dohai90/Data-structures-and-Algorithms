#include "Graph.h"

Graph::Graph(const string& filename) : m_V(0), m_E(0) {
    string line;
    ifstream myfile(filename);
    vector<string> splitted;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            split(line, ' ', splitted);
            if(splitted.size() == 1 && m_V == 0) {
                m_V = stoi(splitted.front());
                m_adjs.resize(m_V);
            } else if (splitted.size() == 2) {
                addEdge(stoi(splitted.front()), stoi(splitted.back()));
            }
        }
        myfile.close();
    } else {
        cout << "File not found!" << endl;
    }
}

Graph::~Graph() {}

int Graph::getV() const {
    return m_V;
}

int Graph::getE() const {
    return m_E;
}

vector<int> Graph::getAdj(int v) const {
    return m_adjs.at(v);
}

void Graph::addEdge(int v, int w) {
    m_adjs.at(v).push_back(w);
    m_adjs.at(w).push_back(v);
    m_E++;
}

void Graph::split(const string& line, char c, vector<string>& splitted) {
    if (!splitted.empty()) splitted.clear();
    size_t i = 0;
    size_t j = line.find(c);
    while (j != string::npos) {
        splitted.push_back(line.substr(i, j - i));
        i = ++j;
        j = line.find(c, i);
    }
    if (j == string::npos) 
        splitted.push_back(line.substr(i));
}