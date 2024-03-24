#include <stdio.h>

int somme(int n){
	return n*(n+1)/2;
}

int main(){
    int n;
    printf("Donnez un nombre ");
    scanf("%d",&n);
	printf("Somme = %d\n",somme(n));
	return 0;
}
