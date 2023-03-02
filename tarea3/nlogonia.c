//Brayan Zuluaga 

//
#include <stdio.h>
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