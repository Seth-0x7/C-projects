/* Travail Pratique 1 : Chemin de dyck

Description : Ce fichier contient la fonction principale du programme
              mot de dyck. 
Universite du Quebec a montreal
              
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>


#define TAILLE_MOT 40
#define LONGUEUR_MAX 100
#define NOMBRE_MAX_ARGUMENTS 4
#define MOT_HAUTEUR "hauteur"
#define MOT_AIRE "aire"




#define USAGE "\
Usage: %s [HEIGHT,AREA] <LETTER 1> <LETTER 2> <WORD>\n\
\n\
Draws on an ASCII path of dycks word. The dycks word is provided on stdin and\n\
the result is printed on stdout. The length of the word must not exceed 40 characters.\n\
\n\
If no argument is provided, the program prints this help and exit.\n\
\n\
Program parameters :\n\
  HEIGHT                    Optional parameter to calculate the height of the\n\
                            path under the word of dyck.\n\
  AREA                      Optional parameter to calculate the height of\n\
                            the path under the word of dyck.\n\
  LETTER 1, LETTER 2        Define the alphabet of the word.\n\
  WORD                      Word of dyck to draw.\n\
  "

struct motDeDyck {
    char mot[TAILLE_MOT];   //Le mot saisi
    char haut;              //Caractere ascendant
    char bas;               //Caractere descendant
};

// STATUT DU PROGRAMME
typedef enum {
    OK                          = 0,
    ERREUR_ARGUMENTS_INVALIDES  = 1,
    ERREUR_DONNEES_INVALIDES    = 2,
    ERREUR_MOT_TROP_LONG        = 3,
    ERREUR_LETTRE_INTERDITE     = 4,
    ERREUR_MOT_NON_EQUILIBRE    = 5
}Statut;

const char* messages_erreur[] = {
    "",  // Correspond à OK, pas de message d'erreur
    "argument invalide",
    "donnees invalides",
    "mot trop long",
    "lettre interdite",
    "mot non equilibre"
};

    /********************* Declaration des fonctions *****************/

    /**
     * Affiche l'usage du programme avec le message spécifié.
     *
     * @param s Le message à afficher dans l'usage.
     */
    void afficherUsage(char *s);

    /**
     * Vérifie si la taille de la chaîne de caractères est inférieure à la constante TAILLE_MOT.
     *
     * @param m La chaîne de caractères à vérifier.
     * @return true si la taille est inférieure à TAILLE_MOT, false sinon.
     */
    bool verifierTailleMot(const char* m);

    /**
     * Valide la longueur du mot dans la structure motDeDyck.
     * Affiche un message d'erreur si la longueur dépasse TAILLE_MOT.
     *
     * @param m La structure motDeDyck contenant le mot à valider.
     * @return Le code d'erreur ERREUR_MOT_TROP_LONG en cas d'erreur, 0 sinon.
     */
    int validerLongueurMot(struct motDeDyck m);

    /**
     * Vérifie si les caractères de la chaîne de caractères sont différents de l1 et l2.
     *
     * @param l1 Le premier caractère à comparer.
     * @param l2 Le deuxième caractère à comparer.
     * @param m La chaîne de caractères à vérifier.
     * @return true si au moins un caractère est différent de l1 et l2, false sinon.
     */
    bool verifierLettre(char l1, char l2, char* m);

    /**
     * Compte le nombre d'occurrences du caractère spécifié dans la chaîne de caractères.
     *
     * @param chaine La chaîne de caractères dans laquelle compter les occurrences.
     * @param caractere Le caractère à compter.
     * @return Le nombre d'occurrences du caractère dans la chaîne.
     */
    int compterOccurrences(char *chaine, char caractere);

    /**
     * Détermine si le nombre d'occurrences de l1 et l2 dans la chaîne de caractères est équilibré.
     *
     * @param l1 Le premier caractère à compter.
     * @param l2 Le deuxième caractère à compter.
     * @param m La chaîne de caractères dans laquelle compter les occurrences.
     * @return true si le nombre d'occurrences de l1 et l2 est équilibré, false sinon.
     */
    bool determinerEquilibreMot(char l1, char l2, char *m);

    /**
     * Vérifie si le nombre d'arguments est égal à NOMBRE_MAX_ARGUMENTS.
     *
     * @param nbreArg Le nombre d'arguments à vérifier.
     * @return true si le nombre d'arguments est égal à NOMBRE_MAX_ARGUMENTS, false sinon.
     */
    bool verifierNombreArguments(int nbreArg);

    /**
     * Vérifie si la taille de la chaîne de caractère est différente de 1.
     *
     * @param caractere La chaîne de caractère à vérifier.
     * @return true si la taille de la chaîne est différente de 1, false sinon.
     */
    bool verifierTailleCaractere(char *caractere);

    /**
     * Vérifie si les deux caractères spécifiés sont similaires.
     *
     * @param c1 Le premier caractère à comparer.
     * @param c2 Le deuxième caractère à comparer.
     * @return true si les deux caractères sont similaires, false sinon.
     */
    bool caracteresSimilaires(char c1, char c2);

    /**
     * Vérifie si la chaîne de caractères est vide.
     *
     * @param chaine La chaîne de caractères à vérifier.
     * @return true si la chaîne est vide, false sinon.
     */
    bool estChaineVide(const char *chaine);

    /**
     * Affiche le message "mot trop long" et retourne le code d'erreur ERREUR_MOT_TROP_LONG.
     *
     * @return Le code d'erreur ERREUR_MOT_TROP_LONG.
     */
    int motTropLong();

    /**
     * Affiche le message "lettre interdite" et retourne le code d'erreur ERREUR_LETTRE_INTERDITE.
     *
     * @return Le code d'erreur ERREUR_LETTRE_INTERDITE.
     */
    int lettreInterdite();

    /**
     * Affiche le message "mot non équilibré" et retourne le code d'erreur ERREUR_MOT_NON_EQUILIBRE.
     *
     * @return Le code d'erreur ERREUR_MOT_NON_EQUILIBRE.
     */
    int motNonEquilibre();

    /**
     * Affiche le message "données invalides" et retourne le code d'erreur ERREUR_DONNEES_INVALIDES.
     *
     * @return Le code d'erreur ERREUR_DONNEES_INVALIDES.
     */
    int donneesInvalides();

    /**
     * Affiche le message "argument invalide" et retourne le code d'erreur ERREUR_ARGUMENTS_INVALIDES.
     *
     * @return Le code d'erreur ERREUR_ARGUMENTS_INVALIDES.
     */
    int argumentInvalides();

    /**
     * Valide les arguments passés au programme et effectue les opérations appropriées.
     *
     * @param n Le nombre d'arguments passés au programme.
     * @param liste Le tableau d'arguments passés au programme.
     */
    bool validerArguments(int n, char *liste[]);

    /**
     * Calcule l'aire d'un mot de Dyck.
     *
     * @param mot Le mot de Dyck sur lequel calculer l'aire.
     * @return L'aire du mot de Dyck.
     */
    int calculer_aire(struct motDeDyck *mot);

    /**
     * Calcule la hauteur maximale d'un mot de Dyck.
     *
     * @param mot Le mot de Dyck sur lequel calculer la hauteur.
     * @return La hauteur maximale du mot de Dyck.
     */
    int calculer_hauteur(const struct motDeDyck *mot);

    /**
     * Lit les entrées depuis l'entrée standard et les stocke dans une structure motDeDyck spécifiée.
     *
     * @param m Un pointeur vers la structure motDeDyck dans laquelle stocker les données lues.
     * @return Le statut de la lecture de l'entrée :
     *         - OK si la lecture a réussi et les données sont valides.
     *         - ERREUR_DONNEES_INVALIDES si une erreur s'est produite lors de la lecture des données.
     */
    Statut lireEntreeFichier(struct motDeDyck *m) ;

    /**
 * Valide le mot de Dyck spécifié dans une structure motDeDyck.
 *
 * @param motDeDyck Un pointeur vers la structure motDeDyck contenant le mot à valider.
 * @return Le statut de validation du mot de Dyck :
 *         - OK si le mot est valide et équilibré.
 *         - ERREUR_LETTRE_INTERDITE si une lettre interdite est présente dans le mot.
 *         - ERREUR_MOT_NON_EQUILIBRE si le mot n'est pas équilibré (nombre de caractères ascendants et descendants différents).
 */
