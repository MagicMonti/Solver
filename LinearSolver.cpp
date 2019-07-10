#include "LinearSolver.h"
#include <cstdlib>
#include <iostream>

LinearSolver::LinearSolver(const int* size){
    this->size = size;
    this->array = new double* [*size];

    for(int i = 0; i < *size; i++){
        this->array[i] = new double[*size];
    }
}
LinearSolver::~LinearSolver() {
    for(int i = 0; i < *this->size; i++) {
        delete [] array[i];
    }
    delete [] array;
}

double LinearSolver::getRandomNumber(){
    return rand() % 2 + 0;
}
void LinearSolver::generateData(){
    for(int i = 0; i < *this->size ; i++){
        for (int j = 0; j < *this->size ; j++){
            this->array[i][j] = this->getRandomNumber();
        }
    }
}
void LinearSolver::printData(){
    for(int i = 0; i < *this->size ; i++){
        for (int j = 0; j < *this->size ; j++){
            std::cout <<  array[i][j] << "\t" ;
        }
        std::cout << std::endl << std::endl;
    }
}
void LinearSolver::simplify(){
    for(int i = 0; i < *this->size ; i++){
        int counter = 0;
        double firstInRow = array[i][counter];
        for (int j = 0; j < *this->size ; j++){
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
void LinearSolver::eliminate(){
    int rowNumberWithFirstOne = 0;
    int columnNumberWithFirstOne = 0;
    for (int x = 0 ; x < *this->size+1; x++){
        for (int j = columnNumberWithFirstOne ; j <*this->size-1 ; j++){
            for (int i = rowNumberWithFirstOne ; i <*this->size-1; i++){
                if (array[i][j] == 1){
                    rowNumberWithFirstOne = i;
                    columnNumberWithFirstOne = j;
                    goto endloop;
                }
            }
        }
        endloop:
        for (int j = columnNumberWithFirstOne; j <*this->size ; j++){
            for (int i = rowNumberWithFirstOne+1 ; i <*this->size; i++){
                if (array[i][j] == 1 ){
                    for (int k = columnNumberWithFirstOne ; k < *this->size ; k++){
                        array[i][k] = array[i][k] - array[rowNumberWithFirstOne][k];
                    }
                }
            }
            this->simplify();
            if (rowNumberWithFirstOne+2 == *this->size && columnNumberWithFirstOne+2 == *this->size){
                goto endloop2;
            }
            rowNumberWithFirstOne++;
            columnNumberWithFirstOne++;
        }
    }
    endloop2:
    ;
}

void LinearSolver::solveLinearSystem(){
    this->simplify();
    this->eliminate();
}
