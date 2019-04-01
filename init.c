
#include "includes.h"

// CREER FONCTION TRAITEMENT DES PARAMETRES D'ENTREE

int rand_a_b(int a, int b){
    return rand()%(b-a) + a;
}

char** initialisation(int longueur, int largeur, int pourcentRemplissage){
    int i =0, j= 0, cpt = 0, rankOfI = 0, rankOfJ = 0;
    srand(time(NULL));
    pourcentRemplissage = ((largeur*longueur) *pourcentRemplissage) /100;

    char** array = (char**) malloc(sizeof(char*) * longueur);   // NE PAS OUBLIER DE FREE
    for(i=0;i<longueur; i++){
        array[i] = (char*) malloc(sizeof(char) * largeur);
    }

    for(i=0;i<longueur;i++){
        for(j=0;j<largeur;j++){
            array[i][j] = '_';
        }
    }

    i=0;
    while(i < pourcentRemplissage){
        rankOfI = rand_a_b(0, longueur);
        rankOfJ = rand_a_b(0, largeur);
        
        if(array[rankOfI][rankOfJ] == 'X'){
            i--;
        }
        else{
        array[rankOfI][rankOfJ] = 'X';
        }

        i++;
    }
    cpt=0;
    for(i=0;i<longueur;i++){
        for(j=0;j<largeur;j++){
            if(array[i][j] == 'X'){
                cpt++;
            }
        }
    }


    printf("\n");
    //printf("%d\n\n", pourcentRemplissage);
    return array;
}