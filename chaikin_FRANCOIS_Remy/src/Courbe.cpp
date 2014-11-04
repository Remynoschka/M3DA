#include "Courbe.h"
#include "glsupport.h"
#include "Point.h"

Courbe::Courbe()
{

}

/**
 * @brief Courbe::addPoint : ajoute un point au polygone
 * @param point
 */
void Courbe::addPoint(Point point){
    this->points.push_back(point);
    //    cout << point.getX() << "/" << point.getY() << endl;
}

/**
 * @brief Courbe::getNbSubdivisons
 * @return le nombre de subdivisions effectuees
 */
int Courbe::getNbSubdivisons(){
    return nbSubdivisions;
}

/**
 * @brief Courbe::isClosed
 * @return true si le polygone est ferme
 */
bool Courbe::isClosed(){
    return closed;
}

/**
 * @brief Courbe::getPoints
 * @return les points ajoutes
 */
vector<Point> Courbe::getPoints(){
    return this->points;
}

/**
 * Exercice 2 : Q1
 * @brief Courbe::subdivizeChaikin : subdivise la courbe avec chaikin
 */
void Courbe::subdivizeChaikin(){
    if (nbSubdivisions == 0){
        for (int i = 0 ; i < points.size()-1 ; i++){
            if (dynamic_cast<Point&>(points.at(i)).isPointFixe()){               
                subdivizedPoints.push_back(points.at(i));
                Vector2 q2 = calculateChaikin(dynamic_cast<Point&>(points.at(i)).getCoordonnees(), dynamic_cast<Point&>(points.at(i+1)).getCoordonnees()).at(1);
                subdivizedPoints.push_back(Point(q2.getX(), q2.getY(), false));
            } else {
                for(Vector2 point : calculateChaikin(dynamic_cast<Point&>(points.at(i)).getCoordonnees(), dynamic_cast<Point&>(points.at(i+1)).getCoordonnees())){
                    subdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                }
            }
        }
         if (dynamic_cast<Point&>(points.at(points.size()-1)).isPointFixe()){
             subdivizedPoints.push_back(points.at(points.size()-1));
         }
    } else {
        vector<Point> newSubdivizedPoints;
        for (int i = 0 ; i < subdivizedPoints.size()-1 ; i++){
            if (dynamic_cast<Point&>(subdivizedPoints.at(i)).isPointFixe()){
                newSubdivizedPoints.push_back(subdivizedPoints.at(i));
                Vector2 q2 = calculateChaikin(dynamic_cast<Point&>(subdivizedPoints.at(i)).getCoordonnees(), dynamic_cast<Point&>(subdivizedPoints.at(i+1)).getCoordonnees()).at(1);
                newSubdivizedPoints.push_back(Point(q2.getX(), q2.getY(), false));
            } else {
                for(Vector2 point : calculateChaikin(dynamic_cast<Point&>(subdivizedPoints.at(i)).getCoordonnees(), dynamic_cast<Point&>(subdivizedPoints.at(i+1)).getCoordonnees())){
                    newSubdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                }
            }
        }
        if (dynamic_cast<Point&>(subdivizedPoints.at(subdivizedPoints.size()-1)).isPointFixe()){
            newSubdivizedPoints.push_back(subdivizedPoints.at(subdivizedPoints.size()-1));
        }
        subdivizedPoints = newSubdivizedPoints;
    }
    nbSubdivisions++;
}

/**
 * Exercice 3 : Q1
 * @brief Courbe::subdivize4Point : subdivise ka courbe avec 4-point
 */
void Courbe::subdivize4Point(){
    if (closed){
        cout << "Subdivise 4pts" << endl;
        if (nbSubdivisions == 0){
            for (int i = 0 ; i < points.size()-1 ; i++){
                // cas du premier point
                if (i == 0){
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(points.at(points.size()-2)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(0)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(2)).getCoordonnees())){
                        subdivizedPoints.push_back(Point(point.getX(),point.getY(), false));
                    }
                }
                //cas du dernier
                else if (i == points.size()-2){
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(points.at(i-1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(i)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(i+1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(1)).getCoordonnees())){
                        subdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                    }
                }
                // autres
                else {
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(points.at(i-1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(i)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(i+1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(points.at(i+2)).getCoordonnees())){
                        subdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                    }
                }
            }
        } else {
            vector<Point> newSubdivizedPoints;
            for (int i = 0 ; i < subdivizedPoints.size()-1 ; i++){
                // cas du premier
                if (i == 0){
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(subdivizedPoints.at(subdivizedPoints.size()-2)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i+1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i+2)).getCoordonnees())){
                        newSubdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                    }
                }
                // cas du dernier
                else if (i == subdivizedPoints.size()-2){
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(subdivizedPoints.at(i-1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i+1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(1)).getCoordonnees())){
                        newSubdivizedPoints.push_back(Point(point.getX(), point.getY(),false));
                    }
                }
                // autre
                else {
                    for(Vector2 point : calculate4Point(dynamic_cast<Point&>(subdivizedPoints.at(i-1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i+1)).getCoordonnees(),
                                                        dynamic_cast<Point&>(subdivizedPoints.at(i+2)).getCoordonnees())){
                        newSubdivizedPoints.push_back(Point(point.getX(), point.getY(), false));
                    }
                }
            }
            subdivizedPoints = newSubdivizedPoints;
        }
        subdivizedPoints.push_back(subdivizedPoints.at(0));
        nbSubdivisions++;
    }
}

