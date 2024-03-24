#include <stdio.h>
#include <stdlib.h>

void init(int ***m,int line, int col){
	printf("start");
	*m = (int**)malloc(line*sizeof(int*));
	printf("enter");
	if (m)*
													///
	{
		printf("in if");
		for(int i=0;i<line;i++)
			(*m)[i]=(int*)malloc(col*sizeof(int));
		for(int i=0;i<line;i++){
			for(int j=0;j<col;j++)
				(*m)[i][j] = 0;
				printf("in for");
	
		//printf("\n");
	}
	}
	
}

int main(){
	printf("Avant appel");
	int **m=NULL,line=3,col=4;

	init(&m,3,4);
	if(m==NULL)
		printf("kk");
	for(int i=0;i<line;i++){
			for(int j=0;j<col;j++)
				printf("%d ",m[i][j]);
			printf("\n");
	}	//free(m);
	return 0;
}