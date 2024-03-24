#include <stdio.h>

int A(int m,int n){
	if(m==0 && n!=0)
		return n+1;
	if(n==0 && m!=0)
		return A(m-1,1);
	return A( m-1,A( m,n-1 ) );
}

int main(){
	int m,n;
	printf("Donnez m et n\n");
	scanf("%d %d",&m,&n);
	printf("%d\n",A(m,n));
}