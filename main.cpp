#include <iostream>
#include <cstdlib>
#include <chrono>

#include "Newton.h"
#include <fstream>
#include <math.h>

using namespace std;



double* Newton::function(double* x){
    //let's define f(x) R³->R³
    this->model[0] = log(x[0]*x[1]); //f1(x,y,z) = ln(x*y)
    this->model[1] = log(x[1]*x[2]); //f2(x,y,z) = ln(y*z)
    this->model[2] = log(x[2]*x[0]); //f3(x,y,z) = ln(z*x)

    return this->model;
}

int main(int argc, char const* argv[]) {
    auto start = chrono::high_resolution_clock::now();
    int size = 3;
    double initGuess[3] = {0.5,0.5,0.5};
    Newton* newton = new Newton(size);
    newton->init(initGuess);
    newton->solveModel();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Time in microseconds: " << duration.count() << endl;
    cout <<"Time in milliseconds: " << (double)duration.count() / 1000 << endl;
    cout <<"Time in seconds:" << (double)duration.count() / (1000 * 1000) << endl;


    return 0;
}
