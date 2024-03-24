#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    if(argc==3){
        int s = atoi(argv[1])+atoi(argv[2]);
        printf("la somme de %s et %s est %d\n",argv[1],argv[2],s);
    }
    return 0;
}