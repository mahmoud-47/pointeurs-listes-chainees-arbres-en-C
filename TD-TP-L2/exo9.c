#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct{
	int num;
	double(*fonc)(double,double);
} dict;
double surf_rect(double a, double b){
	return a*b;
}
double surf_tria(double a, double b){
	return a*b/2;
}
double surf_disq(double a, double b){
	return 3.14*a*a;
}
double calc(double a, double b, double(*f)(double,double)){
	return (*f)(a,b);
}
int main(){
	dict tab[N]={
		{1,surf_rect},
		{2,surf_tria},
		{3,surf_disq},
	};
	int id;
	printf("Donner un id ");
	scanf("%d",&id);
	int found=0,i=0;
	while(i<N && !found){
		if(tab[i].num==id)
			found=1;
		else
			i++;
	}
	if(!found)
		printf("Entrer qlq chose entre 1 et %d\n",N);
	else{
		double a,b;
		printf("Donner a et b ");
		scanf("%lf %lf",&a,&b);
		printf("Le resultat est %lf\n",calc(a,b,tab[i].fonc));
	}
	return 0;
}