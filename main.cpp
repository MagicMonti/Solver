#include <iostream>
#include <cstdlib>
#include <chrono>
#include "LinearSolver.h"
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {
    ofstream myfile;
    myfile.open ("benchmark.txt");
    LinearSolver* solver = new LinearSolver();
    for (int i = 2 ; i < 200 ; i++){
        solver->setSize(i);
        solver->generateData();
        //solver->printData();
        cout << endl ;
        auto start = chrono::high_resolution_clock::now();
        solver->solveLinearSystem();
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        myfile << i << ";" << i*(i+1)  << ";" << (double)duration.count() << endl;
        cout << i << endl;
        cout <<"Time in microseconds: " << duration.count() << endl;
        cout <<"Time in milliseconds: " << (double)duration.count() / 1000 << endl;
        cout <<"Time in seconds:" << (double)duration.count() / (1000 * 1000) << endl;
        cout << endl;
        solver->clearData();
    }
    myfile.close();
    delete [] solver;
    //solver->printData();

    return 0;
}
