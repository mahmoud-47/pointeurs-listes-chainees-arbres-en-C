/*
Table d'association
-Création table vide
-put(cle,val)
-get(cle)-> valeur
-remove(cle) supprime une paire
-contains(cle) 
-size() : nombre de paires dans le tableau
-isEmpty()
*/
/*
    Attention !
    Put : avant de faire previous -> next , verifier d abord si l'element n'est pas le premier 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char *cle;
    char *val;
} Association;

typedef struct liste{
    Association a;
    struct liste *next;
} *Liste;

Liste creation(){
    return NULL;
}

void put(Liste *l, char *cle, char *val){
    if(*l == NULL){
        *l = (Liste)malloc(sizeof(struct liste));
        (*l) -> a.cle = (char*)malloc(strlen(cle)+1);
        strcpy( (*l) -> a.cle,cle);
        (*l) -> a.val = (char*)malloc(strlen(val)+1);
        strcpy( (*l) -> a.val,val);
        (*l) -> next = NULL;
    }else{
        Liste q = *l, previous;
        while(q){
            if(strcmp(q -> a.cle,cle)==0)
                break;
            previous = q;
            q = q -> next;
        }
        //si la clé n'existe pas deja
        if(q == NULL){ 
            Liste maillon = (Liste)malloc(sizeof(struct liste));
            maillon -> a.cle = (char*)malloc(strlen(cle)+1);
            strcpy(maillon -> a.cle, cle);
            maillon -> a.val = (char*)malloc(strlen(val)+1);
            strcpy(maillon -> a.val, val);
            maillon -> next = NULL;
            previous -> next = maillon;
        }else{
            //si la cle existe deja
            /*
            //mise à jour
            q -> a.val = (char*)realloc(q -> a.val, strlen(val)+1);
            strcpy(q -> a.val, val);
            */
            printf("La clé existe deja\n");
        }
    }
}

char* get(Liste l,char* cle){
    if(!l)
        return NULL; 
    Liste q = l;
    while(q){
        if(strcmp(q -> a.cle, cle)==0){
            char *ret = (char*)malloc(strlen(q -> a.val)+1);
            strcpy(ret, q -> a.val);
            return ret;
        }
        q = q -> next;
    }
    return NULL;
}

void display(Liste l){
    if(l==NULL)
        printf("{}\n");
    else{
        Liste q = l;
        printf("{");
        while(q){
            printf("\"%s\":\"%s\",",q -> a.cle, q -> a.val);
            q = q -> next;
        }
        printf("\b}\n");
    }
}

void Remove(Liste *l,char* cle){
    if(!*l)
        return;
    Liste q = *l, previous;
    //si c est le premier element
    if( strcmp((*l)->a.cle, cle)==0 ){
        q = *l;
        *l = (*l) -> next;
        free(q -> a.cle);
        free(q -> a.val);
        free(q);
    }else{
        //si ce n est pas le premier element
        while(q){
            if( !strcmp(q -> a.cle, cle) )
                break;
            previous = q;
            q = q -> next;
        }
        previous -> next = q -> next;
        free(q -> a.cle);
        free(q -> a.val);
        free(q);
    }
}

int contains(Liste l, char* cle){
    if(l==NULL)
        return 0;
    if(!strcmp(l -> a.cle,cle))
        return 1;
    return contains(l -> next, cle);
}

int size(Liste l){
    if(l==NULL)
        return 0;
    return 1 + size(l -> next);
}

int isEmpty(Liste l){
    if(l)
        return 0;
    return 1;
}

int main(){
    fprintf(stderr,"toto\n");
    return 0;
}