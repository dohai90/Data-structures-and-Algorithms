#include <fstream>
#include "EWDGraph.h"

EWDGraph::EWDGraph(const string& filename) : m_V(0), m_E(0) {
    string line = "";
    ifstream myfile(filename);
    vector<string> splitted_str;
    if(myfile.is_open()) {
        while(getline(myfile, line)) {
            split(line, ' ', splitted_str);
            if(m_V == 0) {
                m_V = stoi(splitted_str.front());
                m_adjs.resize(m_V);
            }
            else if(splitted_str.size() == 3) {
                int v = stoi(splitted_str.at(0));
                int w = stoi(splitted_str.at(1));
                double weight = stod(splitted_str.at(2));
                DEdge* e = new DEdge(v, w, weight);
                addEdge(e);
            }
        }
        myfile.close();
    } else {
        cerr << "Open file error!" << endl;
    }
}

EWDGraph::~EWDGraph() {
    for (int v = 0; v < m_V; v++) {
        for (DEdge* e : m_adjs.at(v)) {
            delete e;
            e = nullptr;
        }
    }
}

void EWDGraph::split(const string& line ,char c, vector<string>& splitted_str) {
    if(!splitted_str.empty()) splitted_str.clear();
    size_t i = 0;
    size_t j = line.find(c);

    while(j != string::npos) {
        splitted_str.push_back(line.substr(i, j - i));
        i = ++j;
        j = line.find(c, i);
    }

    if(j == string::npos) 
        splitted_str.push_back(line.substr(i));
}

int EWDGraph::getV() const {
    return m_V;
}

int EWDGraph::getE() const {
    return m_E;
}

vector<DEdge*> EWDGraph::getAdj(int v) const {
    return m_adjs.at(v);
}

void EWDGraph::addEdge(DEdge* e) {
    int v = e->from();
    m_adjs.at(v).push_back(e);
    m_E++;
}