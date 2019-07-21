g++ LinearSolver.cpp Newton.cpp main.cpp
file="a.out"
if [ -f "$file" ]
then
	mv "$file" solver
fi
./solver
