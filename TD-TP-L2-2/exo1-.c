#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

typedef struct{
	char *titre;
	char *auteur;
	char *mots_cles[N];
} Document;

Document* creer(char* auteur, char* titre){
	Document *doc = (Document*)malloc(sizeof(Document));
	doc -> titre = (char*)malloc(strlen(titre)+1);
	doc -> auteur = (char*)malloc(strlen(auteur)+1);
	if(!doc -> titre || !doc -> auteur)
		return NULL;
	strcpy(doc -> titre, titre);
	strcpy(doc -> auteur, auteur);
	for(int i=0;i<7;i++)
		doc -> mots_cles[i] = NULL;
	return doc;
}

void affiche(Document doc){
	printf("Titre : %s\n",doc.titre);
	printf("auteur : %s\n",doc.auteur);
	printf("Mots Cles :\n");
	for(int i=0;i<N && doc.mots_cles[i]!=NULL;i++)
		printf("%s\n",doc.mots_cles[i]);
}

Document* detruire(Document *doc){
	for(int i=0;i<N && doc->mots_cles[i]!=NULL;i++)
		free(doc->mots_cles[i]);
	if(doc->titre)
		free(doc->titre); 
	if(doc->auteur)
		free(doc->auteur);
	free(doc);
	return NULL;
}

char *getTitre(Document doc){
	if(!doc.titre)
		return NULL;
	char *s = (char*)malloc(strlen(doc.titre)+1);
	strcpy(s,doc.titre);
	return s;
}

char *getMotCle(Document doc, int i){
	if(i<1 || i>7 || !doc.mots_cles[i-1])
		return NULL;
	char *s = (char*)malloc(strlen(doc.mots_cles[i-1])+1);
	strcpy(s,doc.mots_cles[i-1]);
	return s;
}

void ajoutMotCle(Document *doc,char *mot){
		int i;
		for(i=0;i<N && doc -> mots_cles[i];i++);
		if(i==N)
			printf("Plein\n");
		else{
			doc -> mots_cles[i] = (char*)malloc(strlen(mot)+1);
			if(doc -> mots_cles[i])
				strcpy(doc -> mots_cles[i],mot);
		}
}

Document* copy(Document src){
	Document* d = creer(src.titre, src.auteur);
	int i=0;
	while(i<N && src.mots_cles[i]){
		ajoutMotCle(d,src.mots_cles[i]);
		i++;
	}
	return d;
}

int motExiste(Document doc,char *mot){
	for(int i=0;i<N && doc.mots_cles[i];i++)
		if(!strcmp(doc.mots_cles[i],mot))
			return 1;
	return 0;
}

int main(int argc, char const *argv[]){
	Document *doc = creer("Toto","tata");
	Document *doc1 = creer("1","2");
	ajoutMotCle(doc,"Tata");
	ajoutMotCle(doc,"Tata1");
	ajoutMotCle(doc,"Tata2");
	ajoutMotCle(doc,"Tata3");
	doc1 = copy(*doc);
	affiche(*doc1);
	printf("%d\n",motExiste(*doc,"Tata3"));
	if(getMotCle(*doc,1))
		printf("%s\n",getMotCle(*doc,1));
	doc = detruire(doc);
	doc = detruire(doc1);
	return 0;
}