#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NB_MOTS= 5 ;
#define MAX_LONGUEUR_MOT 50

// Fonction pour saisir les mots dans un tableau de chaînes de caractères
char ** Saisie(char **tab) {
    printf("Saisir %d mots (maximum %d caractères chacun):\n", NB_MOTS, MAX_LONGUEUR_MOT);
    char **p ;
     for (p = tab; p < tab+NB_MOTS; p++){
       // Allouer de la mémoire pour le mot
        *p= (char *)malloc((MAX_LONGUEUR_MOT + 1) * sizeof(char)); 
        scanf("%s", *p); // Lire le mot depuis l'entrée standard
    }
    return tab ;
}

// Fonction pour inserer un nouveau mot
char** insererMot(char **tab) {
    NB_MOTS=NB_MOTS+1 ; // nouvelle taille
    tab = (char **) realloc (tab, (NB_MOTS)*sizeof(char*)) ; // realloc de tableau avec une taille +1 
     
   *(tab+(NB_MOTS-1)) = (char *)malloc((MAX_LONGUEUR_MOT + 1) * sizeof(char));
   printf("\n Donner une chaine : ") ;
   scanf("%s", *(tab+(NB_MOTS-1)));
   return tab ;
}

// Fonction pour inverser l'ordre des caractères dans un mot
void inverserMot(char *mot) {
    char *p1 = mot;                       // Pointeur vers le début du mot
    char *p2 = mot + strlen(mot) - 1;   // Pointeur vers la fin du mot
    char temp ; // une variable temporaire pour la permutation
    // Inverser les caractères en utilisant les pointeurs
    while (p1 < p2) {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
}
// Fonction pour inverser l'ordre des mots dans un tableau de chaînes de caractères
void inverserTab(char **tab) {
    char **p1 = tab;                      // Pointeur vers le début du tableau
    char **p2 = tab + NB_MOTS - 1;        // Pointeur vers la fin du tableau
    char **temp ; // une variable temporaire pour la permutation
    // Inverser l'ordre des pointeurs vers les mots dans le tableau
    while (p1 < p2) {
        *temp = *p1;
        *p1 = *p2;
        *p2 = *temp;
        p1++;
        p2--;
    }
    
    // Inversion de l'ordre des caractères dans chaque mot
    char **p ;
    for (p = tab; p < tab+NB_MOTS; p++) {
        inverserMot(*p);
    }
    
}

// Fonction pour afficher le contenu du tableau de mots
void Afficher(char **tab) {
    printf("Contenu du tableau de mots :\n");
    char **p ;
    for (p = tab; p < tab+NB_MOTS; p++) {
        printf("%s\n", *p);
    }
}

// Fonction pour la Libération de la mémoire allouée pour chaque mot
void Liberer(char **tab) {
    char **p ;
    for (p = tab; p < tab+NB_MOTS; p++) {
        free(*p);
    }
    free(tab) ;
}


int main()
{
    
    char **tab;  // Déclaration du tableau de pointeurs vers les mots
    
    // Allocation dynamique de mémoire pour le tableau de pointeurs
    tab = (char **)malloc(NB_MOTS * sizeof(char*)); // autre déclaration char *tab[NB_MOTS]; 

    // Saisie des mots
    tab = Saisie(tab);
    
    //===========================================================
    // Affichage du tableau de mots avant l'insertion
    printf("Tableau de mots avant l'insertion :\n");
    Afficher(tab);

    tab=insererMot(tab) ;

    // Affichage du tableau de mots après l'insertion
    printf("Tableau de mots après l'insertion:\n");
    Afficher(tab);
    
    //===========================================================
 
  // Affichage du tableau de mots avant l'inversion
    printf("Tableau de mots avant l'inversion :\n");
    Afficher(tab);
    
    // Inversion de l'ordre des mots dans le tableau
    inverserTab(tab);

    // Affichage du tableau de mots après l'inversion
    printf("\nTableau de mots après l'inversion :\n");
    Afficher(tab); 
    
     // Libération de la mémoire allouée pour chaque mot
    Liberer(tab)  ;
    Afficher(tab); // Tableau vide après suppression 
    return 0;
}