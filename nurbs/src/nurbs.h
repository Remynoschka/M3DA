#ifndef NURBS_H
#define NURBS_H

#include <vector>
#include <iostream>
#include <GL/gl.h>

using namespace std;

class Nurbs
{
public:
    Nurbs();
    int degre;
    vector<double> nodalVector;

    void initializeNodalVector(int nbPoints, int degre);
    double evaluate(int p, int k, int t);
    void drawN(int k, int p);
};

#endif // NURBS_H
