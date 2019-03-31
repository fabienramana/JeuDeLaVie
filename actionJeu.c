# include "includes.h"

char** copier(char **arrayToCopy, char ** arrayToCopyIn, int longueur, int largeur){
    
    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            arrayToCopyIn[i][j] = arrayToCopy[i][j];
        }
    }
    return arrayToCopyIn;
}

void sauvegarder(char** array, int longueur, int largeur){
    FILE* f;
    int toInsert = 0;
    //SUPPRIMER FICHIER SI DEJA EXISTANT

    toInsert += 1;
    f = fopen("sauvegarde","w+");
    fwrite(&longueur,sizeof(int), 1, f);
    fwrite(&largeur,sizeof(int), 1, f);

    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            if(array[i][j] == '_'){
                toInsert = 1;
                fwrite(&toInsert, sizeof(int), 1, f);
            }
            else if (array[i][j] == 'X'){
                toInsert = 0;
                fwrite(&toInsert, sizeof(int), 1, f);
            }
        }
    }
    fclose(f);

}

void afficherTableau(char** array, int longueur, int largeur){

    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void lireFichierBinaire(){
    FILE* f;
    int N, M, number;
    f = fopen("sauvegarde", "r");

    fread(&N, sizeof(int), 1, f);
    fread(&M, sizeof(int), 1, f);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            fread(&number, sizeof(int), 1, f);
            printf("%d", number);
        }
        printf("\n");
    }

    fclose(f);
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
