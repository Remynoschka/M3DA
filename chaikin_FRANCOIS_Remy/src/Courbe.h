#ifndef COURBE_H
#define COURBE_H

#include <vector>
#include "Vector2.h"
#include "Point.h"

using namespace std;

class Courbe
{
public:
    Courbe();

    void addPoint(Point point);

    vector<Point> getPoints();
    vector<Point> getSubdivizedPoints();

    int getNbSubdivisons();
    bool isClosed();

    void subdivizeChaikin();
    void subdivize4Point();

    vector<Vector2>calculateChaikin(Vector2 p0, Vector2 p1);
    vector<Vector2>calculate4Point(Vector2 p_1, Vector2 p0, Vector2 p1, Vector2 p2);

    void draw(int w, int h);
    void drawChaikin(int w, int h);
    void draw4Point(int w, int h);

    void close();
    void open();
private:
    vector<Point> points;
    vector<Point> subdivizedPoints;
    int nbSubdivisions;
    bool closed;
};

#endif // COURBE_H
