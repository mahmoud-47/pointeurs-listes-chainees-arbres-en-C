#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Seules les operators dans la pile
ex : a+b*c-d/e
on a ord(+)=ord(-)=1
    ord(*)=ord(/)=2
p = NULL; chaine ="";
a not symbol => append(chaine,a) {chaine="a"}
+ symbol  et p null => push(p,+) {p = + -> NULL}
b not symbol => append(chaine,b) {chaine="ab"}
* symbol p non nul et ord(*) = 2 > ord(sommet) = > push(p,*) {p = * -> + -> NULL}
c not symbol => append(chaine,c) {chaine="abc"}
- symbol et p non nul et ord(-) = 1 <= ord(sommet) = ord(*) = 2:
    append(chaine,pop(p)) {chaine="abc*"} {p = + -> NULL}
    symbol et p non nul et ord(-) = 1 <= ord(sommet) = ord(+) = 1:
        append(chaine,pop(p)) {chaine="abc*+"} {p = NULL}
    p nul => push(p,-) {chaine="abc*+"} {p = - -> NULL}
d not symbol => append(chaine,d) {chaine="abc*+d"}
/ symbol et p not nul et ord(/) = 2 > ord(sommet) = ord(-) = 1:
    push(p,/) {p = / -> - -> NULL}
e not symbol => append(chaine,e) {chaine="abc*+de"}
End of line:
    while(p)
        append(chaine,pop(p)); {chaine="abc*+de/-"}
return chaine;
*/

typedef struct pile{
    char c;
    struct pile *next;
} *Pile;

int symbole(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    return 0;
}

char ordr(char c){
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
}

Pile push(Pile p, char c){
    Pile temp = malloc(sizeof(struct pile));
    temp -> c = c;
    if(!p){
        temp -> next = NULL;
        return temp;
    }
    temp -> next = p;
    return temp;
}

char sommet(Pile p){
    if(!p)
        return -1;
    return p -> c;

}

char* append(char* chaine, char c){
    int i = strlen(chaine);
    chaine[i]=c;
    chaine[i+1]='\0';
    return chaine;
}

char pop(Pile *p){
    if(!*p)
        return -1;
    Pile pile = *p;
    char c = pile -> c;
    *p = (*p) -> next;
    free(pile);
    return c;
}

char* toPost(char *exp){
    Pile p=NULL; char c;
    char* post = malloc(30);
    int i = 0;
    while(exp[i]!='\0'){
        if(!symbole(exp[i]))
            append(post,exp[i++]);
        else{
            if(!p || ordr(sommet(p)) < ordr(exp[i]) ){
                p = push(p,exp[i++]);
            }else{
                while(p && ordr(sommet(p)) >= ordr(exp[i]) ){
                    c = pop(&p);
                    append(post,c);
                }
                p = push(p,exp[i]);
                i++;
            }
        }
    }
    while(p){
        c = pop(&p);
        append(post,c);
    }
    return post;
}

int main(){
    printf("%s\n",toPost("a+b*c-d/e"));
}