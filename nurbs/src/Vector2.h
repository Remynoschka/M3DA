#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    Vector2(double x, double y);
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    Vector2 operator +(const double val) const;
    Vector2 operator *(const double val) const;

    Vector2 operator +(const Vector2& vec) const;
    Vector2 operator *(const Vector2& vec) const;
private:
    double x;
    double y;
};


#endif // VECTOR2_H
