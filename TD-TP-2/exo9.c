#include<stdio.h>
#include<stdlib.h>

/*
n : nombre de disques utilisés
D : emplacement de départ
A : emplacement d'arrivée
I : emplacement intermédiaire
*/

void toursHanoi(int n, char D, char A, char I) {
    if (n == 1)
      printf("Disque 1 de %c a %c \n" , D , A);
    else {
      // D à A
      toursHanoi(n - 1, D, I, A);
      printf("Disque %d de %c a %c \n", n , D ,A);
      //I à A
      toursHanoi(n - 1, I, A, D);
    }
}

int main() {
    int nDisques = 3;
    toursHanoi(nDisques, 'A', 'C', 'B');
}