#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Vector2::getX(){
    return this->x;
}

int Vector2::getY(){
    return this->y;
}

void Vector2::setX(int x){
    this->x = x;
}

void Vector2::setY(int y){
    this->y = y;
}
