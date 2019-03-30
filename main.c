# include "includes.h"
# include "bibli.h"

int main (int argc, char **argv){


    // VARIABLES D'ENTREE
    int longueur = 80, largeur = 80;
    int i=0;
    int pourcentRemplissage = 20;
    // ******* //
    int flagParameters = 0;
    char** array;
    int* gestionParametreIntegerArray;

    // 1ER PARAMETRE = EXECUTABLE

    gestionParametreIntegerArray = gestionDesParametresInteger(argc, argv);

    if(gestionParametreIntegerArray[5] == -1){
        return 0;
    }

    for(int i=0;i<6;i++){   // CA MARCHE
        printf("%d\n", gestionParametreIntegerArray[i]);
    }
    return 0;

    // NE PAS OUBLIER DE FREE LES TABLEAUX


    array = initialisation(longueur, largeur, pourcentRemplissage);     // INITIALISE LE TABLEAU AVEC LES PARAMETRES DONNE
    array = jouer(array, longueur, largeur);        // RENTRE DANS LE JEU

    // PARTIE POUR LIBERER L'ESPACE MEMOIRE

    for(i=0;i<longueur;i++){    
        free(array[i]);
    }

    free(*array);
    free(array);

    return 0;
}