#include <stdio.h>
#include <stdbool.h>
bool parfait(int n){
	int somme = 1;
	for(int i=2;i<=n/2;i++)
		if(n%i==0)
			somme += i;
	return somme==n;
}
int main(){
	for(int i=2; i<10000;i++)
		if(parfait(i))
			printf("%d\n",i);
	return 0;
}