
#include "bibli.h"
#include "includes.h"

char** jouer(char** array, int longueur, int largeur){
    int entree = 0;
    int nbr_de_tours = 1;
    // FLAG
    int flagArrayToCopyIn = 0;  // SI 0 -> array = principal, si 1 -> clonedArray = principal


    char** clonedArray = (char**) malloc(sizeof(char*) * longueur);   // NE PAS OUBLIER DE FREE
    for(int i=0;i<longueur; i++){
        clonedArray[i] = (char*) malloc(sizeof(char) * largeur);
    }
    

    printf("Nous allons pouvoir commencer ! \n");

    do {    
        printf("Tour n %d : ", nbr_de_tours);
        printf("\n\n");

        if(flagArrayToCopyIn == 0){
            clonedArray = copier(array, clonedArray, longueur, largeur);
            clonedArray = iterationDuJeu(array, clonedArray, longueur, largeur);
            afficherTableau(clonedArray, longueur, largeur);
            flagArrayToCopyIn = 1;
        }
        else{
            array = copier(clonedArray, array, longueur, largeur);
            array = iterationDuJeu(clonedArray, array, longueur, largeur);
            afficherTableau(array, longueur, largeur);
            flagArrayToCopyIn = 0;
        }

        printf("\n Voulez vous continuer ? : ");
        scanf("%d", &entree);
        printf("\n\n");
        printf("%d", entree);
        printf("\n\n");
        nbr_de_tours++;

    }while(entree != 0); 



    if(flagArrayToCopyIn == 1){
        
        for(int i=0;i<longueur;i++){
            free(array[i]);
        }

        free(*array);
        free(array);
        printf("Au revoir ! \n");
        return clonedArray;
    }
    else if(flagArrayToCopyIn == 0){

        for(int i=0;i<longueur;i++){
            free(clonedArray[i]);
        }

        free(*clonedArray);
        free(clonedArray);
        printf("Au revoir ! \n");
        return array;
    }

    return array; // FAUX RETURN 
}