#include <iostream>
#include <cstdlib>
#include <chrono>
#include "LinearSolver.h"

using namespace std;

int main(int argc, char const* argv[]) {
    const int size = 1000;
    LinearSolver* solver = new LinearSolver(&size);
    solver->generateData();
    solver->printData();
    cout << endl ;
    auto start = chrono::high_resolution_clock::now();
    solver->solveLinearSystem();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    solver->printData();

    cout <<"Time in microseconds: " << duration.count() << endl;
    cout <<"Time in milliseconds: " << (double)duration.count() / 1000 << endl;
    cout <<"Time in seconds:" << (double)duration.count() / (1000 * 1000) << endl;
    cout << endl;
    cout << "end";

    delete [] solver;
    return 0;
}
