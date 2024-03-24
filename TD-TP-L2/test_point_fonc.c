#include <stdio.h>
#include<stdlib.h>

int carre(int n){
	return n*n;
}

void affiche_carre(int i){
	printf("%d ",i*i);
}

void map(int t[],int n,void(*f)(int)){
	for(int i=0;i<n;i++)
		(*f)(t[i]);
}

int main(){
	int(*f)(int);
	f=carre;
	int n,t[5]={1,2,3,4,5};
	printf("Donner un nombre ");
	scanf("%d",&n);
	printf("Le carre est %d\n",(*f)(n));
	printf("--------\n");
	map(t,5,affiche_carre);
	return 0;
}