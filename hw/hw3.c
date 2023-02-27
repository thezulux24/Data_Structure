/*
Brayan David Zuluaga
id: 8972631

*/

//parking
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
//había usado otro método pero implementé en este documento el que el profesor Calrare mostró en clases

/*
informacion usada: funcion de ordenamiento qsort
http://arantxa.ii.uam.es/~swerc/ejemplos/csorting.html

*/

//nlogonia

int main(){
	int casos, key, x, y, n,m, finalX, finalY,i;
	scanf("%d",&casos);
	while(casos != 0){
		scanf("%d",&n);
		scanf("%d",&m);
		for (i=0; i<casos; i++){
			scanf("%d",&x);
			scanf("%d",&y);
			finalX = x - n;
			finalY = y- m;
			if(finalX == 0 || finalY ==0){
				printf("divisa\n");
			}
			if (finalX > 0 && finalY > 0){
				printf("NE\n");
			}
			if(finalX < 0 && finalY < 0){
				printf("SO\n");
			}
			if(finalX > 0 && finalY < 0){
				printf("SE\n");
			}
			if(finalX < 0 && finalY >0){
				printf("NO\n");
			}
		}
	scanf("%d",&casos);
	}
	return 0;
}


//lock

int main(){
	int combinaciones[4], i, gradosUnit, suma, j, gradosTotal;
	gradosUnit = 360/40;
	i = 1 ;
	suma= 1;
	for (j= 0; j<4; j++){
		scanf("%d", &combinaciones[j]);
		suma += combinaciones[j];
	}
	if (suma== 1){
		i = 0;
	}
	while (i == 1){
		suma= 1;
		gradosTotal = 1080;
		gradosTotal += ((combinaciones[0] - combinaciones[1] + 40)%40) *gradosUnit;
		gradosTotal += ((combinaciones[2] - combinaciones[1] + 40)%40) *gradosUnit;
		gradosTotal += ((combinaciones[2] - combinaciones[3] + 40)%40) *gradosUnit;

		printf("%d\n", gradosTotal );
		for (j= 0; j<4; j++){
			scanf("%d", &combinaciones[j]);
			suma += combinaciones[j];
		}
		if (suma== 1){
			i = 0;
		}
	}
	return 0;
}

//jumpers
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
