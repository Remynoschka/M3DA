#include "nurbs.h"
#include <vector>
#include <cmath>
#include "Vector3.h"
Nurbs::Nurbs()
{
}

void Nurbs::initializeNodalVector(int nbPoints, int degre){
    this->degre = degre;
    nodalVector.clear();
    for (int i = 0 ; i < nbPoints + degre + 1 ; i++){
        this->nodalVector.push_back(i+1);
    }
}

/**
 * PART1/Q11
 * @brief Nurbs::initializeNodalVectorNU
 * @param nbPoints
 * @param degre
 */
void Nurbs::initializeNodalVectorNU(int nbPoints, int degre){
    this->degre = degre;
    nodalVector.clear();
    for (int i = 0 ; i < nbPoints + degre + 1 ; i++){
        int cpt = 0;
//        cout << "-----" << endl;
        while (nodalVector.size() < nbPoints+degre+1 && cpt < i*i){
//            cout << "i = " << i <<endl;
            this->nodalVector.push_back(i);
            cpt++;
        }
    }
//    cout << nodalVector.size() << endl;
}


/**
 * Part1 / Q2
 * @brief Nurbs::evaluate
 * @param p : degre
 * @param k : indice
 * @param t : valeur
 * @return
 */
double Nurbs::evaluate(int p, int k, double t){
    //   cout << "evaluate " << p <<"/"<< k << "/"<<t << "/" << nodalVector.at(k) <<endl;
    if (p == 0){
        if (t >= nodalVector.at(k) && t < nodalVector.at(k+1)){
            return 1;
        } else {
            return 0;
        }
    } else {
        //        cout << "calcul evaluate" << endl;
        double den1 = nodalVector.at(k+p) - nodalVector.at(k) ;
        double den2 = nodalVector.at(k+p+1) - nodalVector.at(k+1);
        double part1 = 0;
        double part2 = 0;

        if (den1 != 0)
            part1 = (t-nodalVector.at(k))/ den1 ;
        if (den2!=0)
            part2 = (nodalVector.at(p+k+1) - t) / den2 ;
        return  part1 * evaluate(p-1,k,t) + part2 * evaluate(p-1,k+1,t);

    }
}

/**
 *PART1/Q3
 * @brief Nurbs::drawN
 * @param k : indice
 * @param p : degre
 */
void Nurbs::drawN(int k, int p){
    double tmin = nodalVector.at(0);
    //    cout << "draw/" <<tmin<<"/"<<tmax<<endl;
    glPushMatrix();
    glOrtho(0,1,-1,1,-1,1);
    // dessiner la courbe
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (double t = tmin+k; t < tmin+k+p+1 ; t += 0.1){
        double y = evaluate(p,k,t);
        double x = (t) / nodalVector.size() / 2;

        //            cout << "coord: " << x << "/" <<y << endl;

        glVertex2d(x,y);


    }
    glEnd();


    // dessiner les points
    glPointSize(10);
    glColor3f(0,1,0);
    glBegin(GL_POINTS);

    for (double i = 0; i < nodalVector.size(); i++) {
        glVertex2f((i+1)/ nodalVector.size() / 2,0);
//        cout << nodalVector.at(i)/ nodalVector.size() << endl;
    }
    glEnd();
    glFlush();
    glPopMatrix();

}

/**
 * PART1/Q4
 * @brief Nurbs::drawAllN : dessine toutes les representation des Nkp pour un vecteur nodal et un degre
 * @param p : degre
 */
void Nurbs::drawAllN(int p){
    for (int k = 0 ; k < nodalVector.size()-p-1; k++){
        drawN(k,p);
    }
}

/**
 * PART1/Q7
 * @brief addControlPoint :ajoute un point de controle
 * @param point : point a ajoute
 */
void Nurbs::addControlPoint(Vector3 point){
    this->controlPoints.push_back(point);
    initializeNodalVector(controlPoints.size(), degre);
}

/**
 * PART1/Q11
 * @brief addControlPoint :ajoute un point de controle
 * @param point : point a ajoute
 */
void Nurbs::addControlPointNU(Vector3 point){
    this->controlPoints.push_back(point);
    initializeNodalVectorNU(controlPoints.size(), degre);
}


/**
 *PART1/Q7Q9
 * @brief drawBSpline : dessine la BSpline avec son polygone de controle
 */
void Nurbs::drawBSpline(){
    glPushMatrix();
    glOrtho(-1,1,-1,1,-1,1);

    //dessin des points de controle
    glPointSize(3);
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    for (int i = 0 ; i < controlPoints.size() ; i++){
        glVertex2f(controlPoints.at(i).getX(), controlPoints.at(i).getY());
    }
    glEnd();

    //dessin du polygone de controle
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0 ; i < controlPoints.size() ; i++){
        glVertex2d(controlPoints.at(i).getX(), controlPoints.at(i).getY());
    }
    glEnd();

    //dessine la b-spline
    glColor3f(0,0,1);
    glBegin(GL_LINE_STRIP);
    int tmin = nodalVector.at(degre);
    int tmax = nodalVector.at(controlPoints.size());
    // cout << tmin << "/" << tmax << endl;
    for (double t = tmin; t <= tmax; t+=0.1) {
        Vector3 point = evalBSpline(t);
        glVertex2d(point.getX(), point.getY());
    }
    glEnd();


    glFlush();
    glPopMatrix();

}

/**
 *PART1/Q8
 * @brief Nurbs::evalBSpline
 * @param t : valeur a calculee
 * @return la somme du calcul de la courbe
 */
Vector3 Nurbs::evalBSpline(double t){
    Vector3 sum;
    for (int k = 0 ; k < controlPoints.size() ; k++){
        sum = sum + (controlPoints.at(k) * evaluate(degre, k, t));
    }
    return sum;
}

/**
 * PART1/Q10
 * @brief Nurbs::drawAnimation : dessine le point de l'animation sur la B-Spline
 * @param time : le temps correspondant de l'animation
 */
void Nurbs::drawAnimationBSpline(double time){
    double tmin = nodalVector.at(degre);
    glPushMatrix();
    glBegin(GL_POINTS);
    glOrtho(-1,1,-1,1,-1,1);
    glPointSize(5);
    glColor3f(1,0,1);
    // anim b-spline
    Vector3 point = evalBSpline(tmin + time);
    glVertex2d(point.getX(), point.getY());

    glEnd();
    glFlush();
    glPopMatrix();
}

/**
 * Part1/Q10
 * @brief Nurbs::drawAnimationN : dessine le point de l'animation sur la fonction
 * @param time : le temps correspondant
 */
void Nurbs::drawAnimationN(double time){
    glPushMatrix();
    glOrtho(0,1,-1,1,-1,1);
    glBegin(GL_POINTS);
    glPointSize(5);
    glColor3f(1,0,1);
    double tmin = nodalVector.at(0);
    for (int k = 0 ; k < nodalVector.size()-degre-1; k++){
            double y = evaluate(degre,k,tmin+k+time);
            double x = ((tmin+k+time) / nodalVector.size() / 2);
            glVertex2d(x,y);

    }
    glEnd();
    glFlush();
    glPopMatrix();
}

