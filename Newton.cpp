#include "Newton.h"
#include <math.h>
#include <iostream>
#include <sstream>
#define DEBUG false


template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 5)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

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
    delete this->linearSolver;
}

*/

void Newton::init(double* initGuess){
    this->initGuess = initGuess;
}

void Newton::solveModel(){
    this->createJacobian(this->initGuess);
    if (DEBUG){
        this->linearSolver->printData();
        std::cout << std::endl;
    }
    this->linearSolver->solveLinearSystem();
    if (DEBUG){
        this->linearSolver->printData();
        //new initGuess are the solutions form the previous EqS;
        std::cout << std::endl;
    }
    while (true){
        for(int i = 0 ; i < this->size; i++){
            //x_(n+1) = deltaX + x_n
            this->initGuess[i] = this->linearSolver->array[i][this->size] + this->initGuess[i];
            if (DEBUG){
                std::cout<< initGuess[i] << "," << std::endl;
            }
        }
        this->createJacobian(this->initGuess);

        if (DEBUG){
            this->linearSolver->printData();
            std::cout << std::endl;
        }
        this->linearSolver->solveLinearSystem();

        if (DEBUG){
            this->linearSolver->printData();
            std::cout << std::endl;
        }
        
        int trigger = 0;
        for(int i = 0 ; i < this->size; i++){
            if (std::abs(this->function(this->initGuess)[i]) < pow(10,-5)){
                trigger++;
            }
        }
        if (trigger == this->size){
            break;
        }
    }

    for(int i = 0 ; i < this->size; i++){
        std::cout.precision(20);
        std::cout <<"f"<< i << "(" << this->ArrayToString(this->initGuess, this->size) << ")=" << this->function(this->initGuess)[i]  <<"~ "<< round(function(this->initGuess)[i]) << std::endl;
    }
}

double Newton::calculateDerivative(double* x, int index1, int index2){
    double* point = new double[this->size];
    for (int i = 0 ; i < this->size; i++){
        point[i] = x[i];
    }
    point[index1] = point[index1] + pow(10,-10);

    double result = (this->function(point)[index2]-this->function(x)[index2])/pow(10,-10);
    delete [] point;
    return result;
}
void Newton::createJacobian(double* x){

    this->function(x);
    for(int i = 0; i < this->size ; i++){
        for (int j = 0; j <= this->size ; j++){
            if (j == this->size){
                linearSolver->array[i][j] = -this->function(x)[i];
            }else{
                linearSolver->array[i][j] = this->calculateDerivative(x,j,i);
            }
        }
    }
}

void Newton::clearModel(){

}


std::string Newton::ArrayToString(double* array, int size){
    std::string str = "";
    for (int i = 0 ; i < size ; i++){
        str = str + to_string_with_precision(array[i],10) +  "," ;
    }
    return str;
}
