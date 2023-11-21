#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// IMPLEMENTAR UN PROGRAMA QUE:
	
	// Utilice los algoritmos: Insertion, Quick y Bubble Sort por medio de funciones
	// Realize un arreglo de 10 mil elementos
	// Ejecute cada algoritmo 100 veces y registre los tiempos de ejecucion.
	
	// Calcular y presentar: Promedio, tiempo minimo y máximo de cada ejecucion para cada algoritmo
	
	// Este enfoque proporcionara una vision más completa del rendmiento de los algoritmos.
	
int CREATEARRAY(int ARRAY[5], int ARRLEN){
	
	for (int i = 0; i < ARRLEN; i++){
		
		int ran = rand()%10000;
		ARRAY[i] = ran;	
	}	
}

int PRINTARRAY (int ARRAY[5], int ARRLEN){
	
	for (int i = 0; i < ARRLEN; i++){
		
		printf("%d  ", ARRAY[i]);	
	
	}	
	printf("\n");
}

// ALGORITMOS SORT

void BubbleSort(int Array[5], int ArrLeng , int Flag){
	
	if (Flag == 0){
		
		Flag = 1;
		
		for (int i = 0; i < ArrLeng; i++){
			
			if (Array[i] > Array[i + 1]){
				
				int AUX = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = AUX;
				
				Flag = 0;
			}
			
		}
		
		BubbleSort(Array, ArrLeng, Flag);
		
	} else if (Flag == 1){
		
		return;
		
	}
}


int INSERTION(int Array[5], int TamArreglo){
	
	for(int i = 0; i < TamArreglo; i++){
		
		int NumActual = Array[i];
		int posAnterior = i - 1;
		
		while (posAnterior >= 0 && Array[posAnterior] > NumActual){
			
			Array[posAnterior + 1] = Array[posAnterior];
			posAnterior --;
			
		}
		
	}
	
}

int QUICKSORT(int ARRAY[5], int FIRST, int LAST){
	
	int pivot, i, j, temp;
	
	if (FIRST < LAST){
		pivot = FIRST;
		i = FIRST;
		j = LAST;
		
		while (i < j){
			
			while(ARRAY[i] <= ARRAY[pivot] && i <= LAST){
				i++;
			}
			while (ARRAY[j] > ARRAY[pivot] && j >= FIRST){
				j--;
			}
			
			if (i < j){
				
				temp = ARRAY[i];
				ARRAY[i] = ARRAY[j];
				ARRAY[j] = temp;
				
			}
			
		}
		temp = ARRAY[j];
		ARRAY[j] = ARRAY[pivot];
		ARRAY[pivot] = temp;
		
		QUICKSORT(ARRAY, FIRST, j-1);
		QUICKSORT(ARRAY, j+1, LAST);
	}
}

int FindSmall(float Arreglo[5], int TamArreglo ){
	
	float AUX = 1000000;
	int INDEX = -1;
	
	for (int i = 0; i < TamArreglo; i++){
		
		if (AUX > Arreglo[i]){
			AUX = Arreglo[i];
			INDEX = i;
		}
	}
	return INDEX;
}

int FindBig(float Arreglo[5], int TamArreglo){
	
	float AUX = -1000000;
	int INDEX = -1;
	
	for (int i = 0; i < TamArreglo; i++){
		
		if (AUX < Arreglo[i]){
			AUX = Arreglo[i];
			INDEX = i;
		}
	}
	return INDEX;
}

float PROMEDIO_ARRAY(float ARRAY[5], int TAMARREGLO){
	
	float SUMAPROMEDIO = 0;
	
	for(int i = 0; i < TAMARREGLO; i++){
		
		SUMAPROMEDIO += ARRAY[i];
		
	}
	printf("TOTAL = %f\n", SUMAPROMEDIO);
	SUMAPROMEDIO = SUMAPROMEDIO / TAMARREGLO;
	return SUMAPROMEDIO;
	
}

int main(){
	
	srand(time(NULL));
	
	
	float PROMEDIO, MINIMO, MAXIMO;
	
	int TEST_ARRAY[MAX_SIZE];
	CREATEARRAY(TEST_ARRAY, MAX_SIZE);
	
	int ejecuciones = 100;
	
	// PRINTARRAY(TEST_ARRAY, MAX_SIZE);
	
	float TIMEARRAY[ejecuciones];
	
	printf("EJECUTANDO BUBBLE SORT: \n");
	
	for (int i = 0; i < ejecuciones; i++){
		
		
		CREATEARRAY(TEST_ARRAY, MAX_SIZE);
		
		clock_t tic = clock();
		BubbleSort(TEST_ARRAY, MAX_SIZE, 0);
		clock_t toc = clock();
		
		TIMEARRAY[i] = (float)(toc - tic)/CLOCKS_PER_SEC;
	}
	
	PROMEDIO = PROMEDIO_ARRAY(TIMEARRAY, ejecuciones);
	MINIMO = TIMEARRAY[FindSmall(TIMEARRAY, ejecuciones)];
	MAXIMO = TIMEARRAY[FindBig(TIMEARRAY, ejecuciones)];
	
	printf("TIEMPO PROMEDIO = %f, TIEMPO MAXIMO = %f, TIEMPO MINIMO = %f",PROMEDIO, MAXIMO, MINIMO);
	
	printf("\n");
	
	printf("EJECUTANDO INSERTION SORT: \n");
	
	for (int i = 0; i < ejecuciones; i++){
		
		CREATEARRAY(TEST_ARRAY, MAX_SIZE);
		
		clock_t tic = clock();
		INSERTION(TEST_ARRAY, MAX_SIZE);
		clock_t toc = clock();
		
		TIMEARRAY[i] = (float)(toc - tic)/CLOCKS_PER_SEC;
	}
	
	PROMEDIO = PROMEDIO_ARRAY(TIMEARRAY, ejecuciones);
	MINIMO = TIMEARRAY[FindSmall(TIMEARRAY, ejecuciones)];
	MAXIMO = TIMEARRAY[FindBig(TIMEARRAY, ejecuciones)];
	
	printf("TIEMPO PROMEDIO = %f, TIEMPO MAXIMO = %f, TIEMPO MINIMO = %f",PROMEDIO, MAXIMO, MINIMO);
	
	printf("\n");
	
	printf("EJECUTANDO QUICK SORT: \n");
	
	for (int i = 0; i < ejecuciones; i++){
		
		CREATEARRAY(TEST_ARRAY, MAX_SIZE);
		
		clock_t tic = clock();
		QUICKSORT(TEST_ARRAY, 0, MAX_SIZE-1);
		clock_t toc = clock();
		
		TIMEARRAY[i] = (float)(toc - tic)/CLOCKS_PER_SEC;
	}
	
	PROMEDIO = PROMEDIO_ARRAY(TIMEARRAY, ejecuciones);
	MINIMO = TIMEARRAY[FindSmall(TIMEARRAY, ejecuciones)];
	MAXIMO = TIMEARRAY[FindBig(TIMEARRAY, ejecuciones)];
	
	printf("TIEMPO PROMEDIO = %f, TIEMPO MAXIMO = %f, TIEMPO MINIMO = %f",PROMEDIO, MAXIMO, MINIMO);
	
	return 0;
}
