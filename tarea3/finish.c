//Brayan David Zuluaga

#include <stdio.h>

int main (){
	int n = 1 , casos, nEstaciones, gasolinaNecesaria[100001], gasolinaEstaciones [100001], gasolina, minimo, estacion, i;
	scanf("%d", &casos);
	while(n <= casos ){
		scanf("%d",&nEstaciones);
		for (i = 1; i <= nEstaciones; i++){
			scanf("%d",&gasolinaEstaciones[i]);
		}
		for (i = 1; i<= nEstaciones; i++){
			scanf("%d", &gasolinaNecesaria[i]);
		}
		gasolina = 0;
		minimo = 0;
		estacion = 1;
		for (i = 1 ; i <= nEstaciones; i++){
			gasolina += gasolinaEstaciones[i] - gasolinaNecesaria[i];
			if (gasolina < minimo){
				minimo = gasolina;
				estacion = i +1 ;
			}
		}
		if (gasolina < 0){
			printf("Case %d: Not possible\n", n);
		}
		else{
			printf("Case %d: Possible from station %d\n", n, estacion);
		}
		n++;
	}
	return 0;
}