#include <stdio.h>
#include "tab.h"
int main(){
    int *a,*b,i=3,j=4,x;
    int *c=NULL,k;
    printf("Saisie de A \n");
    a = saisie(i);
    printf("Saisie de B \n");
    b = saisie(j);
    c = ajout_fin(a,b,i,j,&k);
    printf("affichage de C \n");
    affiche(c,k);
    printf("Element à supprimer ? ");
    scanf("%d",&x);
    del_occ(c,&k,x);
    printf("affichage de C apres suppression\n");
    affiche(c,k);
    return 0;
}