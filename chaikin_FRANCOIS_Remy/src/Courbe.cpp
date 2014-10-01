#include "Courbe.h"
#include "glsupport.h"

Courbe::Courbe()
{

}

void Courbe::addPoint(Vector2 point){
    this->points.push_back(point);
}

vector<Vector2> Courbe::getPoints(){
    return this->points;
}

void Courbe::draw(int w, int h){
    if (points.size() >= 2){

        glBegin(GL_LINE_STRIP);

        for (Vector2 point : points){
            glVertex2f(point.getX() / w, point.getY() / h);
        }

        glEnd();

    }
}
