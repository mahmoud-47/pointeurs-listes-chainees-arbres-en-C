#include<stdio.h>
#include<stdlib.h>

typedef struct liste{
    int n;
    struct liste *next;
    struct liste *previous;
} *Liste;

void ajout_queue(Liste *l, int n){
    if(!*l){
        *l = (Liste)malloc(sizeof(struct liste));
        (*l) -> n = n;
        (*l) -> previous = NULL;
        (*l) -> next = NULL;
        return;
    }
    Liste q = *l,maillon;
    maillon = (Liste)malloc(sizeof(struct liste));
    maillon -> n = n; 
    maillon -> next = NULL;
    while(q -> next)
        q = q -> next;
    q -> next = maillon;
    maillon -> previous = q;
}

void display(Liste l){
    if(!l)
        printf("Vide\n");
    else{
        Liste q = l;
        while(q->next){
            printf("%d ",q->n);
            q = q->next;
        }
        while(q->previous){
            printf("%d ",q->n);
            q = q->previous;
        }
        printf("\n");
    }
}

int main(){
    Liste l=NULL;
    for(int i=0;i<5;i++)
        ajout_queue(&l,i);
    display(l);
    return 0;
}