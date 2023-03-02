/*
Brayan David Zuluaga
id: 8972631

*/

#include <stdio.h>
#include <stdlib.h>
int comparar(const void* a, const void* b) {
  return *(const int*)a - *(const int*)b;
    }
int main(){
	int posiciones [100];
	int casos, i, tiendas, distancia, j, k;
	i = 1;
	scanf ("%d", &casos);
	while (i <= casos){
		distancia = 0;
		scanf("%d",&tiendas);
		for (j=0; j < tiendas; j++ ){
			scanf("%d", &posiciones[j]);
		}
		qsort(posiciones, tiendas, sizeof(int), comparar);
		
		distancia += (abs(posiciones[tiendas-1] - posiciones[0]))*2;
		printf("%d\n", distancia );
		i++;
	}
	return 0;
}

/*
informacion usada: funcion de ordenamiento qsort
http://arantxa.ii.uam.es/~swerc/ejemplos/csorting.html

*/