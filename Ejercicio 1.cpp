// Programa en C que realice la multiplicacion de dos matrices.
// TAMAÑO = 30 * 30
// Mostrar ambas matrices antes de la multiplicacion y mostrar el resultado
// Las matrices son random y llenadas de 0 a 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

void CrearMatriz(int Matriz[SIZE][SIZE]){
	
	for (int i = 0; i < SIZE; i++){
		
		for (int j = 0; j <SIZE; j++){
			
			int random = rand()% 10;
			
			Matriz[i][j] = random;
			
	 }
	}
	
	return;
}

void PrintMatriz(int Matriz[SIZE][SIZE]){
	
	for (int i = 0; i < SIZE; i++){
		
		for (int j = 0; j < SIZE; j++){
			
			printf("%d  ", Matriz[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
	
	return;
}

int MULTMATRIX(int MATRIZ_1[SIZE][SIZE], int MATRIZ_2[SIZE][SIZE], int MATRIZ_MULT[SIZE][SIZE]){
	printf("\nINICIALIZANDO MULTIPLICACION: \n");
	
	clock_t tic = clock();
	int DOT, DOTSUM, k, SUMA;
	
	for (int i = 0; i < SIZE; i++){
		
		SUMA = 0;
		
		for (int j = 0; j < SIZE; j++){
			
			DOTSUM = 0;
			
			for (k = 0; k < SIZE; k++){
				
				DOT = (MATRIZ_1[i][k] * MATRIZ_2[k][j]);
				
				DOTSUM += DOT;
				
			}
			
			MATRIZ_MULT[i][j] = DOTSUM;
			
			printf("%d ", MATRIZ_MULT[i][j]);
		}
		
		printf("\n");
		
	}
	clock_t toc = clock();
	printf("FUNCTION TIME ELAPSED: %f SECONDS\n", (float)(toc - tic)/CLOCKS_PER_SEC);
	return 0;
	
}

int main(){
	
	srand(time(NULL));
	
	int MATRIX1[SIZE][SIZE];
	int MATRIX2[SIZE][SIZE];
	
	CrearMatriz(MATRIX1);
	CrearMatriz(MATRIX2);
	
	printf("MATRIZ 1: \n");
	PrintMatriz(MATRIX1);
	printf("MATRIZ 2: \n");
	PrintMatriz(MATRIX2);
	
	// AMBAS MATRICES SON CUADRADAS, POR LO QUE LA MULTIPLICACION ES POSIBLE.
	
	int MATRIZ_MULT[SIZE][SIZE];

	MULTMATRIX(MATRIX1, MATRIX2, MATRIZ_MULT);
	
	return 0;
}
