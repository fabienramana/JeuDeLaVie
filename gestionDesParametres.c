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


int* gestionDesParametresInteger(int argc, char** argv){
   int flagParameters = 0;
   int* toReturn = (int*) malloc(sizeof(int) * 9);  //case 0 : -d (longueur), case 1 : -d (largeur) case 2 : -f, case 3 : -r (naitre), case 4 : -r (mort)
   int j=0;                                     //, case 5 : flagParameters, case 6: parametre -d donné, case è :parametre -r donné, case 8 : parametre -r donné

   for(int i=0;i<6;i++){
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
                            toReturn[6] = 1;
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
                            toReturn[7] = 1;
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
                            toReturn[8] = 1;
                            flagParameters++;
                        }
                    }
                }
            }
        }
    }

    // FAIRE GESTION DES ERREURS
    
    // -d
    if(toReturn[0] != 0 || toReturn[1] != 0){
        if(toReturn[0] > 256 || toReturn[1] > 256){
            printf("ERROR : la longueur ou la largeur du tableau ne peut pas etre superieur a 256");
            flagParameters = -1;
            toReturn[5] = flagParameters;
            return toReturn;
        }
        printf("ERROR : la longueur ou la largeur du tableau ne peut pas etre égal à 0");
        flagParameters = -1;
        toReturn[5] = flagParameters;
        return toReturn;
    }

    // -f
    if(toReturn[2] == 0){
        if(toReturn[2] >= 100){
            printf("ERROR : le pourcentage de remplissage ne peut pas etre égal ou superieur à 100");
            flagParameters = -1;
            toReturn[5] = flagParameters;
            return toReturn;    
        }
        printf("ERROR : le pourcentage de remplissage ne peut pas etre égal à 0");
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

/*char* gestionDesErreursFileAndHelp(int argc, char** argv, int flagParameters){
    
}*/