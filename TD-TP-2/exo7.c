/*
C(n,0)=1 ; C(n,n)=1
C(n,p)=C(n-1,p)+C(n-1,p-1)
*/
#include <stdio.h> 

int C(int n,int p){
	if(p==0 || n==p)
		return 1;
	return C(n-1,p)+C(n-1,p-1);
}

int main(){
	int n,p;
	do{
		printf("n : ");
		scanf("%d",&n);
		printf("p : ");
		scanf("%d",&p);
	}while(p>n);
	printf("%d\n",C(n,p));
}