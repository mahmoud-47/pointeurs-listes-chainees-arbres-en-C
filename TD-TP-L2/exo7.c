#include <stdio.h>
#include <stdlib.h>

float **creation_matrice(int line, int col){
	float **m = (float**)malloc(line*sizeof(float*));
	if(m==NULL)
		exit(1);
	for(int i=0;i<line;i++){
		m[i]=(float*)malloc(col*sizeof(float));
		for(int j=0;j<col;j++)
			m[i][j]=0;
	}
	return m;
}

void saisie_mat(float **m,int line, int col){
	for(int i=0;i<line;i++){
		for(int j=0;j<col;j++){
			printf("M(%d,%d) = ",i,j);
			scanf("%f",&m[i][j]);
		}
	}
}

void **detruire(float ***m,int line){
	for(int i=0;i<line;i++)
		free((*m)[i]);
	free(*m);
	*m= NULL;
}

void affichage(float **m,int line,int col){
	if(!m){
		printf("| NULL |\n");
		return;
	}
	printf("\n");
	for(int i=0;i<line;i++){
		printf("| ");
		for(int j=0;j<col;j++)
			printf("%5.1f",m[i][j]);
		printf(" |\n");
	}
}

float **prod(float **m1,int l1,int c1,float **m2,int l2,int c2,int *newL,int *newC){
	if(c1!=l2){
		*newL = 0;
		*newC = 0;
		return NULL;
	}

	float **p = NULL;
	int sum;*newL = l1;*newC = c2;
	p = creation_matrice(*newL,*newC);
	
	for(int k=0;k<l1;k++){
		for(int i=0;i<c2;i++){
			sum = 0;
			for(int j=0;j<c1;j++)
				sum += m1[k][j]*m2[j][i];
			p[k][i]=sum;
		}
	}
	return p;
}

float **prod_reel_mat(float **m,float line,float col,float x){
	float **p = creation_matrice(line,col);
	for(int i=0;i<line;i++)
		for(int j=0;j<col;j++)
			p[i][j] = m[i][j] * x;
	return p;
}

float **trans(float **m,int line,int col,int *newL,int *newC){
	float **t=NULL,temp;
	temp = *newL; *newL = *newC; *newC = temp;
	t = creation_matrice(line,col);
	for(int i=0;i<line;i++)
		for(int j=0;j<col;j++)
			t[j][i]=m[i][j];
	return t;	
}

float main(){
	float **m1 = creation_matrice(3,4);
	float **m2 = m1;
	detruire(&m1,3);
	affichage(m2,3,4);
	/*float **m=NULL;
	int line=2,col=2,lp,cp,k;

	m = creation_matrice(line,col);
	printf("\nSaisie Matrice 1\n");
	saisie_mat(m,line,col);
	affichage(m,line,col);

	int l2=2,c2=2;
	float **m2=creation_matrice(l2,c2); 
	
	affichage(m2,l2,c2);
	printf("\nSaisie Matrice 2\n");
	saisie_mat(m2,l2,c2);
	float **prodm=prod(m,line,col,m2,l2,c2,&lp,&cp);
	
	printf("\nProduit M1*M2\n");
	affichage(prodm,lp,cp);

	printf("Donner un entier à multiplier ");
	scanf("%d",&k);
	float **prodk=prod_reel_mat(m,line,col,k);
	printf("\nProduit M1*%d\n",k);
	affichage(prodk,col,line);

	m = detruire(m,line);
	m2 = detruire(m2,l2);
	prodm = detruire(prodm,lp);
	prodk = detruire(prodk,lp);*/
	return 0;
}

