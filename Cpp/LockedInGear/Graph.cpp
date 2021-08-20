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
            } else if (splitted.size() == 3) {
                m_vertices.push_back(make_pair(make_pair(stoi(splitted.at(0)), stoi(splitted.at(1))), stoi(splitted.at(2))));
            }
        }
        myfile.close();

        for (int i = 0; i < m_V - 1; i++) {
            auto p1 = m_vertices.at(i).first;
            int r1 = m_vertices.at(i).second;
            for (int j = i + 1; j < m_V; j++) {
                auto p2 = m_vertices.at(j).first;
                int r2 = m_vertices.at(j).second;
                float d1 = getDistBetween(p1, p2);
                float d2 = r1 + r2;
                if (isEqual(d1, d2)) addEdge(i, j);
            }
        }
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

float Graph::getDistBetween(const pair<int, int>& p1, const pair<int, int>& p2) const {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool Graph::isEqual(float d1, float d2, float epsilon) const {
    return (d1 - d2) <= epsilon;
}

string Graph::toString() const {
    string s = "";
    for (int v = 0; v < m_V; v++) {
        s += to_string(v) + ": ";
        for (int w : getAdj(v)) 
            s += to_string(w) + " ";
        s += "\n";
    }
    return s;
}