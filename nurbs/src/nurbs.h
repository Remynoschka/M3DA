#ifndef NURBS_H
#define NURBS_H

#include <vector>

using namespace std;

class Nurbs
{
public:
    Nurbs();
    int degre;
    vector<double> nodalVector;

    void initializeNodalVector(int nbPoints, int degre);
    double evaluate(int k, int t);
};

#endif // NURBS_H
