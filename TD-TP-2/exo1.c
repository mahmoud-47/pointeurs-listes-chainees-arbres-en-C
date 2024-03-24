#include <stdio.h> 

int somme(int n){
	if(n<1)
		return 0;
	return n + somme(n-1);
}

int main(){
	int n;
	printf("Nombre : ");
	scanf("%d",&n);
	printf("%d\n",somme(n));
}