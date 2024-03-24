#include <stdio.h> 

float puissance(float n,int p){
	if(p==0)
		return 1;
	return n*puissance(n,p-1);
}


int main(){
	float n;
	int p;
	printf("Nombre : ");
	scanf("%f",&n);
	printf("Puissance : ");
	scanf("%d",&p);
	printf("%f\n",puissance(n,p));
}