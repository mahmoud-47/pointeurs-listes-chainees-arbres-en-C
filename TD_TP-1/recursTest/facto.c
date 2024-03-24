#include <stdio.h>

double fact(int n){
	if(n==0)
		return 1;
	return n*fact(n-1);
}

int main(){
	int n;
	printf("Facto ? ");
	scanf("%d",&n);
	printf("%lf\n",fact(n));
	return 0;
}