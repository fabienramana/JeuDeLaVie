# include "includes.h"
# include "bibli.h"

int main (int argc, char **argv){


    // VARIABLES D'ENTREE
    int longueur = 80, largeur = 80;
    int i=0;
    int pourcentRemplissage = 20;
    int alreadyInitialized = 0;
    // ******* //
    char** array;
    int* gestionParametresArray;


    gestionParametresArray = gestionDesParametres(argc, argv);

    if(gestionParametresArray[5] == -1){
        free(gestionParametresArray);
        return 0;
    }
    else{
        if(gestionParametresArray[7] == 1){
            return 0;   // SI AFFICHAGE DE L'AIDE
        }
        if(gestionParametresArray[0] != -1 && gestionParametresArray[1] != -1){
            longueur = gestionParametresArray[0];
            largeur = gestionParametresArray[1];
            printf("\nlongueur : %d", gestionParametresArray[0]);
            printf("\nlargeur : %d", gestionParametresArray[1]);
        }
        if(gestionParametresArray[2] != -1){
            pourcentRemplissage = gestionParametresArray[2];
            printf("\npourcentage de remplissage : %d\n", gestionParametresArray[2]);
        }
        if(gestionParametresArray[6] == 1){
            alreadyInitialized = 1;
        }
    }
    free(gestionParametresArray);

    if(alreadyInitialized == 0){
        array = initialisation(longueur, largeur, pourcentRemplissage);     // INITIALISE LE TABLEAU AVEC LES PARAMETRES DONNE
    }
    else{
        longueur = getSize(0); //RETOURNE LA LONGUEUR
        if(longueur == 0)
            return 0;
        largeur = getSize(1); //RETOURNE LA LARGEUR
        array = getArray(); // RETOURNE LE TABLEAU SAUVEGARDE
        printf("\nChargement bien effectué !\n\n");
    }
    array = jouer(array, longueur, largeur);        // RENTRE DANS LE JEU

    // PARTIE POUR LIBERER L'ESPACE MEMOIRE

    for(i=0;i<longueur;i++){    
        free(array[i]);
    }

    free(*array);
    free(array);

    return 0;
}