#include <stdio.h>
#include <stdlib.h>
#include "Entreprise.h"
int main()
{
    int n;
    Membres_Personnels mb;
    
    Entreprise E;
    saisie_tab(E);
    affiche_tab(E);
    highsalary(E);
    femmes_str(E);
    infos_ing(E);
    printf("Masse salariale : %d\n",masse(E)) ;
    /*if(search_femme(E,&mb)){
        printf("La femme recherchée est :\n");
        affiche_employe(mb);
    }else
        printf("Femme non trouvée\n");*/
    Membres_Personnels *m=femme5(E);
    if(m==NULL)
        printf("Non trouvee ");
    else
        affiche_employe(*m);
    //free(E);
    return 0;
}
