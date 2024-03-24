#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	srand(time(NULL));
	int test,mys=rand()%1000+1,essai=1;
	while(essai<=10){
		printf("Essaie %d : ",essai);
		scanf("%d",&test);
		if(test==mys){
			printf("Bravo !\n");
			return 0;
		}
		if(test>mys)
			printf("Trop grand\n");
		else
			printf("Trop petit\n");
		essai++;
	}
	printf("Game Over ! Le nombre était %d\n",mys);
	return 0;
}