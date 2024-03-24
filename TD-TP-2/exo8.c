#include <stdio.h> 
#include <stdbool.h>

void affiche_1(int t[],int n,int k){
	if(k==n-1)
		printf("%d\n",t[k]);
	else{
		printf("%d\n",t[k]);
		affiche_1(t,n,k+1);
	}
	
}

void affiche_2(int t[],int n){
	if(n==0)
		printf("%d\n",t[n]);
	else{
		printf("%d\n",t[n]);
		affiche_2(t,n-1);
	}
}

int somme(int t[],int n){
	if(n==0)
		return t[0];
	return t[n]+somme(t,n-1);
}

bool dicho(int t[],int g, int d,int x){
	int m=(d+g)/2;
	if(g>d)
		return false;
	if(x==t[m])
		return true;
	if(x>m)
		g=m + 1;
	else
		d=m - 1;
	return dicho(t,g,d,x);
}

int main(){

	int n,taille,k,t[20];

	printf("Taille : ");
	scanf("%d",&taille);
	printf("Donnez les %d elements\n",taille);

	for(k=0;k<taille;k++)
		scanf("%d",&t[k]);

	printf("Affichage Croissant \n");
	affiche_1(t,taille,0);

	printf("Affichage Decroissant \n");
	affiche_2(t,taille-1);
	do{
		printf("Donnez l'indice pour la somme : ");
		scanf("%d",&k);
	}while(k>taille);
	
	printf("%d\n",somme(t,k-1));

	printf("Entier à rechercher ? \n");
	scanf("%d",&k);

	printf("%d\n",dicho(t,0,taille,k));
}