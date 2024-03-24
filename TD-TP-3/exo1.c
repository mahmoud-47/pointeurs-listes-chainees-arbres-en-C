#include<stdio.h>

void afficher(int t[],int n){
	if(n==1){
		printf("%d\t",t[0]);
	}else{
		afficher(t,n-1);
		printf("%d\t",t[n-1]);
	}
}

void permuter(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void bulle(int t[],int n){
	int dernier=n-2;
	while(dernier>=0){
		for(int i=0;i<=dernier;i++)
			if(t[i]>t[i+1])
				permuter(&t[i],&t[i+1]);
		dernier--;	
	}
}

void selection(int t[],int n){
	int imin,i,j;
	for(i=0;i<n-1;i++){
		imin=i;
		for(int j=i+1;j<n;j++)
			if(t[j]<t[imin])
				imin=j;
		permuter(&t[imin],&t[i]);
	}
}

void insertion(int t[],int n){
	int x,j;
	for(int i=1;i<n;i++){
		j=i; x=t[i];
		while(j>0 && t[j-1]>x){
			t[j]=t[j-1];
			j--;
		}
		t[j]=x;
	}
}

void tri_fusion(int t[],int g,int d){
	if(g<d){
		int m=(g+d)/2;
		tri_fusion(t,g,m);
		tri_fusion(t,m+1,d);	

		int i=g,j=m+1,k=i,temp[10];
		while(i<=m && j<=d)
			if(t[i]<t[j])
				temp[k++]=t[i++];
			else
				temp[k++]=t[j++];
		
		while(i<=m)
			temp[k++]=t[i++];
		while(j<=d)
			temp[k++]=t[j++];
		for(i=g;i<=d;i++)
			t[i]=temp[i];
	}
}

void tri_rapide(int t[],int g,int d){
	int i=g,j=d,m=t[(g+d)/2];
	do{
		while(t[i]<m) i++;
		while(t[j]>m) j--;
		if(i<=j){
			permuter(&t[i],&t[j]);
			i++; j--;
		}
	}while(i<j);
	if(g<j) tri_rapide(t,d,j);
	if(d>i) tri_rapide(t,i,d);
}

int main(){
	int tab[9]={10,9,8,7,6,5,4,3,2};
	//bulle(tab,9);
	//selection(tab,9);
	//insertion(tab,9);
	//tri_fusion(tab,0,8);
	tri_rapide(tab,0,9);
	afficher(tab,9);
	printf("\n");
}