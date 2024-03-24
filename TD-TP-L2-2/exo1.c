#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

typedef struct{
	char *titre;
	char *auteur;
	char* mots_cles[N];
} Document;

Document* creer(char* auteur, char* titre, int nbkey, char keys[][15]){
	if(nbkey<0 || nbkey>N){
		printf("Debordement de capacité\n");
		return NULL;
	}
	Document *doc = (Document*)malloc(sizeof(Document));
	doc -> titre = malloc(strlen(titre)+1);
	doc -> auteur = malloc(strlen(auteur)+1);
	strcpy(doc -> titre, titre);
	strcpy(doc -> auteur, auteur);
	int i=0;
	while(i<nbkey){
		doc -> mots_cles[i] = malloc(sizeof(char)*strlen(keys[i]));
		strcpy(doc -> mots_cles[i],keys[i]);
		i++;
	}
	while(i<N){
		doc -> mots_cles[i] = NULL;
		i++;
	}
	return doc;
}

void affiche(Document doc){
	printf("Titre : %s\n",doc.titre);
	printf("auteur : %s\n",doc.auteur);
	printf("Mots Cles :\n");
	for(int i=0;i<N && doc.mots_cles[i]!=NULL;i++)
		printf("%s\n",doc.mots_cles[i]);
}

void detruire(Document **doc){
	for(int i=0;i<N && (**doc).mots_cles[i]!=NULL;i++)
		free((**doc).mots_cles[i]);
	free(*doc);
	*doc = NULL;
}

char *getTitre(Document *doc){
	return doc -> titre;
}

char *getMotCle(Document *doc, int i){
	return doc -> mots_cles[i];
}

void ajoutMotCle(Document *doc,char *mot){
	if( doc -> mots_cles[N-1] )
		printf("Plein\n");
	else{
		int i;
		for(i=0;i<N && doc -> mots_cles[i];i++);
		doc -> mots_cles[i] = (char*)malloc(sizeof(char)*strlen(mot));
		strcpy(doc -> mots_cles[i],mot);
	}
}

void copy(Document *dest, Document src){
	strcpy(dest -> titre, src.titre);
	strcpy(dest -> auteur, src.auteur);
	for(int i=0;i<N && src.mots_cles[i];i++){
		dest -> mots_cles[i] = (char*)malloc(sizeof(char)*strlen(src.mots_cles[i]));
		strcpy(dest -> mots_cles[i], src.mots_cles[i]);
	}
}

int motExiste(Document doc,char *mot){
	for(int i=0;i<N && doc.mots_cles[i];i++)
		if(!strcmp(doc.mots_cles[i],mot))
			return 1;
	return 0;
}

int main(int argc, char const *argv[]){
	char tab[N][15]={
		"Sidi",
		"Rama",
		"Ansou"
	};
	Document *doc = creer("Toto","tata",3,tab);
	Document *doc1 = creer("1","2",0,tab);
	ajoutMotCle(doc,"Tata");
	ajoutMotCle(doc,"Tata1");
	ajoutMotCle(doc,"Tata2");
	ajoutMotCle(doc,"Tata3");
	copy(doc1,*doc);
	affiche(*doc1);
	printf("%d\n",motExiste(*doc,"Tata3"));
	detruire(&doc);
	return 0;
}