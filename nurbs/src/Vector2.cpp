#include "Vector2.h"

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Vector2::getX(){
    return this->x;
}

double Vector2::getY(){
    return this->y;
}

void Vector2::setX(double x){
    this->x = x;
}

void Vector2::setY(double y){
    this->y = y;
}


Vector2 Vector2::operator +(const double val) const {
    Vector2 result = Vector2(0,0);
    result.setX(this->x + val);
    result.setY(this->y + val);
    return result;
}

Vector2 Vector2::operator *(const double val) const {
    Vector2 result = Vector2(0,0);
    result.setX(this->x * val);
    result.setY(this->y * val);
    return result;
}


Vector2 Vector2::operator +(const Vector2& vec) const {
    Vector2 result = Vector2(0,0);
    result.setX(this->x + vec.getX());
    result.setY(this->y + vec.getY());
    return result;
}

Vector2 Vector2::operator *(const Vector2& vec) const {
    Vector2 result = Vector2(0,0);
    result.setX(this->x * vec.getX());
    result.setY(this->y * vec.getY());
    return result;
}
