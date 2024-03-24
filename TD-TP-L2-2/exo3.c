#include<stdio.h>
#include<stdlib.h>

typedef struct liste{
    int n;
    struct liste *next;
} *Liste;

void ajout(Liste *l, int n){
    if(!*l){
        *l = (Liste)malloc(sizeof(struct liste));
        (*l) -> n = n;
        (*l) -> next = NULL;
        return ;
    }
    Liste q = *l;
    while(q -> next)
        q = q -> next;
    
    q -> next = (Liste)malloc(sizeof(struct liste));
    q -> next -> n = n;
    q -> next -> next = NULL;
}

void ajout_tri(Liste *l, int n){
    if(!*l){
        ajout(l,n);
        return;
    }
    //si la liste n est pas null on declare le nouveau maillon 
    Liste q,maillon,previous;
    maillon = (Liste)malloc(sizeof(struct liste));
    maillon -> n = n;
    //si on doit l'inserer au niveau du premier element
    if(n <= (*l)->n){
        maillon -> next = *l;
        *l = maillon;
        return;
    }
    //si l'insertion n est pas au premier element
    q = *l;
    while(q){
        if(n < q->n)
            break;
        previous = q;
        q = q -> next;
    }
    //si q est null alors on inserer à la queue sinon on fait autrement
    if(!q){
        maillon -> next = NULL;
        previous -> next = maillon;
        return;
    }
    //si q n est pas null on insere le nouveau maillon 
    maillon -> next = q;
    previous -> next = maillon;
}

void display(Liste l){
    if(!l)
        printf("Vide\n");
    else{
        Liste q = l;
        while(q){
            printf("%d",q->n);
            if(q->next)
                printf(" -> ");
            q = q->next;
        }
        printf("\n");
    }
}

Liste search(Liste l, int n){
    if(!l)
        return NULL;
    Liste q = l;
    while(q){
        if(q -> n == n)
            return q;
        q = q -> next;
    }
    return NULL;
}

Liste reverse(Liste l){
    Liste previous=NULL,next=NULL;
    while(l){
        next = l -> next;
        l -> next = previous;
        previous = l;
        l = next;
    }
    return l;
}

void listcat(Liste *l1, Liste l2){
    if(!*l1)
        *l1 = l2;
    else{
        Liste q = *l1;
        while(q -> next)
            q = q-> next;
        q -> next = l2;
    }
}

void del_first(Liste *l, int n){
    if(!*l)
        return;
    Liste q,previous;
    //si l'element à supprimer est à la tête
    if( (*l)->n == n){
        q = *l;
        *l = (*l) -> next;
        free(q);
        return;
    }
    //si l'element à supprimer n'est pas à la tête
    q = *l;
    while(q){
        if(q -> n == n)
            break;
        previous = q;
        q = q -> next;
    }
    //si on a un element à supprimer
    if(q){
        previous -> next = q -> next;
        free(q);
    }
}

void del_all(Liste *l, int n){
    while(search(*l,n))
        del_first(l,n);
}

void copy(Liste *l1, Liste l2){
    Liste q = *l1, q2=l2,temp;
    //liberer la liste 1
    while(q){
        temp = q;
        q = q -> next;
        free(temp);
    }
    *l1 = NULL;
    while(q2){
        ajout(l1,q2 -> n);
        q2 = q2 -> next;
    }
}

void copy_rev(Liste *l1, Liste l2){
    Liste maillon, q = *l1, q2 = l2, temp;
    //liberer la liste 1
    while(q){
        temp = q;
        q = q -> next;
        free(temp);
    }
    *l1 = NULL;
    //ajout en tête
    while(q2){
        maillon = (Liste)malloc(sizeof(struct liste));
        maillon -> n = q2 -> n;
        maillon -> next = *l1;
        *l1 = maillon;
        q2 = q2 -> next;
    }
}

int main(){
    Liste test=NULL,test2=NULL;
    int n;
    for(int i=0;i<10;i++){
        ajout(&test,i);
        display(test);
    }
    for(int i=0;i<5;i++){
        printf(">>> ");
        scanf("%d",&n);
        ajout_tri(&test2,n);
        display(test2);
    }
    //listcat(&test,test2);
    //display(test);
    //del_first(&test,1);
    //del_all(&test2,5);
    copy_rev(&test,test2);
    display(test);
    test = reverse(test);
    display(test);
    return 0;
}