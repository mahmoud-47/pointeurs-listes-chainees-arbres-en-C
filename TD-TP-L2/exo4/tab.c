#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

void affiche(int *t, int taille){
    int *p=NULL;
    for(p=t;p<t+taille;p++)
        printf("%d\t",*p);
    printf("\n");
}

int *saisie(int taille){
    int *t=(int*)malloc(taille*sizeof(int));
    for(int *p=t;p<t+taille;p++){
        printf("t[%ld] : ",p-t);
        scanf("%d",p);
    }    
    return t;
}

/*void ajout_fin(int *a, int *b, int *taille1, int taille2){
    int *p1 = a + *taille1, *p2 = b;
    (*taille1) += taille2;
    while(p2 < b+taille2)
        *(p1++) = *(p2++);
}*/
int *ajout_fin(int *a, int *b, int taille1, int taille2, int *taille3){
    int *p1, *p2;
    *taille3 = taille1 + taille2;
    int *c = (int*)malloc((*taille3)*sizeof(int));
    int *p = c;
    for(p1=a;p1<a+taille1;p1++){
        *p = *p1;
        p++;
    }
    for(p2=b;p2<b+taille2;p2++){
        *p = *p2;
        p++;
    }
    return c;
}

void del_occ(int *t, int *taille, int x){
    int *p1=t,*p2=NULL;
    while(p1 < t+*taille){
        if(*p1 == x){
            p2=p1;
            while( p2 < t+*taille-1 ){
                *(p2) = *(p2+1);
                p2++;
            }
            (*taille)--;
        }else  
            p1++; 
    }
}