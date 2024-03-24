#include <stdio.h>
#include <stdlib.h>

void init(int **m,int line, int col){
	m = (int**)malloc(line*sizeof(int*));
	for(int i=0;i<line;i++)
		m[i]=(int*)calloc(col,sizeof(int));
}

int main(){
	int **m=NULL,line=3,col=4;
	init(m,3,4);

	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}
	free(m);
	return 0;
}
