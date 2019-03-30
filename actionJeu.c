# include "includes.h"

char** copier(char **arrayToCopy, char ** arrayToCopyIn, int longueur, int largeur){
    
    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            arrayToCopyIn[i][j] = arrayToCopy[i][j];
        }
    }
    return arrayToCopyIn;
}

/*void sauvegarder(char** array, int longueur, int largeur){

}*/

void afficherTableau(char** array, int longueur, int largeur){

    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}


char** iterationDuJeu(char** array, char** arrayToCopyIn, int longueur, int largeur){

    int flagChangement = 0;

        for(int i =0;i<longueur;i++){
            for(int j=0;j<largeur;j++){
                
                if(array[i][j] == 'X'){     // CAS OU LA CELLULE EST MORTE
                   
                    if(i == 0){     // CAS OU I = 0
                        if(j == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur -1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(i == longueur -1){       // CAS OU I EST AU DERNIER RANG
                        if(j == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur-1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == 0){     // CAS OU J = 0
                        if(i == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(i == longueur-1){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == largeur-1){    // CAS OU J EST AU DERNIER RANK
                        if(i == 0){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else if (i == longueur -1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else{
                        if(array[i-1][j] == '_'){
                            flagChangement++;
                        }
                        if(array[i-1][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j-1] == '_'){
                            flagChangement++;
                        }
                        if(array[i][j-1] == '_'){
                            flagChangement++;
                        }
                        if(array[i-1][j-1] == '_'){
                            flagChangement++;
                        }
                    }

                    // ALGO SELON SI CELLULE MORTE
                    if(flagChangement >= 3){
                        arrayToCopyIn[i][j] = '_';
                    }
                    flagChangement = 0;
                }   // FIN SI CELLULE MORTE

            /************************************** ALGO CELLULE EN VIE **********************************************/

                else{    // CAS SI LA CASE ACTUELLE = CELLULE EN VIE
                    if(i == 0){     // CAS OU I = 0
                        if(j == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur -1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(i == longueur -1){       // CAS OU I EST AU DERNIER RANG
                        if(j == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur-1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == 0){     // CAS OU J = 0
                        if(i == 0){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else if(i == longueur-1){
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == largeur-1){    // CAS OU J EST AU DERNIER RANK
                        if(i == 0){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else if (i == longueur -1){
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == '_'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == '_'){
                                flagChangement++;
                            }
                        }
                    }

                    else{
                        if(array[i-1][j] == '_'){
                            flagChangement++;
                        }
                        if(array[i-1][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j+1] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j] == '_'){
                            flagChangement++;
                        }
                        if(array[i+1][j-1] == '_'){
                            flagChangement++;
                        }
                        if(array[i][j-1] == '_'){
                            flagChangement++;
                        }
                        if(array[i-1][j-1] == '_'){
                            flagChangement++;
                        }
                    }

                    if(flagChangement < 2 || flagChangement > 3){
                        arrayToCopyIn[i][j] = 'X';
                    }
                    flagChangement = 0;

                }   // FIN SI CELLULE EN VIE
            }   // FIN FOR J
        }   // FIN FOR I

        return arrayToCopyIn;

}
