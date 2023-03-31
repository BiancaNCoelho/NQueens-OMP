# NQueens-OMP
N Queens puzzle implemented in C with OpenMP.

## NQueens Puzzle
The N queens puzzle is the problem of placing N queens in a N X N chess board such that no queen can be attacked by another queen in any possible direction(vertically, horizontally and diagonally).

## Compile and Run
To compile:

sequential:

gcc -o rainhas rainhas.c

parallel-OpenMP:

gcc -o rainhas -fopenmp rainhas.c -lpthread

To run:
./rainhas numberOfQueens numberOfThreads

if numberofThreads = 0 -> sequential

## Contributor(s)
Bianca Nunes Coelho - Computer engeneering student at Universidade Federal de Pelotas(UFPEL)

Alejandro Tomas Reyes Alberoni - Computer science student at Universidade Federal de Pelotas(UFPEL)

Patrick Silva da Rosa - Computer engeneering student at UNiversidade Federal de Pelotas(UFPEL)
