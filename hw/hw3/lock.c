#include <stdio.h>

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