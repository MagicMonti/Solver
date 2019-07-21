#include <iostream>
#include <cstdlib>
#include <chrono>

#include "Newton.h"
#include <fstream>
#include <math.h>

using namespace std;



double* Newton::function(double* x){
    //let's define f(x) R³->R³
    this->model[0] = exp(x[0]*x[1]); //f1(x,y,z) = e^(x*y)
    this->model[1] = sin(x[0]*x[2]); //f2(x,y,z) = sin(x*z)
    this->model[2] = x[0]*x[1]*x[2]; //f3(x,y,z) = x*y*z

    return this->model;
}

int main(int argc, char const* argv[]) {
    int size = 3;
    double initGuess[3] = {1,1,1};
    Newton* newton = new Newton(size);
    newton->init(initGuess);
    newton->solveModel();


    //ofstream myfile;
    //myfile.open ("benchmark.txt");
    /*LinearSolver* solver = new LinearSolver();
    //for (int i = 2 ; i < 200 ; i++){
        solver->setSize(4);
        solver->generateData();
        solver->printData();
        cout << endl ;
        auto start = chrono::high_resolution_clock::now();
        solver->solveLinearSystem();
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        //myfile << i << ";" << i*(i+1)  << ";" << (double)duration.count() << endl;
        //cout << i << endl;
        solver->printData();
        cout <<"Time in microseconds: " << duration.count() << endl;
        cout <<"Time in milliseconds: " << (double)duration.count() / 1000 << endl;
        cout <<"Time in seconds:" << (double)duration.count() / (1000 * 1000) << endl;
        cout << endl;
        solver->clearData();
    //}
    //myfile.close();
    delete [] solver;
    //solver->printData();*/

    //delete [] newton;

    return 0;
}
