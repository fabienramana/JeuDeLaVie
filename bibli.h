// FICHIER POUR DECLARER TOUTES LES FONCTIONS DE TOUS LES FICHIERS

char** initialisation(int longueur, int largeur, int pourcentRemplissage);

int rand_a_b(int a, int b);

char** jouer(char **array, int longueur, int largeur);

char** copier(char **arrayToCopy, char ** arrayToCopyIn, int longueur, int largeur);

void sauvegarder(char** array, int longueur, int largeur);

char** iterationDuJeu(char** array, char** arrayToCopyIn, int longueur, int largeur);

void afficherTableau(char** array, int longueur, int largeur);

int* gestionDesParametresInteger(int argc, char** argv);

int convertCharToInt(char c);