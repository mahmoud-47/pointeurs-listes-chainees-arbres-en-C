#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
    int jour;
    int mois;
    int annee;
}DATEDENAISSANCE;
typedef struct {
    char nom[20];
    char prenom[50];
    DATEDENAISSANCE DAN;
    char classe[4];
    float NOTE_CONTROLE;
    float NOTE_TP;
    float NOTE_EXAM;
    float MOYENNE;
    }ETUDIANT;
typedef ETUDIANT TAB_ETUDIANT[300];
typedef ETUDIANT TAB_ETUDIANT_MASS[400];
typedef FILE *FIC_ETUDIANT ;
void saisirEtudiant(ETUDIANT *etudiant){
        printf("NOM :");
        scanf("%s",etudiant->nom);
        printf("PRENOM :");
        scanf("%s",etudiant->prenom);
        printf("DATE DE NAISSANCE :");
        scanf("%d",&etudiant->DAN.jour);
        scanf("%d",&etudiant->DAN.mois);
        scanf("%d",&etudiant->DAN.annee);
        printf("CLASSE");
        scanf("%s",etudiant->classe);
        printf("NOTE DE CONTROLE :");
        scanf("%f",&etudiant->NOTE_CONTROLE);
        printf("NOTE DE TP :");
        scanf("%f",&etudiant->NOTE_TP);
        printf("NOTE D'EXAM :");
        scanf("%f",&etudiant->NOTE_EXAM);
}
void saisirTabEtudiant(TAB_ETUDIANT T,int n){
    for(int i=0;i<n;i++){
        printf("L'Etudiant N %d :\n",i+1);
        saisirEtudiant(&T[i]);
    }
}
void calculermoyenne(TAB_ETUDIANT T,int n){
    for(int i=0;i<n;i++){
        T[i].MOYENNE=(T[i].NOTE_CONTROLE+T[i].NOTE_TP+2*T[i].NOTE_EXAM)/4;
        printf("Son note est :%f\n",T[i].MOYENNE);
    }
}
void creerFicEtudiant(TAB_ETUDIANT T,int n,char *filename){
    FIC_ETUDIANT INFORMATION = fopen(filename,"w");
    for(int j=0;j<n;j++){

        fprintf(INFORMATION,"%s %s %d %d %d %s %f %f %f %f\n",T[j].nom,T[j].prenom,T[j].DAN.jour,T[j].DAN.mois,T[j].DAN.annee,T[j].classe,T[j].NOTE_CONTROLE,T[j].NOTE_TP,T[j].NOTE_EXAM,T[j].MOYENNE);
    }
    fclose(INFORMATION);
}
int extraireMASS (TAB_ETUDIANT_MASS tabMass,int n, char *filename){
    FIC_ETUDIANT MASSIEN=fopen(filename,"r");
    int i=0;
    while(fscanf(MASSIEN,"%s %s %d %d %d %s %f %f %f %f\n",tabMass[i].nom,tabMass[i].prenom,&tabMass[i].DAN.jour,&tabMass[i].DAN.mois,&tabMass[i].DAN.annee,tabMass[i].classe,&tabMass[i].NOTE_CONTROLE,&tabMass[i].NOTE_TP,&tabMass[i].NOTE_EXAM,&tabMass[i].MOYENNE)!=EOF){
        if(strcmp(tabMass[i].classe,"MASS")==0)
            i++;
    }
   fclose(MASSIEN);
   return i;
}
void affectation(ETUDIANT *A,ETUDIANT B){
    strcpy(A->nom,B.nom);
    strcpy(A->prenom,B.prenom);
    A->DAN.jour=B.DAN.jour;
    A->DAN.mois=B.DAN.mois;
    A->DAN.annee=B.DAN.annee;
    strcpy(A->classe,B.classe);
    A->NOTE_CONTROLE=B.NOTE_CONTROLE;
    A->NOTE_TP=B.NOTE_TP;
    A->NOTE_EXAM=B.NOTE_EXAM;
    A->MOYENNE=B.MOYENNE;
}
void trierMASS (TAB_ETUDIANT_MASS tabMass,int n){
    int i,j,imax;
    ETUDIANT X;
    for(i=0;i<n;i++){
        imax=i;
        for(j=i;j<n;j++){
            if(tabMass[imax].MOYENNE<tabMass[j].MOYENNE)
                imax=j;
        }
        affectation(&X,tabMass[imax]);
        affectation(&tabMass[imax],tabMass[i]);
        affectation (&tabMass[i],X);
    }
}
int main(){
    int a=5;
    char Monfichier[30];
    TAB_ETUDIANT E;
    TAB_ETUDIANT_MASS Y;
    /*printf("Entrez la taille :");
    scanf("%d",&a);
    saisirTabEtudiant(E,a);
    calculermoyenne(E,a);
    printf("Entrez le nom du fichier: ");
    scanf("%s",Monfichier);
    creerFicEtudiant(E,a,Monfichier);*/
    int l;
    l=extraireMASS(Y,a,"test11.txt");
    for(int p=0;p<l;p++){
        
        printf("Y[%d]",p+1);
        printf("%f\n",Y[p].NOTE_EXAM);
    }
    trierMASS(Y,l);
    printf("Le tableau deja trie est la suivante :");
    for(int p=0;p<l;p++){
        
        printf("Y[%d]",p+1);
        printf("%f\n",Y[p].NOTE_EXAM);
    }

    return 0;
}
