#include <stdio.h>

void ecriture(int tab[],int n,int fin){
	if(n==fin-1)
		printf("%d\n",tab[fin-1]);
	else{
		printf("%d\n",tab[n]);
		ecriture(tab,n+1,fin);
	}
	
}

int main(int argc, char const *argv[]){
	int tab[5]={4,5,6,7,8};
	ecriture(tab,0,5);
	return 0;
}