#include <stdio.h>
#include <ctype.h>

void transfo_en_maj(char minus[],char maj[]){
	int i;
	for(i=0;minus[i]!='\0';i++)
		maj[i]=toupper(minus[i]);
	maj[i]='\0';
}

int main(){
	char v1[10],v2[10];
	scanf("%[^\n]",v1);
	transfo_en_maj(v1,v2);
	printf("%s - %s\n",v1,v2 );
}