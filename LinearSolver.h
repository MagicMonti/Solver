#ifndef LinearSolver_H
#define LinearSolver_H

class LinearSolver {
   public:
      LinearSolver(const int* size);
      ~LinearSolver(void);//define the destructor

      void solveLinearSystem();
      void generateData(void);
      void printData(void);
   protected:
      double getRandomNumber();
      void simplify(void);
      void eliminate(void);
      const int* size;
      double** array;

};

#endif
