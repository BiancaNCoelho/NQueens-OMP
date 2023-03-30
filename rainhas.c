// Problema das N Rainhas com OpenMP
// 0 --> empty space | 1 ---> queen
// Introdução ao Processamento Paralelo e Distribuido (IPPD)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#ifdef _OPENMP
	#include <omp.h> 
#endif

void show_board(int **mat, int queens);
bool check_queen(int **mat, int queens, int row, int column);
void put_queen(int **mat, int queens, int position);

int solutions = 0; // number of solutions to the problem

// Main
int main(int args, char *argv[]){
	
	if (args != 3){
		fprintf(stderr,"Not enough!\n");
	}
	
	int queens, threads;
	int **mat;
	int i,j;
	double time;
	clock_t t;
	
	queens = atoi(argv[1]);
	threads = atoi(argv[2]);
#ifdef _OPENMP
	omp_set_num_threads(threads);
#endif	
	// Creates the board for the problem
	mat = malloc(queens * sizeof(int*));
	for (i=0;i < queens;i++){
		mat[i] = malloc(queens * sizeof(int));
	}
	
	for (i=0;i<queens;i++){
		for(j=0;j<queens;j++){
			mat[i][j] = 0 ;
		}
	}
	printf("--------------------------------------------\n");
    	printf("Solving N-Queen\n");
    	printf("--------------------------------------------\n");
	
	t = clock();
	// SOLUTION IS SIMPLE FOR N = 1
	if(queens == 1 ){
		solutions++;
		mat[0][0] = 1;
		show_board(mat,queens);
	}
	
	// DOES NOT EXIST A SOLUTION FOR N = 2 AND N = 3
	if(queens == 2 || queens == 3){
		solutions = 0;
		show_board(mat,queens);
	}
	
	// CASE N > 3, CACULATE THE NUMBER OF SOLUTIONS POSSIBLE AND PRINT BOARD
	if(queens > 3){
		put_queen(mat,queens,0);
	}
	
	t = clock() - t;
	time = ((double)t)/CLOCKS_PER_SEC;
	
	printf("--------------------------------------------\n");
    	printf("Solved!\n");
	printf("Solutions: %d\n", solutions);
	printf("Queens : %d\n", queens);
	printf("Board size: %d\n", queens*queens);
#ifdef _OPENMP
	printf("Number of threads: %d\n", threads);
#else
	printf("Number of threads: %d\n", 0);
#endif
	printf("Time(in seconds): %f\n", time);
	return 0;
}

// Put a queen in the board
void put_queen(int **mat, int queens, int positioned){
	int i,j;

	if (positioned == queens){
		show_board(mat, queens);
		solutions++;
		return;
	}

	for(i = 0; i < queens; i++){
		if (check_queen(mat, queens,positioned,i)){
			mat[positioned][i] = 1;
			put_queen(mat, queens,positioned+1);
			mat[positioned][i] = 0;
		}	
	}
}

// Checks if there is a queen in the diagonal or in the same row or column
bool check_queen(int **mat, int queens, int pos, int column){
	int i,j;

	// column -
	for(i = 0; i < pos; i++){
		if(mat[i][column] == 1){
			return false;
		}
	}

	// '\'
	for(int i = pos, j = column; i >= 0 && j >= 0; i--,j--){
		if(mat[i][j] == 1){
			return false;
		}
	}
	
	// '/'
	for(int i = pos, j = column; i >= 0 && j < queens; i--,j++){
		if(mat[i][j] == 1){
			return false;
		}
	}

	return true;

}

// Show board of one solution
void show_board(int **mat , int queens){
	int i,j;
	for (i = 0; i < queens; i++){
		for (j = 0; j < queens; j++){
			printf("[%d]", mat[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
}

