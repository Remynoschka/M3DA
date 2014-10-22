#include "Vector2.h"

Vector2::Vector2(){
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Vector2::getX() const{
    return this->x;
}

double Vector2::getY() const{
    return this->y;
}

void Vector2::setX(double x){
    this->x = x;
}

void Vector2::setY(double y){
    this->y = y;
}


Vector2 Vector2::operator +(const double val) const {
    Vector2 result;
    result.setX(this->x + val);
    result.setY(this->y + val);
    return result;
}

Vector2 Vector2::operator *(const double val) const {
    Vector2 result;
    result.setX(this->x * val);
    result.setY(this->y * val);
    return result;
}


Vector2 Vector2::operator *(const Vector2& vec) const{
    Vector2 result;
    result.setX(getX() * vec.getX());
    result.setY(getY() * vec.getY());
    return result;
}
Vector2 Vector2::operator +(const Vector2& vec) const {
    Vector2 result;
    result.setX(getX() + vec.getX());
    result.setY(getY() + vec.getY());
    return result;
}
