// Problema das N Rainhas com OpenMP
// 0 --> empty space | 1 ---> queen
// Bianca Nunes Coelho
// Introdução ao Processamento Paralelo e Distribuido (IPPD)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>

void show_board(int **mat, int queens);
bool check_queen(int **mat, int queens, int position);
void put_queen(int **mat, int queens, int position);

int solutions = 0;
int posistion = 0;
	
// Main
int main(int args, char *argv[]){
	
	if (args != 3){
		fprintf(stderr,"Not enough!\n");
	}
	
	int queens, threads;
	int **mat;
	int i,j;
	
	queens = atoi(argv[1]);
	threads = atoi(argv[2]);
	int nMaxProc = omp_get_max_threads();
	omp_set_num_threads(threads);
	
	mat = malloc(queens * sizeof(int*));
	for (i=0;i < queens;i++){
		mat[i] = malloc(queens * sizeof(int));
	}
	
	for (i=0;i<queens;i++){
		for(j=0;j<queens;j++){
			mat[i][j] = 0 ;
		}
	}
	
	// SOLUTION IS SIMPLE: N = 1
	if(queens == 1 ){
		solutions++;
		printf("Solutions = %d.", solutions);
		show_board(mat,queens);
	}
	
	// DOES NOT EXIST A SOLUTION FOR N = 2 AND N = 3
	if(queens == 2 || queens == 3){
		solutions = 0;
		printf("Solutions = %d", solutions);
		show_board(mat,queens);
	}
	
	// CASE N > 3, CACULATE THE NUMBER OF SOLUTIONS POSSIBLE AND PRINT BOARD
	if(queens > 3){
	
	
	}

	return 0;
}

void put_queen(int **mat, int queens, int position){
	int i,j;
	if (position == 8){
		show_board(mat, queens);
		solutions++;
	}else{
		for(i = 0; i < queens; i++){
			for(j = 0; j < queens; j++){
				if (check_queen(mat, queens, position)){
					mat[i][j] = 1;
					put_queen(mat, queens, position+1);
				}
			}
		}
	}
}

// Checks if there is a queen in the diagonal or in the same row or column
bool check_queen(int **mat, int queens, int position){
	int i,j,k,m;
	j = 7;
	m = 7;
	for(i = 0; i < queens; i++){
		while (j != 0){
			if (mat[i][j] == mat[i][j-1]){
				return false;
			} 	
			j--;
		}
	
	}
	
	while (m != 0){
		for (k = 0; k < queens; k++){
			if(mat[m][k] == mat[m+1][j]){
				return false;
			}
		}	
		
		m--;
	}
	
	
	return true;

}

// Show board solution
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

