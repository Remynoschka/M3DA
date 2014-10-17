#include "nurbs.h"
#include <vector>
#include <cmath>
Nurbs::Nurbs()
{
}

void Nurbs::initializeNodalVector(int nbPoints, int degre){
    this->degre = degre;
    for (int i = 0 ; i < nbPoints + degre + 1 ; i++){
        this->nodalVector.push_back(i+1);
    }
}

double Nurbs::evaluate(int p, int k, int t){
   cout << "evaluate " << p <<"/"<< k << "/"<<t << "/" << nodalVector.at(k) <<endl;
    if (p == 0){
        if (t >= nodalVector.at(k) && t < nodalVector.at(k+1)){
            return 1;
        } else {
            return 0;
        }
    } else {
        cout << "calcul evaluate" << endl;
        double den1 = nodalVector.at(k+p) - nodalVector.at(k) ;
        double den2 = nodalVector.at(k+p+1) - nodalVector.at(k+1);
        double part1 = 0;
        double part2 = 0;

        if (den1 != 0)
            part1 = (t-nodalVector.at(k))/ den1 ;
        if (den2!=0)
            part2 = (nodalVector.at(p+k-1) - t) / den2 ;
        return  part1 * evaluate(p-1,k,t) + part2 * evaluate(p-1,k+1,t);

    }
}

void Nurbs::drawN(int k, int p){
    double tmin = nodalVector.at(0);
    double tmax = nodalVector.at(nodalVector.size()-1);
    cout << "draw/" <<tmin<<"/"<<tmax<<endl;
    glPushMatrix();
    glOrtho(0,1,-1,1,-1,1);
    // dessiner la courbe
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (double t = tmin; t <= tmax ; t+= 0.1){

        double y = abs(evaluate(p,k,t));
        double x = t / nodalVector.size() / 2;

        cout << "coord: " << x << "/" <<y << endl;

        glVertex2d(x,y);

    }
    glEnd();


//        for(int i = 0; i < nodalVector.size()-1; i++) {
//            double y2 = 0;
//            double y1 = 0;
//            cout << i <<"/"<< endl;
//            glBegin(GL_LINES);
//            glColor3f(1.0f, 0.0f, 0.0f);
//            double x1 = nodalVector.at(i) / nodalVector.size() / 2;
//            double x2 = nodalVector.at(i+1) / nodalVector.size() / 2;
//            cout << "start evaluate" << endl;
//            y1 = evaluate(p, k, nodalVector.at(i));
//            // pour pas faire le dernier
//            if (i != nodalVector.size()-2)
//                y2 = evaluate(p, k, nodalVector.at(i+1));
//            cout << "end evaluate" << endl;
//            glVertex2d(x1, y1);
//            glVertex2d(x2, y2);
//            cout << "1: " << x1 <<"/"<<y1<<endl;
//            cout << "2: " << x2 <<"/"<<y2<<endl;
//            glEnd();
//        }

    // dessiner les points
    glPointSize(10);
    glColor3f(0,1,0);
    glBegin(GL_POINTS);

    for (int i = 0; i < nodalVector.size(); i++) {
        glVertex2f(nodalVector.at(i)/ nodalVector.size() / 2,0);
        //cout << nodalVector.at(i)/ nodalVector.size() << endl;
    }
    glEnd();
    glFlush();
    glPopMatrix();

}


