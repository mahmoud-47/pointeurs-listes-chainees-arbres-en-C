#include <stdio.h>

int somme(int tab[],int taille){
	if(taille==-1)
		return 0;
	return tab[taille]+somme(tab,taille-1);
}

int main(){
	int n=3,tab[5]={1,2,3,4};
	printf("%d\n",somme(tab,n));
	return 0;
}