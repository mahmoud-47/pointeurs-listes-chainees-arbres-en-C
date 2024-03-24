#ifndef ENTREPRISE_H_INCLUDED
#define ENTREPRISE_H_INCLUDED

#define N 2
typedef struct{
    char prenom[50];
    char nom[20];
    char sexe;
    char fonction[25];
    unsigned int experience;
    int salaire;
} Membres_Personnels;

typedef Membres_Personnels Entreprise[N];

void saisie_tab(Entreprise e);
void affiche_tab(Entreprise e);
void highsalary(Entreprise e);
void femmes_str(Entreprise e);
void infos_ing(Entreprise e);
int masse(Entreprise e);
//int search_femme(Entreprise e,Membres_Personnels *mb); //renvoyer 1 si trouvé sinon 0; passage par adresse de la femme trouvée
Membres_Personnels *femme5(Entreprise e);
void affiche_employe(Membres_Personnels mb);

#endif // ENTREPRISE_H_INCLUDED
