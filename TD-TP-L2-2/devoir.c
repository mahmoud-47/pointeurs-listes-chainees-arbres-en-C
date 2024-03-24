#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const char *a, const char *b){
	while(*a){
		if(*a != *b)
			return *a-*b;
		a++; b++;
	}	
	return *a-*b;
}

void cpy(char *dest,const char *src){
	while( (*dest++=*src++) !='\0');
}

void scat(char *dest,const char *src){
	while(*dest)
		dest++;

	while((*dest++=*src++) != '\0');
}

int main(int argc, char const *argv[])
{
	char c1[10];
	strcpy(c1,"titi");
	scat(c1,"toto");
	printf("%s\n",c1);
	printf("%d\n",cmp("tatz","tatza"));
	return 0;
}