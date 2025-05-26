#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NB_MOTS=5;
#define MAX_LONGUEUR_MOT 50
// Fonction pour saisir les mots dans un tableau de chaînes de caractères
char** Saisie(char **CH) {
    printf("Saisir %d mots (maximum %d caractères chacun):\n", NB_MOTS, MAX_LONGUEUR_MOT);
    char **p ;
     for (p = CH; p < CH+NB_MOTS; p++){
       // Allouer de la mémoire pour le mot
        *p= (char *)malloc((MAX_LONGUEUR_MOT + 1) * sizeof(char));
        printf("Donner un mot : ") ;
        scanf("%s", *p); // Lire le mot depuis l'entrée standard
    }
    return CH ;
}

// Fonction pour copier les mots en une seule 'phrase' dont l'adresse est affectée à un pointeur PHRASE
char* copier(char **CH) {
    char **p ;
    
    // Initialiser la phrase avec une taille suffisamment grande
    char *PHRASE = (char *)malloc(1 * sizeof(char));
    PHRASE[0] = '\0'; // Phrase vide au début
    
    // Copier les mots dans la phrase avec des espaces entre les mots

    int taille ;
    for (p = CH; p < CH+NB_MOTS; p++){
        taille=strlen(PHRASE) + strlen(*p) + 2;
       // Réallouer de la mémoire pour les mots
        PHRASE= (char *)realloc(PHRASE, taille*sizeof(char)); 
        // Concaténer le mot et un espace à la fin de la phrase
        strcat(PHRASE, *p);
        strcat(PHRASE, " ");

    }
    return PHRASE ;
    
}
// Fonction pour afficher le contenu du tableau de mots
void Afficher(char **CH) {
    printf("Contenu du tableau de mots :\n");
    char **p ;
    for (p = CH; p < CH+NB_MOTS; p++) {
        printf("%s\n", *p);
    }
}

// Fonction pour afficher le contenu du tableau de mots
void Liberer(char **CH) {
    char **p;
    // Libération de la mémoire allouée pour chaque mot
    for (p = CH; p < CH + NB_MOTS; p++) {
      free(*p);
    }
    free(CH) ;
}


int main()
{
    char **CH,*PHRASE;
    
    // Allocation dynamique de mémoire pour le tableau de pointeurs
    CH = (char **)malloc(NB_MOTS * sizeof(char*)); //autre décalaration char *CH[NB_MOTS],*PHRASE;
    
    // Saisie des mots
    CH=Saisie(CH);
    
    // Affichage du tableau de mots 
    Afficher(CH);
   
    // Copier
    PHRASE=copier(CH);

    // Affichage de la phrase
    printf("\nLa phrase  : %s\n", PHRASE);

   
    // Libération de la mémoire allouée pour CH
    Liberer(CH) ;
    
    // Libération de la mémoire allouée pour la phrase
    free(PHRASE);
     
    return 0;
}