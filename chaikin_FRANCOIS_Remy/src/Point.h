#ifndef POINT_H
#define POINT_H

#include "Vector2.h"

class Point
{
public:
    Point();
    Point(double x, double y, bool fixe);
    Vector2 getCoordonnees();
    bool isPointFixe();
private:
    Vector2 coordonnees;
    bool fixe;
};

#endif // POINT_H
