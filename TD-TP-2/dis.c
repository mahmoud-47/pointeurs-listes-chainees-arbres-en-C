#include <stdio.h>

void affichage(int t[],int n){
	if(n==1)
		printf("%d\n",t[0]);
	else{
		affichage(t,n-1);
		printf("%d\n",t[n-1]);
	}
}

void affichage2(int t[],int n){
	if(n==1)
		printf("%d\n",t[0]);
	else{
		
		printf("%d\n",t[n-1]);
		affichage2(t,n-1);
	}
}

int main(){
	int n=5,t[]={9,8,7,6,5};
	affichage2(t,n);
	return 0;
}