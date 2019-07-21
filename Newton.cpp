#include "Newton.h"
#include <iostream>
#include <math.h>

Newton::Newton(int size){
    this->size = size;
    this->model = new double[size];
    this->linearSolver = new LinearSolver();
    this->linearSolver->setSize(this->size);
}
/*

Newton::~Newton() {
    delete [] this->model;
    this->linearSolver->clearData();
    delete [] this->linearSolver;
}

*/

void Newton::init(double* initGuess){
    this->initGuess = initGuess;
}

void Newton::solveModel(){
    this->createJacobian(this->initGuess);
    this->linearSolver->printData();
    std::cout << std::endl;
    this->linearSolver->solveLinearSystem();
    this->linearSolver->printData();
    //new initGuess are the solutions form the previous EqS;
    std::cout << std::endl;
    for (int j = 0 ; j < 5 ; j++){
    for(int i = 0 ; i < this->size; i++){
        //x_(n+1) = deltaX + x_n
        this->initGuess[i] = this->linearSolver->array[i][this->size] + this->initGuess[i];
        std::cout << initGuess[i] << ", ";
    }
    std::cout << std::endl;
    this->createJacobian(this->initGuess);
    this->linearSolver->printData();
    std::cout << std::endl;
    this->linearSolver->solveLinearSystem();
    this->linearSolver->printData();
    std::cout << std::endl;
    }
}
double Newton::calculateDerivative(double* x, int index1, int index2){
    double* point1 = new double[this->size];
    double* point2 = new double[this->size];
    for (int i = 0; i < this->size ; i++){
        if (i == index1){
            point1[i] =  x[i] + pow(10,-10);
        }
        else{
            point1[i] = x[i];
        }
        point2[i] = x[i];
    }
    double result = (this->function(point1)[index2]-this->function(point2)[index2])/pow(10,-10);
    delete [] point1;
    delete [] point2;
    return result;
}
void Newton::createJacobian(double* x){

    this->function(x);
    for(int i = 0; i < this->size ; i++){
        for (int j = 0; j <= this->size ; j++){
            if (j == this->size){
                linearSolver->array[i][j] = -this->function(x)[i];
            }else{
                linearSolver->array[i][j] = this->calculateDerivative(x,i,j);
            }
        }
    }
}

void Newton::clearModel(){

}