/**
     * Exercice 2 : Q1
     * @brief Courbe::calculateChaikin : calcule les points pour la subdivision
     * @param p0
     * @param p1
     * @return un vecteur de 2 points : Q2i et Q2i+1
     */
vector<Vector2> Courbe::calculateChaikin(Vector2 p0, Vector2 p1){
    vector<Vector2> pointsChaikin;
    Vector2 q0 = p0 * (1.0/4.0) + p1 * (3.0/4.0);
    Vector2 q1 = p1 * (1.0/4.0) + p0 * (3.0/4.0);
    pointsChaikin.push_back(q1);
    pointsChaikin.push_back(q0);
    return pointsChaikin;
}

/**
     * Exercice 3 : Q1
     * @brief Courbe::calculate4Point: calcule les points pour la subdivision
     * @param p_1 : pi-1
     * @param p0 : pi
     * @param p1 : pi+1
     * @param p2 : pi+2
     * @return un vecteur de 2 points : Q2i et Q2i+1
     */
vector<Vector2> Courbe::calculate4Point(Vector2 p_1, Vector2 p0, Vector2 p1, Vector2 p2){
    vector<Vector2> pointsChaikin;
    Vector2 q0 = p0;
    Vector2 q1 = (p2 + p_1) * (-1.0/16.0) + (p1 + p0 )* (9.0/16.0);
    pointsChaikin.push_back(q0);
    pointsChaikin.push_back(q1);
    return pointsChaikin;
}

/**
     * @brief Courbe::getSubdivizedPoints
     * @return les points de la subdivision
     */
vector<Point> Courbe::getSubdivizedPoints(){
    return this->subdivizedPoints;
}

/**
     * Execice 1
     * @brief Courbe::draw : dessine les points places et le polygone
     * @param w
     * @param h
     */
void Courbe::draw(int w, int h){
    glPushMatrix();
    glColor3f(1,0,0);
    glLineWidth(3);
    glPointSize(5);
    if (points.size() >= 2){

        glBegin(GL_LINE_STRIP);

        for (Point point : points){
            glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
        }

        glEnd();

    }
    glBegin(GL_POINTS);

    for (Point point : points){
        if (point.isPointFixe()){
            glColor3f(0,0,0);
        }else{
            glColor3f(1,0,0);
        }
        glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
    }

    glEnd();

    glPopMatrix();
}

/**
     * Exercice 2 : Q1
     * @brief Courbe::drawChaikin : dessine la courbe subdivisee
     */
void Courbe::drawChaikin(int w, int h){
    glPushMatrix();
    glColor3f(0,0,1);
    glLineWidth(2);
    glPointSize(4);
    if (points.size() >= 2){

        glBegin(GL_LINE_STRIP);

        for (Point point : subdivizedPoints){

            glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
        }

        glEnd();
    }
    glBegin(GL_POINTS);

    for (Point point : subdivizedPoints){
        glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
    }

    glEnd();


    glPopMatrix();
}

/**
     * Exercice 3 : Q1
     * @brief Courbe::drawChaikin : dessine la courbe subdivisee
     */
void Courbe::draw4Point(int w, int h){
    glPushMatrix();
    glColor3f(0,0,1);
    glLineWidth(2);
    glPointSize(4);
    if (points.size() >= 2){

        glBegin(GL_LINE_STRIP);

        for (Point point : subdivizedPoints){
            glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
        }

        glEnd();
    }
    glBegin(GL_POINTS);

    for (Point point : subdivizedPoints){
        glVertex2f(point.getCoordonnees().getX() / w, point.getCoordonnees().getY() / h);
    }

    glEnd();


    glPopMatrix();
}

/**
     * Exercice 3 : Q1
     * @brief Courbe::close : ferme le polygone
     */
void Courbe::close(){
    points.push_back(points.at(0));
    closed = true;
}


/**
     * Exercice 3 : Q1
     * @brief Courbe::open : ouvre le polygone (retire le dernier)
     */
void Courbe::open(){
    points.pop_back();
    closed = false;
}

