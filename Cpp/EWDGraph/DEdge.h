#ifndef DEDGE_H_
#define DEDGE_H_

#include <string>
#include <iostream>

using namespace std;

class DEdge {
public:
    DEdge(int v, int w, double weight);
    ~DEdge();
    int from() const;
    int to() const;
    double getWeight() const;
    string toString() const;

private:
    int m_v;
    int m_w;
    double m_weight;
};

#endif /* End DEDGE_H_ */