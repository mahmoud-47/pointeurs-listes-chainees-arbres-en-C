/*
	Librairies
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Types
*/

typedef struct DateDeNaissance{
	int jour;
	int mois;
	int annee;
} DateDeNaissance;

typedef struct Etudiant{
	char nom[20];
	char prenom[50];
	DateDeNaissance naiss;
	char classe[5];
	float note_cont;
	float note_tp;
	float note_exam;
	float moy;
} Etudiant;

typedef Etudiant TAB_Etudiant[300];
typedef Etudiant TAB_Etudiant_MASS[400];
typedef FILE *FIC_Etudiant;

/*
	Quelques Fonctions Utiles
*/

void affectation(Etudiant *var, Etudiant val){
	strcpy(var -> prenom, val.prenom);
	strcpy(var -> nom, val.nom);
	var -> naiss.jour = val.naiss.jour;
	var -> naiss.mois = val.naiss.mois;
	var -> naiss.annee = val.naiss.annee;
	strcpy(var -> classe, val.classe);
	var -> note_cont = val.note_cont;
	var -> note_tp = val.note_tp;
	var -> note_exam = val.note_exam;
	var -> moy = val.moy;
}

void permuter(Etudiant *et1, Etudiant *et2){
	Etudiant etu;
	affectation(&etu,*et1);
	affectation(et1,*et2);
	affectation(et2,etu);
}

void afficher(Etudiant etu){
	printf("\nInfos :\nNom complet : %s %s\n",etu.prenom,etu.nom);
	printf("Date de naissance : %d/%d/%d\n",etu.naiss.jour, etu.naiss.mois, etu.naiss.annee);
	printf("Classe : %s\n",etu.classe);
	printf("Controle = %f/20  TP = %f/20  Examen = %f/20\n",etu.note_cont,etu.note_tp,etu.note_exam);
	printf("Moyenne : %f/20\n",etu.moy);
}

/*
	Fonctions
*/

void saisirEtudiant(Etudiant *etu){
	char c; 
	scanf("%c",&c);
	printf("\nSaisie :\nPrenom >>> ");
	scanf("%s",etu -> prenom);
	printf("Nom >>> ");
	scanf("%s",etu -> nom);
	printf("Jour/Mois/Année >>> ");
	scanf("%d/%d/%d",&etu -> naiss.jour, &etu -> naiss.mois, &etu -> naiss.annee);
	do{
		printf("Classe >>> ");
		scanf("%s",etu -> classe);
	}while(strcmp(etu -> classe, "MASS")!=0 && strcmp(etu -> classe, "MPI")!=0);
	printf("Notes controle, TP et examen >>> ");
	scanf("%f %f %f",&etu -> note_cont, &etu -> note_tp, &etu -> note_exam);
}

void saisirTabEtudiant(TAB_Etudiant t, int n){
	for(int i=0; i<n; i++)
		saisirEtudiant(&t[i]);
}

void calculerMoyenne (TAB_Etudiant t, int n){
	for(int i=0; i<n; i++)
		t[i].moy = (t[i].note_cont + t[i].note_tp + 2*t[i].note_exam)/4;
}

void creerFicEtudiant(TAB_Etudiant t, int n, char *file_name){
	FIC_Etudiant f = fopen(file_name,"w");
	if(f==NULL){
		printf("Error while opening %s\n",file_name);
		exit(-1);
	}
	fprintf(f, "Prenom\tNom\tDate de naissance\tClasse\tNoteControle\tNoteTP\tNoteExamen\tMoyenne\n");
	for(int i=0;i<n;i++){
		fprintf(
			f, 
			"%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%f\t\t%f\t\t%f\t\t%f\n",
			t[i].prenom, t[i].nom, t[i].naiss.jour, t[i].naiss.mois, t[i].naiss.annee, t[i].classe, 
			t[i].note_cont, t[i].note_tp, t[i].note_exam, t[i].moy
		);
	}
	fclose(f);
	printf("*** Fichier %s créé ***\n",file_name);
}

void extraireMASS(TAB_Etudiant_MASS tabMass, char *file_name, int *i){
	FIC_Etudiant f = fopen(file_name,"r");
	if(f==NULL){
		printf("Error while opening %s.txt\n",file_name);
		exit(-1);
	}
	*i = 0;
	int line = 0;
	while(
		fscanf(
			f,
			"%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%f\t\t%f\t\t%f\t\t%f\n",
			tabMass[*i].prenom, tabMass[*i].nom, &tabMass[*i].naiss.jour, &tabMass[*i].naiss.mois, 
			&tabMass[*i].naiss.annee, tabMass[*i].classe, &tabMass[*i].note_cont, &tabMass[*i].note_tp, 
			&tabMass[*i].note_exam, &tabMass[*i].moy
		)!=EOF
	){
		printf("***%s*%s*\n",tabMass[*i].prenom,tabMass[*i].nom);
		if(strcmp(tabMass[*i].classe,"MASS")==0)
			*i = *i + 1;
	}
	fclose(f);
}

void trierMASS (TAB_Etudiant_MASS tabMass, int n ){
	int imax;
	for(int i=0;i<n;i++){
		imax = i;
		for(int j=i;j<n;j++)
			if(tabMass[j].moy>tabMass[imax].moy)
				imax = j;
		permuter(&tabMass[i],&tabMass[imax]);
	}
}

/*
	Main
*/

int main(){
	TAB_Etudiant t;
	TAB_Etudiant_MASS t2;
	int taille,taille2;
	char file_name[30];
	/*printf("Taille >>> ");
	scanf("%d",&taille);
	saisirTabEtudiant(t,taille);
	calculerMoyenne(t,taille);
	printf("\nNom du fichier avec extension >>> ");
	scanf("%s",file_name);
	creerFicEtudiant(t,taille,file_name);
	extraireMASS(t2,file_name,&taille2);*/
	extraireMASS(t2,"lol",&taille2);
	trierMASS(t2,taille2);
	for(int i=0;i<taille2;i++)
		afficher(t2[i]);
	return 0;
}