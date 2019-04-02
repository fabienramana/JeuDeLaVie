# include "includes.h"

char** copier(char **arrayToCopy, char ** arrayToCopyIn, int longueur, int largeur){
    
    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            arrayToCopyIn[i][j] = arrayToCopy[i][j];
        }
    }
    return arrayToCopyIn;
}

int getSize(int whichSize){
    FILE* f;
    int longueur, largeur;
    if(access("sauvegarde", F_OK) == -1){
        printf("Le fichier de sauvegarde n'existe pas...\n");
        return 0;
    }

    f = fopen("sauvegarde", "r");

    fread(&longueur, sizeof(int), 1, f);
    fread(&largeur, sizeof(int), 1, f);

    if(whichSize == 0){
        return longueur;
    }
    else{
        return largeur;
    }

    fclose(f);
}

char** getArray(){
    FILE* f;
    int longueur, largeur, number;
    f = fopen("sauvegarde", "r");

    fread(&longueur, sizeof(int), 1, f);
    fread(&largeur, sizeof(int), 1, f);

    char** array = (char**) malloc(sizeof(char*) * longueur);   // NE PAS OUBLIER DE FREE
    for(int i=0;i<longueur; i++){
        array[i] = (char*) malloc(sizeof(char) * largeur);
    }

    for(int i=0;i<longueur;i++){
        for(int j=0;j<largeur;j++){
            fread(&number, sizeof(int), 1, f);
            if(number == 1){
                array[i][j] = 'X';
            }
            else{
                array[i][j] = '_';
            }
        }
    }

    fclose(f);

    return array;
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
            if(array[i][j] == 'X'){
                toInsert = 1;
                fwrite(&toInsert, sizeof(int), 1, f);
            }
            else if (array[i][j] == '_'){
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
                
                if(array[i][j] == '_'){     // CAS OU LA CELLULE EST MORTE
                   
                    if(i == 0){     // CAS OU I = 0
                        if(j == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur -1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(i == longueur -1){       // CAS OU I EST AU DERNIER RANG
                        if(j == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur-1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == 0){     // CAS OU J = 0
                        if(i == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(i == longueur-1){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == largeur-1){    // CAS OU J EST AU DERNIER RANK
                        if(i == 0){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if (i == longueur -1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == '_'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else{
                        if(array[i-1][j] == 'X'){
                            flagChangement++;
                        }
                        if(array[i-1][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j-1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i][j-1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i-1][j-1] == 'X'){
                            flagChangement++;
                        }
                    }

                    // ALGO SELON SI CELLULE MORTE
                    if(flagChangement >= 3){
                        arrayToCopyIn[i][j] = 'X';
                    }
                    flagChangement = 0;
                }   // FIN SI CELLULE MORTE

            /************************************** ALGO CELLULE EN VIE **********************************************/

                else{    // CAS SI LA CASE ACTUELLE = CELLULE EN VIE
                    if(i == 0){     // CAS OU I = 0
                        if(j == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur -1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(i == longueur -1){       // CAS OU I EST AU DERNIER RANG
                        if(j == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(j == largeur-1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == 0){     // CAS OU J = 0
                        if(i == 0){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if(i == longueur-1){
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j+1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else if(j == largeur-1){    // CAS OU J EST AU DERNIER RANK
                        if(i == 0){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else if (i == longueur -1){
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                        else{
                            if(array[i-1][j] == 'X'){
                                flagChangement++;
                            }
                            if(array[i-1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j-1] == 'X'){
                                flagChangement++;
                            }
                            if(array[i+1][j] == 'X'){
                                flagChangement++;
                            }
                        }
                    }

                    else{
                        if(array[i-1][j] == 'X'){
                            flagChangement++;
                        }
                        if(array[i-1][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j+1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j] == 'X'){
                            flagChangement++;
                        }
                        if(array[i+1][j-1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i][j-1] == 'X'){
                            flagChangement++;
                        }
                        if(array[i-1][j-1] == 'X'){
                            flagChangement++;
                        }
                    }

                    if(flagChangement < 2 || flagChangement > 3){
                        arrayToCopyIn[i][j] = '_';
                    }
                    flagChangement = 0;

                }   // FIN SI CELLULE EN VIE
            }   // FIN FOR J
        }   // FIN FOR I

        return arrayToCopyIn;

}
