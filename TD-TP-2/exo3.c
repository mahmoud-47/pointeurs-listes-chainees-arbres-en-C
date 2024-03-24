#include <stdio.h> 

int somme1(int n){
	if(n<1)
		return 0;
	return n*(n+1) + somme1(n-1);
}

int somme2(int n){
	int s=0;
	for(int i=1;i<=n;i++)
		s += i*(i+1);
	return s;
}

int main(){
	int n;
	printf("Nombre : ");
	scanf("%d",&n);
	printf("Fonction 1 : %d\n",somme1(n));
	printf("Fonction 2 : %d\n",somme2(n));
}