#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    Vector2(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int x;
    int y;
};


#endif // VECTOR2_H
