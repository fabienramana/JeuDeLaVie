
#include "bibli.h"
#include "includes.h"

char** jouer(char** array, int longueur, int largeur){
    char entree, choix;
    int nbr_de_tours = 0;
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

        if(nbr_de_tours == 0){
            afficherTableau(array, longueur, largeur);
            printf("\n");
        }
        else{
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
        }

        while(1){
            printf("\n Voulez vous continuer ? : ");
            scanf(" %c", &entree);
            if(entree != 'o'){
                if(entree == 's' || entree == 'S'){
                    if(flagArrayToCopyIn == 0){
                        sauvegarder(array, longueur, largeur);
                        printf("\n Sauvegarde bien effectuée !\n");
                        break;
                    }
                    else{
                        sauvegarder(clonedArray, longueur, largeur);
                        printf("\n Sauvegarde bien effectuée !\n");
                        break;
                    }
                }
                else if(entree == 'q' || entree == 'Q'){
                    while(1){
                        printf("\n Voulez vous sauvegarder cette partie ? (o/n): ");
                        scanf(" %c", &choix);
                        if(choix == 'o' || choix == 'O'){
                            if(flagArrayToCopyIn == 0){
                                sauvegarder(array, longueur, largeur);
                                printf("\n Sauvegarde bien effectuée !\n");
                                break;
                            }
                            else{
                                sauvegarder(clonedArray, longueur, largeur);
                                printf("\n Sauvegarde bien effectuée !\n");
                                break;
                            }
                        }
                        else if(choix == 'n' || choix == 'N'){
                            printf("\nTres bien.\n");
                        }
                        else{
                            printf("\n Choix invalide ! \n");
                        }
                    }
                    break;
                }
                else{
                    printf("\nEntree non valide ! \n");
                }
            }
            else{
                break;
            }
            printf("\n");
        }

        if(entree == 's' || entree == 'S' || entree == 'q' || entree == 'Q'){
            break;
        }
        nbr_de_tours++;

    }while(entree != '\n'); 



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