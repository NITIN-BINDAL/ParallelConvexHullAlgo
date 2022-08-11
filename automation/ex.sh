#! /bin/sh
g++ -std=c++2a ../src/Sequential.cpp
./a.out<../src/Input/input.txt>../src/Output/SequentialOutput.txt
g++ -std=c++2a ../src/Parallelized.cpp -fopenmp
./a.out<../src/Input/input.txt>../src/Output/ParallelizedOutput.txt
cmp --silent  ../src/Output/SequentialOutput.txt ../src/Output/ParallelizedOutput.txt && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###' 
