//imports
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

//Nombre parfait
bool parfait(int n){
	int somme = 1;
	for(int i=2;i<=n/2;i++)
		if(n%i==0)
			somme += i;
	return somme == n;
}

//Maj min
void transfo_en_maj(char minus[],char maj[]){
	int i;
	for(i=0;minus[i]!='\0';i++)
		maj[i]=toupper(minus[i]);
	maj[i]='\0';
}

//+ ou -
void plus_moins(){
	srand(time(NULL));
	int test,mys=rand()%1000+1,essai=1;
	while(essai<=10){
		printf("Essaie %d : ",essai);
		scanf("%d",&test);
		if(test==mys){
			printf("Bravo !\n");
			return ;
		}
		if(test>mys)
			printf("Trop grand\n");
		else
			printf("Trop petit\n");
		essai++;
	}
	printf("Game Over ! Le nombre était %d\n",mys);
}

int main(){
	int choice,continuer;
	do{

		printf("\t\t*** Menu ***\n1\tSavoir si un nombre est parfait\n2\tTransformer une chaine en majuscule\n3\tJouer au jeu du + ou du -\n>>> ");
		scanf("%d",&choice);

		while(choice!=1 && choice!=2 && choice!=3){
			printf("Choisissez entre 1,2 et 3 please ! >>> ");
			scanf("%d",&choice);
		}

		if(choice==1){
			int nombre;
			printf("Donnez un nombre >>> ");
			scanf("%d",&nombre);
			if(parfait(nombre))
				printf("Ce nombre est parfait\n");
			else
				printf("Ce nombre n\'est parfait\n");
		}else if(choice==2){
			char to_chaine[50],from_chaine[50];
			printf("Chaine à transformer >>> ");
			scanf("\n%[^\n]",to_chaine);
			transfo_en_maj(to_chaine,from_chaine);
			printf("La chaine en majuscule donne : %s\n",from_chaine);
		}else
			plus_moins();

		printf("\nChoisir 1 pour continuer ou autre chose pour arreter >>> ");
		scanf("%d",&continuer);
		
	}while(continuer==1);
	
	printf("Merci !!!\n");
	return 0;
}