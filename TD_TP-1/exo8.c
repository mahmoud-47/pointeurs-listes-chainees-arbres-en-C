#include <stdio.h>

void estPrmier1(int n,int *etat){
	int i;
	if(n<=1)
		*etat = 0;
	else{
		i = 2; *etat = 1;
		while((i<=n/2) && (*etat==1)){
			if(n%i==0)
				*etat = 0;
			i++;
		}
	}
}
int estPrmier2(int n){
	int i;
	if(n<=1)
		return 0;
	else{
		i = 2;
		while(i<=n/2){
			if(n%i==0)
				return 0;
			i++;
		}
		return 1;
	}
}

int main(){
	int test,n;;
	printf("donnez un nombre ");
	scanf("%d",&n)
	/*-------------*/
	estPrmier1(n,&test);
	printf("Test avec la procedure : %d\n",test);
	/*-------------*/
	printf("Test avec la fonction : %d\n",estPrmier2(n));
	return 0;
}