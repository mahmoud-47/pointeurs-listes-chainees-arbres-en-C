#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entreprise.h"

void affiche_employe(Membres_Personnels mb){
    printf("Prenom : %s\n",mb.prenom);
    printf("Nom : %s\n",mb.nom);
    printf("Sexe : %c\n",mb.sexe);
    printf("Fonction : %s\n",mb.fonction);
    printf("Experience : %d\n",mb.experience);
    printf("Salaire : %d\n",mb.salaire);
    printf("\n");
}

void saisie_tab(Entreprise e){
    printf("\n************ Saisie \n");
    for(int i=0;i<N;i++){
        printf("Prenom : ");
        scanf("%s",e[i].prenom);
        printf("Nom : ");
        scanf("%s",e[i].nom);
        do{
            printf("Sexe : ");
            scanf(" %c",&e[i].sexe);
        }while(e[i].sexe!='M' && e[i].sexe!='F');
        printf("Fonction : ");
        scanf("%s",e[i].fonction);
        printf("Experience : ");
        scanf("%d",&e[i].experience);
        printf("Salaire : ");
        scanf("%d",&e[i].salaire);
        printf("\n");
    }
}

void affiche_tab(Entreprise e){
    printf("\n********** Affichage \n");
    for(int i=0;i<N;i++)
        affiche_employe(e[i]);
}

void highsalary(Entreprise e){
    printf("\n*********** Les salaires supérieur à 300.000\n");
    for(int i=0;i<N;i++){
        if(e[i].salaire>300000)
            affiche_employe(e[i]);
    }
}

void femmes_str(Entreprise e){
    printf("\n************ Les femmes secretaires\n");
    for(int i=0;i<N;i++){
        if(e[i].sexe=='F' && !strcmp(e[i].fonction,"Secrétaire"))
            affiche_employe(e[i]);
    }
}

void infos_ing(Entreprise e){
    printf("\n************ Infos Ingenieurs\n");
    for(int i=0;i<N;i++){
        if(!strcmp(e[i].fonction,"Ingénieur"))
            affiche_employe(e[i]);
    }
}

int masse(Entreprise e){
    int s=0;
    for(int i=0;i<N;i++)
        s += e[i].salaire;
    return s;
}

/*int search_femme(Entreprise e,Membres_Personnels *mb){
    int i=0,trouve=0;
    while(i<N && !trouve)
        if(!strcmp(e[i].fonction,"Ingénieur") && e[i].sexe=='F' && e[i].experience>5){
            trouve = 1;
            *mb = e[i];
        }else
            i++;
    return trouve;
}*/
Membres_Personnels *femme5(Entreprise e){
    int i=0;
    while(i<N){
        if(!strcmp(e[i].fonction,"Ingénieur") && e[i].sexe=='F' && e[i].experience>5)
            return &e[i];
        i++;
    }
    return NULL;
}