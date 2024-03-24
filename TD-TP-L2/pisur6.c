#include<stdio.h>
#include <math.h>
int main(){
	float s=0;
	for(int i=0;i<20;i++){

		s = s + (float)(1.0/(i*i));
	}
	printf("%f\n",sqrt(s*6));
	return 0;
}