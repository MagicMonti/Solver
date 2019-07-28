#include "LinearSolver.h"
#include <iostream>

class Newton {
   public:
       ~Newton(void);
       Newton(int size);
       void setModel(void);
       void solveModel(void);
       void init(double*);
       double* function(double* x);
       void clearModel(void);
       double* model = nullptr;
       double* initGuess = nullptr;
       int size;
       double calculateDerivative(double* x, int index1, int index2);
       LinearSolver* linearSolver = nullptr;
       void createJacobian(double* x);
       std::string ArrayToString(double* array, int size);
       double* copyArray(double* array);

};
