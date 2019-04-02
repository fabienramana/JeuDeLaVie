#include "includes.h"

// FICHIER POUR LA GESTION DES PARAMETRES

int convertCharToInt(char c){
    int toReturn = -150;
    if(c == 48){
        toReturn = 0;
    }
    else if(c == 49){
        toReturn = 1;
    }
    else if(c == 50){
        toReturn = 2;
    }
    else if(c == 51){
        toReturn = 3;
    }
    else if(c == 52){
        toReturn = 4;
    }
    else if(c == 53){
        toReturn = 5;
    }
    else if(c == 54){
        toReturn = 6;
    }
    else if(c == 55){
        toReturn = 7;
    }
    else if(c == 56){
        toReturn = 8;
    }
    else if(c == 57){
        toReturn = 9;
    }
    return toReturn;
}


int* gestionDesParametres(int argc, char** argv){
   int flagParameters = 0;
   int* toReturn = (int*) malloc(sizeof(int) * 8);  //case 0 : -d (longueur), case 1 : -d (largeur) case 2 : -f, case 3 : -r (naitre), case 4 : -r (mort)
   int j=0;                                     //, case 5 : flagParameters, case 6 : -l, case 7 : -h

   for(int i=0;i<8;i++){
       toReturn[i] = -1;
   }

    if(argc > 1){
        for(int i=1;i<argc;i++){
            if(argv[i][0] == '-'){
                if(argv[i][1] != 'd' && argv[i][1] != 'f' && argv[i][1] != 'r' && argv[i][1] != 'l' && argv[i][1] != 'h'){
                    printf("Parametres non-reconnu !\n");
                    flagParameters = -1;
                    toReturn[5] = flagParameters;
                    return toReturn;
                }
                else{
                    if(argv[i][1] == 'd'){
                        if(i+1 >= argc){
                            printf("Pas de valeur trouvée pour la parametre -d\n");
                            flagParameters = -1;
                            toReturn[5] = flagParameters;
                            return toReturn;
                        }
                        else{
                            for(j=0;argv[i+1][j]!= 'x';j++){
                                if(argv[i+1][j] >= 48 && argv[i+1][j] <= 57){
                                    if(j == 0){
                                        toReturn[0] =  convertCharToInt(argv[i+1][j]);
                                    }
                                    else{
                                        toReturn[0] *= 10;
                                        toReturn[0] += convertCharToInt(argv[i+1][j]);
                                    }
                                }
                                else{
                                    printf("Argument pour le parametre -d invalide ! \n");
                                    flagParameters = -1;
                                    toReturn[5] = flagParameters;
                                    return toReturn;
                                }
                            }
                            for(j=j+1;argv[i+1][j]!= '\0';j++){
                                if(argv[i+1][j] >= 48 && argv[i+1][j] <= 57){
                                    if(argv[i+1][j-1] == 'x'){
                                        toReturn[1] =  convertCharToInt(argv[i+1][j]);
                                    }
                                    else{
                                        toReturn[1] *= 10;
                                        toReturn[1] += convertCharToInt(argv[i+1][j]);
                                    }
                                }
                                else{
                                    printf("Argument pour le parametre -d invalide ! \n");
                                    flagParameters = -1;
                                    toReturn[5] = flagParameters;
                                    return toReturn;
                                }
                            }
                            flagParameters++;
                        }
                    }
                    if(argv[i][1] == 'f'){
                        if(i+1 >= argc){
                            printf("Pas de valeur trouvée pour la parametre -f\n");
                            flagParameters = -1;
                            toReturn[5] = flagParameters;
                            return toReturn;
                        }
                        else{
                            for(j=0;argv[i+1][j]!= '\0';j++){
                                if(argv[i+1][j] >= 48 && argv[i+1][j] <= 57){
                                    if(j == 0){
                                        toReturn[2] =  convertCharToInt(argv[i+1][j]);
                                    }
                                    else{
                                        toReturn[2] *= 10;
                                        toReturn[2] += convertCharToInt(argv[i+1][j]);
                                    }
                                }
                                else{
                                    printf("Argument pour le parametre -f invalide ! \n");
                                    flagParameters = -1;
                                    toReturn[5] = flagParameters;
                                    return toReturn;
                                }
                            }
                            flagParameters++;
                        }
                    }
                    if(argv[i][1] == 'r'){
                        if(i+1 >= argc){
                            printf("Pas de valeurs trouvées pour le parametre -r\n");
                            flagParameters = -1;
                            toReturn[5] = flagParameters;
                            return toReturn;
                        }
                        else if(i+2 >= argc){
                            printf("Une des valeurs pour le parametre -r n'est pas déclaré\n");
                            flagParameters = -1;
                            toReturn[5] = flagParameters;
                            return toReturn;
                        }
                        else{
                            for(j=0;argv[i+1][j]!= '\0';j++){
                                if(argv[i+1][j] >= 48 && argv[i+1][j] <= 57){
                                    if(j == 0){
                                        toReturn[3] =  convertCharToInt(argv[i+1][j]);
                                    }
                                    else{
                                        toReturn[3] *= 10;
                                        toReturn[3] += convertCharToInt(argv[i+1][j]);
                                    }
                                }
                                else{
                                    printf("Arguments pour le parametre -r invalides ! \n");
                                    flagParameters = -1;
                                    toReturn[5] = flagParameters;
                                    return toReturn;
                                }
                            }
                            for(j=0;argv[i+2][j]!= '\0';j++){
                                if(argv[i+2][j] >= 48 && argv[i+2][j] <= 57){
                                    if(j == 0){
                                        toReturn[4] =  convertCharToInt(argv[i+2][j]);
                                    }
                                    else{
                                        toReturn[4] *= 10;
                                        toReturn[4] += convertCharToInt(argv[i+2][j]);
                                    }
                                }
                                else{
                                    printf("Arguments pour le parametre -r invalides ! \n");
                                    flagParameters = -1;
                                    toReturn[5] = flagParameters;
                                    return toReturn;
                                }
                            }
                            flagParameters++;
                        }
                    }
                    if(argv[i][1] == 'h'){
                        printf("\n /**   AIDE DU JEU    **/\n");
                        printf("\nLe jeu se déroule de la manière suivante : On a un tableau \n");
                        printf("en deux dimensions où chacune des cases représente une cellule \n");
                        printf("morte ou en vie. Celles-ci évoluent en fonctions des cellules alentours. \n");

                        printf("\nLe paramètre -d permet d’indiquer les dimensions de la grille, au format ​ largeur​ x ​ hauteur.");
                        printf(" Par exemple, pour une grille de 10 cellules de côté, on indiquera ​ -d 10x10\n");
                        printf("Si rien n’est indiqué, et qu’aucun fichier n’est chargé, on commencera avec une grille de 80x80 par défaut\n");
                        printf("On considère que les grilles ne peuvent faire plus de 256 de côté. \n");

                        printf("\nLe paramètre -f représente le pourcentage de remplissage, exprimé par un entier de 0 à 100.\n");
                        printf("Par exemple, pour remplir la grille à moitié, on indiquera ​ -f 50.\n");
                        printf("Si rien n’est indiqué et qu’aucun fichier n’est chargé,\n");
                        printf("on commencera avec un taux de remplissage de 20 pourcents\n");

                        printf("\nLe paramètre -l permet de charger un fichier de sauvegarde (appelé automatique 'sauvegarde'), ce qui permet de");
                        printf("\nreprendre une partie là où on l'avait laissé !\n");

                        printf("\nL'affichage de l'aide ne permet pas de lancer une partie, veuillez relancer le programme sans le parametre -h\n\n");

                        printf("/***********************/\n");
                        toReturn[7] = 1;
                        flagParameters++;
                    }
                    if(argv[i][1] == 'l'){
                        if(toReturn[0] != -1 || toReturn[1] != -1 || toReturn[2] != -1){
                            printf("\nVous avez demandé à charger votre derniere partie.");
                            printf("\nLes parametres saisis precedemment ne seront donc pas pris en compte\n");
                            printf("Le fichier de sauvegarde va être chargé ! \n");
                        }
                        toReturn[6] = 1;
                        flagParameters++;
                    }
                }
            }
        }
    }

    // FAIRE GESTION DES ERREURS
    
    // -d
    if(toReturn[0] == 0 || toReturn[1] == 0){
        printf("ERROR : la longueur ou la largeur du tableau ne peut pas etre égal à 0\n");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;
    }
    if(toReturn[0] > 256 || toReturn[1] > 256){
        printf("ERROR : la longueur ou la largeur du tableau ne peut pas etre superieur a 256\n");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;
    }
    if((toReturn[0] == -1 && toReturn[1] != -1) || (toReturn[0] != -1 && toReturn[1] == -1)){
        printf("ERROR : la longueur ou la largeur du tableau n'a pas été déclaré\n");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;
    }

    // -f
    if(toReturn[2] == 0){
        printf("ERROR : le pourcentage de remplissage ne peut pas etre égal à 0\n");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;
    }
    if(toReturn[2] >= 100){
        printf("ERROR : le pourcentage de remplissage ne peut pas etre égal ou superieur à 100\n");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;    
    }

    //-r
   /* if(toReturn[3] == ){
        
    } */


    toReturn[5] = flagParameters;
    return toReturn;

}