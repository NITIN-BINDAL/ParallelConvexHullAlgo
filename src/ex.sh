#! /bin/sh
g++ -std=c++2a Sequential.cpp
./a.out<input.txt>SequentialOutput.txt
g++ -std=c++2a Parallelized.cpp -fopenmp
./a.out<input.txt>ParallelizedOutput.txt
cmp --silent output1.txt output2.txt && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###' 
