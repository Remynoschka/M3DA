#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double w);
    double getX() const;
    double getY() const;
    double getW() const;
    void setX(double x);
    void setY(double y);
    void setW(double w);
    Vector3 operator +(const double val) const;
    Vector3 operator *(const double val) const;

    Vector3 operator +(const Vector3& vec) const;
    Vector3 operator *(const Vector3& vec) const;
private:
    double x;
    double y;
    double w;
};

#endif // VECTOR3_H
