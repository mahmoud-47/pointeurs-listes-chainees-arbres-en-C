#include<stdio.h>
#include<stdlib.h>

typedef struct pile{
    char c;
    struct pile *next;
} *Pile;

int isEmpty(Pile p){
    if(!p)
        return 1;
    return 0;
}

Pile push(Pile p, char c){
    Pile pile = (Pile)malloc(sizeof(struct pile));
    pile -> c = c;
    if(!p){
        pile -> next = NULL;
        return pile;
    }
    pile -> next = p;
    return pile;
}

int similar(char left, char right){
    if(left=='{' && right=='}')
        return 1;
    if(left=='(' && right==')')
        return 1;
    if(left=='[' && right==']')
        return 1;
    return 0;
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

int eval(char *chaine){
    int i=0; char x;
    Pile p=NULL;
    while(chaine[i]!='\0'){
        if(chaine[i]=='(' || chaine[i]=='[' || chaine[i]=='{')
            p = push(p, chaine[i]);
        if(chaine[i]==')' || chaine[i]==']' || chaine[i]=='}'){
            x = pop(&p);
            if(x==-1 || !similar(x,chaine[i]))
                return 0;
        }
        i++;
    }
    return isEmpty(p);
}

int main(){
    char test[30];
    printf("Expression >>> ");
    scanf("%s",test);
    printf("%d\n",eval(test));
    return 0;
}