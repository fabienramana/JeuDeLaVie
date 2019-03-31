# include "includes.h"
# include "bibli.h"

int main (int argc, char **argv){


    // VARIABLES D'ENTREE
    int longueur = 80, largeur = 80;
    int i=0;
    int pourcentRemplissage = 20;
    // ******* //
    //int flagParameters = 0;
    char** array;
    int* gestionParametreIntegerArray;

    // 1ER PARAMETRE = EXECUTABLE

    gestionParametreIntegerArray = gestionDesParametresInteger(argc, argv);

    if(gestionParametreIntegerArray[5] == -1){
        // FREE ICI AUSSI
        return 0;
    }
    else{
        if(gestionParametreIntegerArray[0] != -1 && gestionParametreIntegerArray[1] != -1){
            longueur = gestionParametreIntegerArray[0];
            printf("\nlongueur : %d", gestionParametreIntegerArray[0]);
            largeur = gestionParametreIntegerArray[1];
            printf("\nlargeur : %d", gestionParametreIntegerArray[1]);
        }
        if(gestionParametreIntegerArray[2] != -1){
            pourcentRemplissage = gestionParametreIntegerArray[2];
            printf("\npourcent : %d\n", gestionParametreIntegerArray[2]);
        }
    }
   
        // TEST POUR FREE LE TABLEAU //
    /*for(int i=0;i<6;i++){
       free(gestionParametreIntegerArray[i]);
   }
    free(*gestionParametreIntegerArray);
    free(gestionParametreIntegerArray);

    printf("\nlongueur : %d", longueur);
    printf("\nlargeur : %d", largeur);
    printf("\npourcent : %d", pourcentRemplissage);

    return 0; */

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