class LinearSolver {
   public:
      //LinearSolver(void);
      ~LinearSolver(void);//define the destructor
      void solveLinearSystem();
      void generateData(void);
      void printData(void);
      void clearData(void);
      void setSize(int size);
      double getRandomNumber();
      void simplify(void);
      void echelon_form(void);
      void solve(void);
      int size;
      double** array;

};
