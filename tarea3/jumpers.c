
/*
Brayan Zuluaga

*/
#include <stdio.h>
#include <stdlib.h>
int comparar(const void* a, const void* b) {
  return *(const int*)a - *(const int*)b;
    }
int main (){
	int arreglo [3000], i, cantidad, diferencia[3000],suma;
	while(scanf("%d", &cantidad) != EOF){
		suma=0;
		
		for (i=0 ; i<cantidad; i++){
			scanf("%d", &arreglo[i]);
		}
		for (i=1; i<cantidad; i++){
			diferencia[i]= abs(arreglo[i-1]-arreglo[i]);
		}
		qsort(diferencia, cantidad, sizeof(int), comparar);
		for (i=1; i<cantidad; i++){
			if (diferencia[i-1]+1== diferencia[i]){
				suma++;
			}
		}
		if (suma == cantidad-1){
			printf("Jolly\n");
		}		
		else{
			printf("Not jolly\n");
		}
	}
	return 0;
}