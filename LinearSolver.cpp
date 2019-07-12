#include "LinearSolver.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#define DEBUG false

void LinearSolver::setSize(int size){
    this->size = size;
    this->array = new double* [size];

    for(int i = 0; i < size; i++){
        this->array[i] = new double[size+1];
    }
}
void LinearSolver::clearData(){
    for(int i = 0; i < this->size; i++) {
        delete [] array[i];
    }
    delete [] array;
}

LinearSolver::~LinearSolver() {
    this->clearData();
}

double LinearSolver::getRandomNumber(){
    return rand() % 100 + 0;
}
void LinearSolver::generateData(){
    for(int i = 0; i < this->size ; i++){
        for (int j = 0; j <= this->size ; j++){
            this->array[i][j] = this->getRandomNumber();
        }
    }
}
void LinearSolver::printData(){
    for(int i = 0; i < this->size ; i++){
        for (int j = 0; j <= this->size ; j++){
            if (j == this->size){
                std::cout << "\t|\t" << array[i][j];
            }else{
                std::cout << '\t' << array[i][j];
            }
        }
        std::cout << std::endl << std::endl;
    }
}
void LinearSolver::simplify(){
    for(int i = 0; i < this->size ; i++){
        int counter = 0;
        double firstInRow = array[i][counter];
        for (int j = 0; j <= this->size ; j++){
            if (array[i][counter] != 0){
                if (counter == j){
                    array[i][j] = 1; //also doesn't have to perform a calculation because a number devided by the same number is equal 1
                }else {
                    if (array[i][j] == 0){
                        array[i][j] = 0; //no calculation needed;s
                    }else{
                        array[i][j]  = array[i][j] /  firstInRow;
                    }
                }
            }
            else{
                counter++;
                firstInRow = array[i][counter];
            }
        }
    }
}
void LinearSolver::echelon_form(){
    int rowNumberWithFirstOne = 0;
    int columnNumberWithFirstOne = 0;
    for (int x = 0 ; x < this->size+1; x++){
        for (int j = columnNumberWithFirstOne ; j <this->size-1 ; j++){
            for (int i = rowNumberWithFirstOne ; i <this->size-1; i++){
                if (array[i][j] == 1){
                    rowNumberWithFirstOne = i;
                    columnNumberWithFirstOne = j;
                    goto endloop;
                }
            }
        }
        endloop:
        for (int j = columnNumberWithFirstOne; j <this->size ; j++){
            for (int i = rowNumberWithFirstOne+1 ; i <this->size; i++){
                if (array[i][j] == 1 ){
                    if (DEBUG){
                        this->printData();
                        std::cout << std::endl;
                    }
                    for (int k = columnNumberWithFirstOne ; k <= this->size ; k++){
                        array[i][k] = array[i][k] - array[rowNumberWithFirstOne][k];
                    }
                }
            }
            this->simplify();
            if (DEBUG){
                std::cout << "simplify" << std::endl;
            }
            if (rowNumberWithFirstOne+2 == this->size && columnNumberWithFirstOne+2 == this->size){
                goto endloop2;
            }
            rowNumberWithFirstOne++;
            columnNumberWithFirstOne++;
        }
    }
    endloop2:
    ;
}

void LinearSolver::solve(){

    double factor = 0;
    //std::cout << "test" << std::endl;
    for (int x = 0 ; x < this->size-1; x++){
        for (int i = 0; i < this->size-1 ; i++){
            if (/*array[x][i+1] != 1 &&*/ array[x][i+1] != 0){
                if (x == i+1){
                    i++; //factor lands on a diagonal element;
                }
                factor = array[x][i+1];
                if (DEBUG){
                        std::cout << "factor:" << factor << std::endl;
                        std::cout << "x[row]: " << x << std::endl;
                        std::cout << "i[col]: " << i+1 << std::endl << std::endl;
                        this->printData();
                        std::cout << std::endl;
                }
                if (factor != 1){
                    for (int k = i+1 ; k <= this->size ; k++){
                        array[i+1][k] = array[i+1][k] * factor;
                    }
                    if (DEBUG){
                        this->printData();
                        std::cout << std::endl;
                    }
                }
                for (int k = x+1 ; k <= this->size ; k++){
                    array[x][k] = array[x][k] - array[i+1][k];
                }
            }
            if (DEBUG){
                this->printData();
                std::cout << std::endl;
            }
            this->simplify();
            if (DEBUG){
                this->printData();
                std::cout << std::endl;
            }
        }
    }
}

void LinearSolver::solveLinearSystem(){
    this->simplify();
    this->echelon_form();

    if (DEBUG){
        this->printData();
        std::cout << "echelon_form-------" << std::endl;
    }
    this->solve();
}
