#include <stdio.h>

int left(int n){
	int r=0,m=1;
	while(n>10){
		r = (n%10)*m +r;
		n = n/10;
		m = m*10;
	}
	printf("%d ",n);
	return r;
}

int main(){
	int n;
	printf("Donnez un nombre ");
	scanf("%d",&n);
	while(n>0)
		n=left(n);
	printf("\n");
	return 0;
}
