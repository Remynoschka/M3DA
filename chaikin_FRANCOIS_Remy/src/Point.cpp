#include "Point.h"

Point::Point()
{

}

Point::Point(double x, double y, bool fixe)
{
    this->coordonnees.setX(x);
    this->coordonnees.setY(y);
    this->fixe = fixe;
}

Vector2 Point::getCoordonnees(){
    return this->coordonnees;
}

bool Point::isPointFixe(){
    return fixe;
}
