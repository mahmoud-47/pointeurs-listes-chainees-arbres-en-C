#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

char **init(int n){
	if(n>N) n = N;
	char **chaine = (char**)malloc(n*sizeof(char*));
	for(int i=0;i<n;i++)
		chaine[i]=NULL;
	return chaine;
}

void addText(char **tab, char *phrase){
	int c;
	for(c=0;c<N && tab[c]!=NULL;c++)
		printf("*");
		;
	if(c==N){
		printf("Le tableau est plein\n");
		exit(1);
	}
	
	int i=0,j,x;
	while(i<N && tab[i]!=NULL && strcmp(tab[i],phrase)<0)
		i++;
	for(j=0;j<N && tab[j]!=NULL;j++)
		;
	for(x=j;x>i;x--)
		tab[x]=tab[x-1];
	tab[x]=(char*)malloc(strlen(phrase)*sizeof(char));
	strcpy(tab[x],phrase);
	
}

void display(char **tab){
	printf("\ndisplay\n");
	for(int i=0;i<N && tab[i];i++)
		printf("%s\n",tab[i]);
}

int main(){
	char **test=init(10);int l=0;
	if(test==NULL)
		printf("Null\n");
	printf("Saisir Quitter pour fermer\n\n");
	char chaine[20];
	int i=0; char *tab[N];
	do{
		printf(">>> ");
		fgets(chaine,20,stdin);
		chaine[strlen(chaine)-1]='\0';
		if(strcmp("Quitter",chaine)!=0){
			//tab[i]=(char*)malloc(sizeof(char)*strlen(chaine));
			//strcpy(tab[i],chaine);
			addText(test,chaine);
			display(test);
			//i++;
		}
	}while(strcmp("Quitter",chaine)!=0 && i<N);
	for(int j=0;j<i;j++)
		free(tab[j]);
	return 0;
}

