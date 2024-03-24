#include <stdio.h>
#include <stdlib.h>
typedef struct tableau{
	int nb;
	int *tab;
} LSS;
LSS* chiffresentier(int n){
	LSS *p = (LSS*)malloc(sizeof(LSS));
	p -> nb = 0;
	while(n){
		p -> tab = realloc(p->tab,(p->nb +1)*sizeof(int));
		p -> tab[p -> nb] = n%10;
		(p -> nb)++; n/=10;
	}
	return p;
}

void inversecontenu(LSS *t){
	int left=0,right=t->nb-1,temp;
	while(left<right){
		temp = t -> tab[left];
		t -> tab[left] = t -> tab[right];
		t -> tab[right] = temp;
		left++; right--;
	}
}

LSS* nombreentier(int n){
	LSS *p = chiffresentier(n);
	inversecontenu(p);
	return p;
}

void affichestructure(LSS *t){
	if(t->tab){
		for(int i=0;i<t->nb;i++)
			printf("%d\t",t->tab[i]);
		printf("\n");
	}else
		printf("tableau non initialisé\n");
	
}

LSS* creationTab(int n){
	LSS *p=(LSS*)malloc(n*sizeof(LSS));
	for(int i=0;i<n;i++)
		p[i].tab = NULL;
	return p;
}

void stocker(LSS* tab,int item,int nmax){
	int count = 0;
	while(count<nmax && tab[count].tab)
		count++;
	if(count==nmax)
		printf("tableau plein\n");
	else{
		tab[count].nb = nombreentier(item) -> nb;
		tab[count].tab = malloc(tab[count].nb*sizeof(int));
		for(int i=0;i<nombreentier(item) -> nb;i++)
			tab[count].tab[i]=nombreentier(item) -> tab[i];
	}
}

void sort(LSS* tab,int nmax){
	int count = 0; LSS temp;
	while(count<nmax && tab[count].tab)
		count++;
	int i=0,imin,j;
	while(i<count-1){
		imin = i; j=i;
		while(j<count){
			if(tab[j].nb<tab[imin].nb)
				imin = j;
			j++;
		}
		temp = tab[i]; tab[i]=tab[imin]; tab[imin]=temp;
		i++;
	}
}

void afficheTab(LSS *tab, int nmax){
	int count = 0;
	while(count<nmax && tab[count].tab)
		count++;
	if(!count)
		return;
	int max = tab[count-1].nb;
	for(int i=0;i<count;i++){
		for(int j=0;j<max-tab[i].nb;j++)
			printf("  ");
		for(int j=0;j<tab[i].nb;j++)
			printf("%d ",tab[i].tab[j]);
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	LSS *p = nombreentier(1234);
	LSS *tab = creationTab(5);
	stocker(tab,123,5);
	stocker(tab,4567,5);
	stocker(tab,12,5);
	stocker(tab,1,5);
	sort(tab,5);
	for(int i=0;i<5;i++)
		affichestructure(&tab[i]);
	printf("\n--------\n");
	afficheTab(tab,5);
	return 0;
}