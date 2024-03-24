#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
char **init(){
	char **chaine = (char**)malloc(sizeof(char*));
	return chaine;
}

void addText(char ***tab,int *len,char *phrase){
	(*tab) = (char**)realloc(*tab,(*len+1)*sizeof(char*));
	(*tab)[*len] = (char*)malloc(strlen(phrase)*sizeof(char));
	char **p = (*tab)+*len-1;
	while(p>=*tab && strcmp(*p,phrase)>0){
		(*tab)[p-*tab+1]=(char*)realloc(*tab,strlen(*p)*sizeof(char));
		(*tab)[p-*tab+1]=*p;
		p--;
	}
	(*tab)[p-*tab+1]=(char*)realloc(*tab,strlen(phrase)*sizeof(char));
	(*tab)[p-*tab+1]=phrase;
	(*len)++;
}

void display(char **chaine, int line){
	printf("\ndisplay %d\n",line);
	for(int i=0;i<line;i++)
		printf("%s\n",chaine[i]);
}

int main(){
	char **test=init();int l=0;
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
			tab[i]=(char*)malloc(sizeof(char)*strlen(chaine));
			strcpy(tab[i],chaine);
			addText(&test,&l,tab[i]);
			display(test,l);
			i++;
		}
	}while(strcmp("Quitter",chaine)!=0 && i<N);
	for(int j=0;j<i;j++)
		free(tab[j]);
	return 0;
}