Statut validerMotDeDyck(const struct motDeDyck *m);

/**
 * Dessine le chemin de Dyck correspondant au mot de Dyck spécifié.
 *
 * @param m Le mot de Dyck à représenter.
 */
void dessinerCheminDyck(const struct motDeDyck *m);


    /****************** Definition des fonctions ********************/
    void afficherUsage(char *s){
        printf(USAGE, s);
    }
    
   
    bool verifierTailleMot(const char* m) {
        int taille = strlen(m);
        return taille < TAILLE_MOT;
    }


    int validerLongueurMot(struct motDeDyck m){
        if (!verifierTailleMot(m.mot))
            fprintf(stderr, "mot trop long\n");
        return ERREUR_MOT_TROP_LONG;
    }


    bool verifierLettre(char l1, char l2, char* m){
        bool estDifferent = false;
        for (int i = 0; m[i] != '\0'; i++)
            if (m[i] != l1 && m[i] != l2)
            {
                estDifferent = true;
            }
            
            return estDifferent;
                
    }

    int compterOccurrences(char *chaine, char caractere) {
    int occurrences = 0;

    while (*chaine) {
        if (*chaine == caractere) {
            occurrences++;
        }
        chaine++;
    }
    return occurrences;
    }


    bool determinerEquilibreMot(char l1, char l2, char *m){
        int occurencelettre1 = compterOccurrences(m, l1);
        int occurencelettre2 = compterOccurrences(m, l2);
        return occurencelettre1 == occurencelettre2;
    }
        
    

    bool verifierNombreArguments(int nbreArg){
        return nbreArg == NOMBRE_MAX_ARGUMENTS;   
    }

    bool verifierTailleCaractere(char *caractere){
        return (strlen(caractere) != 1);
    }

    bool caracteresSimilaires(char c1, char c2) {
        return c1 == c2;
    }

    bool estChaineVide(const char *chaine) {
        return chaine[0] == '\0';
    }

    int motTropLong(){
        printf("mot trop long\n");
        return ERREUR_MOT_TROP_LONG;
    }

    int lettreInterdite(){
        printf("lettre interdite\n");
        return ERREUR_LETTRE_INTERDITE;
    }

    int motNonEquilibre(){
        printf("mot non equilibre\n");
        return ERREUR_MOT_NON_EQUILIBRE;
    }

    int donneesInvalides(){
        printf("donnees invalides\n");
        return ERREUR_DONNEES_INVALIDES;
    }

    int argumentInvalides(){
        printf("argument invalide");
        return ERREUR_ARGUMENTS_INVALIDES;
    }

    int calculer_hauteur(const struct motDeDyck *mot){
        int hauteur = 0, hauteurMax = 0;

            for (int i = 0; i < strlen(mot->mot); ++i) {
                char c = mot->mot[i];
                if (c == mot->haut) {
                    hauteur++;
                    hauteurMax = (hauteur > hauteurMax) ? hauteur : hauteurMax;
                } else {
                    hauteur--;
                }
            }

            return hauteurMax;
    }


    int calculer_aire(struct motDeDyck *mot) {
        int aire = 0, hauteur = 0;

            for (int i = 0; i < strlen(mot->mot); ++i) {
                if (mot->mot[i] == mot->haut) {
                    hauteur++;
                    aire += hauteur;

                } else {
                    hauteur--;
                    aire += hauteur;
                }
            }

        return aire;
    }


    bool validerArguments(int n, char *liste[]){
        bool estValide = false;
        if(n <= NOMBRE_MAX_ARGUMENTS){
            if (verifierTailleCaractere(liste[1]) || verifierTailleCaractere(liste[2]) 
                || estChaineVide(liste[3]) || caracteresSimilaires(*liste[1], *liste[2])){

                donneesInvalides();
                   
            }else if (!verifierTailleMot(liste[3]))
            {
                motTropLong();
            }else if (!determinerEquilibreMot(*liste[1], *liste[2], liste[3]))
            {
                motNonEquilibre();
            }else if(verifierLettre(*liste[1], *liste[2], liste[3])){
                
                lettreInterdite();
            }
        }else{
            estValide = true;
        }
        return estValide;
    }

    Statut validerMotDeDyck(const struct motDeDyck *m) {
        int compte_haut = 0, compte_bas = 0;
        

    for (size_t i = 0; i < strlen(m->mot); ++i) {
        char c = m->mot[i];
        if (c == m->haut) {
            compte_haut++;
        } else if (c == m->bas) {
            compte_bas++;
        } else {
            return ERREUR_LETTRE_INTERDITE;
        }

        if (compte_bas > compte_haut) {
            
            return ERREUR_MOT_NON_EQUILIBRE;
        }
    }

    if (compte_haut != compte_bas) {
        
        return ERREUR_MOT_NON_EQUILIBRE;
    }

    return OK;
    }

    Statut lireEntreeFichier(struct motDeDyck *m) {
        char entree[20];
        char lettre1[3], lettre2[3];
        
        if (fgets(entree, sizeof(entree), stdin) == NULL) {
            
            return ERREUR_DONNEES_INVALIDES;
        }
        
        if (sscanf(entree, " %2s %2s %s", lettre1, lettre2, m->mot) != 3) {
            return ERREUR_ARGUMENTS_INVALIDES;
        }
        
        m->haut = *lettre1;
        m->bas = *lettre2;
        
        if (m->haut == m->bas) {
            return ERREUR_DONNEES_INVALIDES;
        }
        
        if (strlen(m->mot) > TAILLE_MOT-28) {
            return ERREUR_MOT_TROP_LONG;
        }
        
        return validerMotDeDyck(m);
    }

