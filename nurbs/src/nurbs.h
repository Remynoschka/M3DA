#ifndef NURBS_H
#define NURBS_H

#include <vector>
#include <iostream>
#include <GL/gl.h>
#include "Vector3.h"

using namespace std;

class Nurbs
{
public:
    Nurbs();
    int degre;
    vector<double> nodalVector;
    vector<Vector3> controlPoints;

    void initializeNodalVector(int nbPoints, int degre);
    void initializeNodalVectorNU(int nbPoints, int degre);
    double evaluate(int p, int k, double t);
    Vector3 evalBSpline(double t);
    void drawN(int k, int p);
    void drawAllN(int p);
    void addControlPoint(Vector3 point);
    void addControlPointNU(Vector3 point);
    void drawBSpline();
    void drawAnimationBSpline(double time);
    void drawAnimationN(double time);
};

#endif // NURBS_H
