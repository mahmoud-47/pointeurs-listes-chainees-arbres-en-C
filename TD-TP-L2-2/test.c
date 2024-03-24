#include<stdio.h>
int main(){
    int i=2;
    int j = i + (1,2,3,4,9);
    printf("%d\n",j);
    return 0;
}
/*j 3
k 1
i -3
m 1
-3 3 1 1*/