void dessinerCheminDyck(const struct motDeDyck *m) {
    int hauteur = calculer_hauteur(m);
    int largeur = strlen(m->mot);
    char grille[hauteur][largeur];

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            grille[i][j] = '*';
        }
    }

    int positionX = 0, positionY = hauteur - 1;
    for (size_t i = 0; i < strlen(m->mot); ++i) {
        char c = m->mot[i];
        if (c == m->haut) {
            grille[positionY][positionX] = '/';
            positionY--;
        } else {
            positionY++;
            grille[positionY][positionX] = '\\';
        }
        positionX++;
    }

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            printf("%c", grille[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    
    if (isatty(STDIN_FILENO)) {
        if (argc != 1)
        {
            // validerArguments(argc, argv);
            
            if (argc > NOMBRE_MAX_ARGUMENTS && strcmp(argv[1], "hauteur") != 0 && strcmp(argv[1], "aire") != 0) {
                printf("%s\n", messages_erreur[ERREUR_ARGUMENTS_INVALIDES]);
                return ERREUR_ARGUMENTS_INVALIDES;
            }
            struct motDeDyck motDyck;
            motDyck.haut = *argv[1];
            motDyck.bas = *argv[2];
            strcpy(motDyck.mot, argv[3]);

            if (argc > NOMBRE_MAX_ARGUMENTS)
            {
                if (strcmp(argv[1], MOT_HAUTEUR) == 0){
                    printf("%d\n", calculer_hauteur(&motDyck));
                }else if(strcmp(argv[1], MOT_AIRE) == 0){
                    printf("%d\n", calculer_aire(&motDyck));
                }
            }
            if(validerArguments(argc, argv) == true){
                dessinerCheminDyck(&motDyck);
            }
        }else{
            printf(USAGE, argv[0]);
        }
    } else {   
        if (argc > 1 && strcmp(argv[1], "hauteur") != 0 && strcmp(argv[1], "aire") != 0) {
            printf("%s\n", messages_erreur[ERREUR_ARGUMENTS_INVALIDES]);
            return ERREUR_ARGUMENTS_INVALIDES;
        }
        struct motDeDyck mot;
        Statut s = lireEntreeFichier(&mot);
        if (s != OK) {
            printf("%s\n", messages_erreur[s]);
            return s;
        }

        if (argc > 1)
        {
            if (strcmp(argv[1], MOT_HAUTEUR) == 0){
                printf("%d\n", calculer_hauteur(&mot));
            }else if(strcmp(argv[1], MOT_AIRE) == 0){
                printf("%d\n", calculer_aire(&mot));
            }
        }else{
            dessinerCheminDyck(&mot);
            
        }   
    }
    // Traitement du mot de Dyck ici
    
    return OK;
}
