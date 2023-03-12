// Problema das N Rainhas
// 0 --> espaço vazio | 1 ---> queen
// Bianca Nunes Coelho

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>

void show_board();
void show_valid_solution();
void check_queen();
void put_queen();

// Main
int main(int args, char *argv[]){
	
	if (args != 3){
		fprintf(stderr,"Not enough!\n");
	}
	
	int queens, threads;
	
	queens = atoi(argv[1]);
	threads = atoi(argv[2]);
	
	int **mat;
	int i,j;
	
	mat = malloc(queens * sizeof(int*));
	
	for (i=0;i < queens;i++){
		mat[i] = malloc(queens * sizeof(int));
	}
	
	for (i=0;i<queens;i++){
		for(j=0;j<queens;j++){
			mat[i][j] = 0;
		}
	}
	
	for (i=0;i<queens;i++){
		for(j=0;j<queens;j++){
			printf("[%d]", mat[i][j]);
		}
	}

	return 0;
}

voiod show_board(){
	int i,j;
	for (i = 0; i < queens; i++){
		for (j = 0; j < queens; j++){
			
		}
		printf("\n");
	}
	printf("\n");

}
