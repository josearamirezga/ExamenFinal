#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50000

// EL PROGRAMA NO TOMA EN CUENTA EL TIEMPO DE EJECUCION DE LOS ALGORITMOS SORT PARA EL BINARY FIND.

// ALGORITMOS

int BINARY_FIND(int Arreglo[5], int TamArreglo, int ELEMENTO){
	
	int primero = 0;
	int ultimo = TamArreglo - 1;
	int mitad = (primero + ultimo)/2;
	
	while (primero <= ultimo){
		
		if (Arreglo[mitad] < ELEMENTO){
			
			primero = mitad + 1;
			
		} else if (Arreglo[mitad] == ELEMENTO){
		return mitad - 1;
		
		} else {
			ultimo = mitad - 1;

		}
		mitad = (primero + ultimo)/2;
	}
		
}

int SEQUENCE_FIND(int num, int lista[5], int elemento){
	
	for (int i = 0; i < num; i++){
		
		if (lista[i] == elemento){
			
			return i;
			
		}
		
	}
	return -1;
}

// PROMEDIOS Y ESTADISTICAS

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


// ARRAYS

int CREATEARRAY(int ARRAY[5], int ARRLEN){
	
	for (int i = 0; i < ARRLEN; i++){
		
		int ran = rand()%50000;
		ARRAY[i] = ran;	
	}	
}

int main(){
	
	srand(time(NULL));
	
	float PROMEDIO, MINIMO, MAXIMO;
	
	int TEST_ARRAY[MAX_SIZE];
	int ejecuciones = 100;
	int FIND_ELEMENT = 0;
	
	float TIMEARRAY[ejecuciones];
	
	printf("COMENZANDO LOS ALGORITMOS FIND: SEQUENCE \n");
	
	for (int i = 0; i < ejecuciones; i++){
		

		CREATEARRAY(TEST_ARRAY, MAX_SIZE);
		FIND_ELEMENT = rand()%50000;
		clock_t tic = clock();
		SEQUENCE_FIND(MAX_SIZE, TEST_ARRAY, FIND_ELEMENT);
		clock_t toc = clock();
		
		TIMEARRAY[i] = (float)(toc - tic)/CLOCKS_PER_SEC;
	}
	
	PROMEDIO = PROMEDIO_ARRAY(TIMEARRAY, ejecuciones);
	MINIMO = TIMEARRAY[FindSmall(TIMEARRAY, ejecuciones)];
	MAXIMO = TIMEARRAY[FindBig(TIMEARRAY, ejecuciones)];
	
	printf("TIEMPO PROMEDIO = %f, TIEMPO MAXIMO = %f, TIEMPO MINIMO = %f",PROMEDIO, MAXIMO, MINIMO);
	printf("\n");
	
	printf("COMENZANDO LOS ALGORITMOS FIND: BINARY \n");
	
	for (int i = 0; i < ejecuciones; i++){
		
		FIND_ELEMENT = rand()%50000;
		CREATEARRAY(TEST_ARRAY, MAX_SIZE);
		QUICKSORT(TEST_ARRAY, 0,MAX_SIZE-1);
		
		FIND_ELEMENT = rand()%50000;
		clock_t tic = clock();
		BINARY_FIND( TEST_ARRAY ,MAX_SIZE, FIND_ELEMENT);
		clock_t toc = clock();
		
		TIMEARRAY[i] = (float)(toc - tic)/CLOCKS_PER_SEC;
	}
	
	PROMEDIO = PROMEDIO_ARRAY(TIMEARRAY, ejecuciones);
	MINIMO = TIMEARRAY[FindSmall(TIMEARRAY, ejecuciones)];
	MAXIMO = TIMEARRAY[FindBig(TIMEARRAY, ejecuciones)];
	
	printf("TIEMPO PROMEDIO = %f, TIEMPO MAXIMO = %f, TIEMPO MINIMO = %f",PROMEDIO, MAXIMO, MINIMO);
	printf("\n");
	
}
