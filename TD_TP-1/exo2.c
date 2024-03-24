#include <stdio.h>
#include <stdbool.h>

void cinq(float p1,float p2,float p3,float p4,bool p5){
	if(p1!=0 && p2!=0){
		p5=true;
		p3=p1 / p2;
		p4=p2 / p1;
		printf("Division reussie\n");
		printf("P3 = %d, P4 = %d\n",p3,p4);
	}else{
        p5=false;
        printf("Erreur\n");
	}
}

int main(){
	float v1,v2,v3,v4;
	bool test;
    printf("2 entiers ? ");
    scanf("%f %f",&v1,&v2);
	cinq(v1,v20,v3,v4,test);
	return 0;
}
