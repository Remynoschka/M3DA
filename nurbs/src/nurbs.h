#ifndef NURBS_H
#define NURBS_H

#include <vector>
#include <iostream>
#include <GL/gl.h>
#include "Vector2.h"

using namespace std;

class Nurbs
{
public:
    Nurbs();
    int degre;
    vector<double> nodalVector;
    vector<Vector2> controlPoints;

    void initializeNodalVector(int nbPoints, int degre);
    double evaluate(int p, int k, double t);
    Vector2 evalBSpline(double t);
    void drawN(int k, int p);
    void drawAllN(int p);
    void addControlPoint(Vector2 point);
    void drawBSpline();
    void drawAnimationBSpline(double time);
    void drawAnimationN(double time);
};

#endif // NURBS_H
