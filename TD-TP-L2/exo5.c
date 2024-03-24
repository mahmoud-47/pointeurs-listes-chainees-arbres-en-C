#include<stdio.h> 
#include<ctype.h>
#include<stdlib.h>

typedef struct{
    char c;
    int occ;
} sta;

void statistiques(char phrase[],sta dict[]){
    char alpha[27]="abcdefghijklmnopqrstuvwxyz",c; int i; 
    for(i=0;i<26;i++){
        dict[i].c=alpha[i];
        dict[i].occ=0;
    }
    i=0;
    while(phrase[i]!='\0'){
        c = tolower(phrase[i++]);
        if(c>='a' && c<='z')
            dict[c-'a'].occ += 1;
    }
}

sta* statistiques1(char phrase[]){
    sta* dict = (sta*)malloc(26*sizeof(sta));
    char alpha[27]="abcdefghijklmnopqrstuvwxyz",c;
    sta *p;
    for(p=dict;p<dict+26;p++){
        (*p).c = alpha[p-dict];
        (*p).occ = 0;
    }
    char *pc=phrase;
    while(*pc != '\0'){
        c = tolower(*pc);
        if(c>='a' && c<='z')
            dict[(int)c-97].occ += 1;
        pc++;
    }
    return dict;
}

int anagramme(char c1[], char c2[]){
    sta dict1[26],dict2[26];
    statistiques(c1,dict1);
    statistiques(c2,dict2);
    int same=1,i=0;
    while(same && i<26)
        if(dict1[i].occ!=dict2[i].occ)
            same = 0;
        else
            i++;
    return same;
}

int anagramme1(char c1[], char c2[]){
    sta *dict1 = (sta*)malloc(26*sizeof(sta)),*dict2 = (sta*)malloc(26*sizeof(sta)),*p1,*p2;
    dict1 = statistiques1(c1);
    dict2 = statistiques1(c2);
    int same=1; p1=dict1; p2=dict2;
    while(same && p1<dict1+26)
        if((*p1).occ!=(*p2).occ)
            same = 0;
        else{
            p1++; p2++;
        }
    free(dict1); free(dict2);
    return same;
}

int main(){
    char chaine[20];
    sta* dict = (sta*)malloc(26*sizeof(sta));
    statistiques("Mohamed Gaye",dict);
    for(int i=0;i<26;i++)
        if(dict[i].occ)
            printf("%c:%d ",dict[i].c,dict[i].occ);
    printf("\n");
    dict = statistiques1("Mohamed Gaye");
    for(int i=0;i<26;i++)
        if(dict[i].occ)
            printf("%c:%d ",dict[i].c,dict[i].occ);
    printf("\n");
    printf("%d\n",anagramme1("alol OK ","aok ll o"));
    free(dict);
    return 0;
}