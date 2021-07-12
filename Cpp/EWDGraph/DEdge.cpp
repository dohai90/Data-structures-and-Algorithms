#include "DEdge.h"

DEdge::DEdge(int v, int w, double weight) : m_v(v), m_w(w), m_weight(weight) { }

DEdge::~DEdge() { 
    cout << "Delete: " << this->toString() << endl;
}

int DEdge::from() const {
    return m_v;
}

int DEdge::to() const {
    return m_w;
}

double DEdge::getWeight() const {
    return m_weight;
}

string DEdge::toString() const {
    return to_string(m_v) + "->" + to_string(m_w) + " " + to_string(m_weight);
}