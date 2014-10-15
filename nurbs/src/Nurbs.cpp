#include "nurbs.h"
#include <vector>
Nurbs::Nurbs()
{
}

void Nurbs::initializeNodalVector(int nbPoints, int degre){
    this->degre = degre;
    for (int i = 0 ; i < nbPoints + degre + 1 ; i++){
        this->nodalVector.push_back(i);
    }
}

double Nurbs::evaluate(int k, int t){

}

