#include <iostream>
#include <cstdlib>

using namespace std;


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
            cout <<  array[i][j] << "\t" ;
        }
        cout << endl << endl;
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
    //! j before i, because iterating through rows;
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
            if (array[i][j] == array[rowNumberWithFirstOne][j]){
                for (int k = columnNumberWithFirstOne ; k < *this->size ; k++){
                    array[i][k] = array[i][k] - array[rowNumberWithFirstOne][k];
                }
            }
        }
    }
    rowNumberWithFirstOne++;
    columnNumberWithFirstOne++;
    this->simplify();
}
    /*for (i int = 1 ; i < *this->size ; i++){
        for (j int = 0 ; j < *this->size ; j++){
            if (array[i][j] != 0){
                cout << "linear dependent!!!!!" << endl;
                break;
            }
        }
    }*/

}

void LinearSolver::solveLinearSystem(){
    this->simplify();
    this->eliminate();
}


int main(int argc, char const* argv[]) {
    const int size = 3;
    LinearSolver* solver = new LinearSolver(&size);
    solver->generateData();
    solver->printData();
    cout << endl ;
    solver->solveLinearSystem();
    solver->printData();
    /*cout << endl;
    solver->solveLinearSystem();
    solver->printData();

    cout << endl;
    solver->solveLinearSystem();
    solver->printData();*/

    cout << endl;
    cout << "end";


    delete [] solver;
    return 0;
}
