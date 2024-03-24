#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Max 150

typedef struct {
	int numero;
	char prenom[50];
	char nom[20];
	float montant;
} Compte;

typedef Compte TAB_COMPTE[Max];
typedef FILE *fichier;


void creerCompteVide (char nom[], char prenom[], int numero, Compte *newCompte){
	strcpy(newCompte -> prenom, prenom);
	strcpy(newCompte -> nom, nom);
	newCompte -> numero = numero;
	newCompte -> montant = 0;
	printf("Compte numéro %d créé\n",numero);
}

void deposerArgent (float somme, Compte *monCompte){
	monCompte -> montant += somme;
	printf("Somme %f déposée sur le compte numéro %d\n", somme, monCompte -> numero);
}

void retirerArgent (float somme, Compte *monCompte){
	if(monCompte -> montant < somme)
		printf("Montant insuffisant !\n");
	else{
		monCompte -> montant -= somme;
		printf("Montant %f retiré du compte numéro %d\n", somme, monCompte -> numero);
	}
}

void afficherCompte (Compte monCompte){
	printf("\t************ Infos compte *****************\n");
	printf("Compte N : %d\n",monCompte.numero);
	printf("Nom complet : %s %s\n",monCompte.prenom, monCompte.nom);
	printf("Montant : %f\n",monCompte.montant);
}

void ajouterCompte (Compte monCompte ,TAB_COMPTE t, int *n){
	strcpy(t[*n].prenom, monCompte.prenom);
	strcpy(t[*n].nom, monCompte.nom);
	t[*n].montant = monCompte.montant;
	t[*n].numero = monCompte.numero;
	*n += 1;
	printf("Compte numéro %d ajouté\n",monCompte.numero);
}

void rechercheAjout (int numCompte, float som, TAB_COMPTE t, int n){
	int trouve = 0, i=0;
	while(i<n && !trouve){
		trouve = (t[i].numero == numCompte);
		i++;
	}
	if(i<n){
		t[--i].montant += som;
		printf("Somme %f déposée sur le compte numéro %d\n", som, t[i].numero);
	}else
		printf("Le compte %d n'existe pas !!!\n",numCompte);
}

void sauverComptes (char *nomFichier, TAB_COMPTE t , int nbElements){
	fichier file = fopen(nomFichier,"w");
	if(file==NULL){
		printf("!!! Error while opening %s !!!\n", nomFichier);
		exit(-1);
	}
	fprintf(file,"Numero\tPrenom\tNom\tMontant\n");
	for(int i=0; i<nbElements; i++)
		fprintf(file,"%d\t%s\t%s\t%f\n",t[i].numero, t[i].prenom, t[i].nom, t[i].montant);
	fclose(file);
	printf("Sauvegarde vers %s réussie\n",nomFichier);
}


int main(){
	int size, ncompte, test;
	float somme;
	TAB_COMPTE t;
	Compte compte_test={179,"Compte","Ajouté",100000};
	char nom[25], file_name[30 	];

	printf("Nombre de comptes >>> ");
	scanf("%d",&size);
	//Creer les comptes
	printf("\n********************* Creation des comptes ***********************\n");
	for(int i=0; i<size; i++){
		sprintf(nom,"Nom%d",i);
		creerCompteVide(nom,"User",i,&t[i]);
	}
	ajouterCompte(compte_test,t,&size);
	//Etat de la base de données
	printf("\n********************* Etat de la base de données ***********************\n");
	for(int i=0;i<size;i++){
		printf("%d",i);
		afficherCompte(t[i]);
	}
	//Depos
	printf("\n********************* Depos ***********************\n");
	for(int i=0;i<size;i++){
		deposerArgent(rand()%10000, &t[i]);
	}
	//Etat de la base de données
	printf("\n********************* Etat de la base de données ***********************\n");
	for(int i=0;i<size;i++){
		printf("%d",i);
		afficherCompte(t[i]);
	}
	//Insertion des montants
	printf("\n********************* Insertion des montants ***********************\n");
	srand(time(NULL));
	for(int i=0;i<20;i++){
		rechercheAjout(rand()%1000,(float)rand()/5,t,size);
	}	
	//Retrait
	printf("\n********************* Retraits ***********************\n");
	for(int i=0;i<size;i++){
		retirerArgent(rand()%100000, &t[i]);
	}
	printf("\n\nFichier pour enregistrer >>> ");
	scanf("%s",file_name);
	sauverComptes(file_name, t, size);
	return 0;
}