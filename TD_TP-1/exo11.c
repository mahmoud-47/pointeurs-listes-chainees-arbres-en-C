#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool JeSuisUnSigneDePonctuation(char c){
	if(c=='.' || c=='?' || c=='!' || c==',' || c==';')
		return true;
	return false;
}

bool JeSuisUnChiffre(char c){
	if(c>='0' && c<='9')
		return true;
	return false;
}

void lirePhrase (char maPhrase[]){
	int i=0,c=0,p=0;
	while(maPhrase[i]!='\0'){
		if(JeSuisUnChiffre(maPhrase[i]))
			c++;
		if(JeSuisUnSigneDePonctuation(maPhrase[i]))
			p++;
		i++;
	}
	printf("Chiffres = %d\nPonctuations = %d\nLength = %d\n",c,p,i);
}

int main(){
	char chaine[30];
	printf("%s\n", chaine);
	scanf("%[^\n]",chaine);
	lirePhrase(chaine);
	return 0;
}