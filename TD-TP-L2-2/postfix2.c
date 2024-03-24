#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
operators et operandes dans la pile
ex : a+b*c-d/e
on a ord(+)=ord(-)=1
    ord(*)=ord(/)=2
    ord(a)=ord(b)=ord(c)=3
p = NULL; chaine ="";
a : ord(a)=3 et p nul => push (p,a) {chaine=""} {p = a -> NULL}
+ : p non nul et ord(+)=2 <= ord(sommet) = ord(a) = 3:
    append(chaine,pop(p)) {chaine="a"} {p = NULL}
    push(p,+) {chaine="a"} {p = + -> NULL}
b: p non nul et ord(b) = 3 > ord(sommet) = ord(+) = 2:
    push(p,b) {chaine="a"} {p = b -> + -> NULL}
* : p non nul ord(*)=2 <= ord(sommet) = ord(b) = 3:
    append(chaine,pop(p)) {chaine="ab"} {p = + -> NULL}
    p non nul ord(*)=2 > ord(sommet) = ord(+) = 1:
        push(p,*) {chaine="ab"} {p = * -> + -> NULL}
c : ord(c) = 3 p non nul et ord(c) > ord(sommet) = ord(*) = 2:
    push(p,c) {chaine="ab"} {p = c -> * -> + -> NULL}
- : p non nul et ord(-) <= ord(sommet) = ord(c) = 3 :
        append(chaine,pop(p)) {chaine="abc"} {p = * -> + -> NULL}
    p non nul et ord(-) <= ord(sommet) = ord(*) = 2 :
        append(chaine,pop(p)) {chaine="abc*"} {p = + -> NULL}
    p non nul et ord(-) <= ord(sommet) = ord(+) = 1 :
        append(chaine,pop(p)) {chaine="abc*+"} {p = NULL}
    p nul :
        push(p,-) {chaine="abc*+"} {p = - -> NULL}
d : p non nul et ord(d)=3 > ord(sommet) = ord(-) = 1:
    push(p,d) {chaine="abc*+"} {p = d -> - -> NULL}
/ : p non nul et ord(/)=2 <= ord(sommet) = ord(d) = 3:
    append(chaine,pop(p)) {chaine="abc*+d"} {p = - -> NULL}
    p non nul et ord(/)=2 > ord(sommet) = ord(-) = 1:
        push(p,/) {chaine="abc*+d"} {p = / -> - -> NULL}
e : p non nul et ord(e)=3 > ord(sommet) = ord(/) = 2:
    push(p,e) {chaine="abc*+d"} {p = e -> / -> - -> NULL}
end :
    while(p)
        append(chaine,pop(p)) {chaine="abc*+de/-"} {p = NULL}
*/

typedef struct pile{
    char c;
    struct pile *next;
} *Pile;

char ordr(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 3;
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
        if(!p || ordr(exp[i])>ordr(sommet(p)) )
            p = push(p,exp[i++]);
        else{
            while(p && ordr(exp[i])<=ordr(sommet(p))){
                c = pop(&p);
                append(post,c);
            }
            p = push(p,exp[i++]);
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
    printf("%s\n",toPost("3*5+6/2-4"));
}