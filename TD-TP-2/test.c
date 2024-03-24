#include <stdio.h>

void disp(int t[],int n){
	if(n==1)
		printf("%d    ",t[0]);
	else{
		disp(t,n-1);
		printf("%d    ",n-1);
	}
}
int main(){
	int t[5]={1,2,3,4,5};
	disp(t,4);
}