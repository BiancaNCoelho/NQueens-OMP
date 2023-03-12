// Problema das N Rainhas
// . --> espaço vazio | Q ---> queen
// Bianca Nunes Coelho

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>

void show_board();
void check_queen();
void put_queen();

int solutions = 0;

// Main
int main(int args, char *argv[]){
	
	if (args != 3){
		fprintf(stderr,"Not enough!\n");
	}
	
	int queens, threads;
	
	queens = atoi(argv[1]);
	threads = atoi(argv[2]);
	
	int nMaxProc = omp_get_max_threads(); 
	
	omp_set_num_threads(threads);
	
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

/*
void put_queen(){
	if(target == queens){
		show_board();
		solutions++;
	}else{
	
	}
}

void show_board(){
	int i,j;
	for (i = 0; i < queens; i++){
		for (j = 0; j < queens; j++){
			//TO DO		
		}
		printf("\n");
	}
	printf("\n");

}
*/
