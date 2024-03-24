#include<stdio.h>
#include<stdlib.h>

typedef struct pile{
    char c;
    struct pile *next;
} *Pile;

int isEmpty(Pile p){
    if(p)
        return 0;
    return 1;
}

Pile push(Pile p, char c){
    Pile pile = (Pile)malloc(sizeof(struct pile));
    pile -> c = c;
    if(!p){
        pile -> next = NULL;
        return pile;
    }
    pile -> next = p;
    p = pile;
    return p;
}

char pop(Pile *p){
    if(isEmpty(*p))
        return -1;
    Pile pile = *p;
    *p = (*p) -> next;
    char c = pile -> c;
    free(pile);
    return c;
}

int eval(char* chaine){
    int i=0; char x;
    Pile p = NULL;
    while(chaine[i]!='\0'){
        if(chaine[i]=='(')
            p = push(p, chaine[i]);
        if(chaine[i]==')'){
            x = pop(&p);
            if(x==-1)
                return 0;
        }
        i++;
    }
    return isEmpty(p);
}

int main(){
    char test[20];
    printf("Expression >>> ");
    scanf("%s",test);
    printf("%d\n",eval(test));
    return 0;
}