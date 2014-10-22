#include "Vector3.h"

Vector3::Vector3(){
    this->x = 0;
    this->y = 0;
    this->w = 0;
}

Vector3::Vector3(double x, double y, double w)
{
    this->x = x;
    this->y = y;
    this->w = w;
}

double Vector3::getX() const{
    return this->x;
}

double Vector3::getY() const{
    return this->y;
}

double Vector3::getW() const{
    return this->w;
}

void Vector3::setX(double x){
    this->x = x;
}

void Vector3::setY(double y){
    this->y = y;
}

void Vector3::setW(double w){
    this->w = w;
}


Vector3 Vector3::operator +(const double val) const {
    Vector3 result;
    result.setX(this->x + val);
    result.setY(this->y + val);
    return result;
}

Vector3 Vector3::operator *(const double val) const {
    Vector3 result;
    result.setX(this->x * val);
    result.setY(this->y * val);
    return result;
}


Vector3 Vector3::operator *(const Vector3& vec) const{
    Vector3 result;
    result.setX(getX() * vec.getX());
    result.setY(getY() * vec.getY());
    return result;
}
Vector3 Vector3::operator +(const Vector3& vec) const {
    Vector3 result;
    result.setX(getX() + vec.getX());
    result.setY(getY() + vec.getY());
    return result;
}
