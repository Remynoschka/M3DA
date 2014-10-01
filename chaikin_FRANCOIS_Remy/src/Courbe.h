#ifndef COURBE_H
#define COURBE_H
#include <vector>
#include "Vector2.h"
#include "GLView.h"

using namespace std;

class Courbe
{
public:
    Courbe();
    void addPoint(Vector2 point);
    vector<Vector2> getPoints();
    void draw(int w, int h);
private:
    vector<Vector2> points;
};

#endif // COURBE_H
