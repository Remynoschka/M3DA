#include "Point.h"

Point::Point()
{

}

/**
 * @brief Point::Point
 * @param x : coordonnee x du point
 * @param y : coordonnee y du point
 * @param fixe : true si c'est un point fixe
 */
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
