#include <stdio.h>
#include <stdlib.h>

// Fonction pour saisir des entiers dans un tableau avec allocation dynamique
int* Saisie(int n) {
    int* tab = (int*)malloc(n * sizeof(int)); // Allouer de la mémoire pour le tableau
    printf("Saisir %d entiers :\n", n);
    int * p ;
    for (p = tab; p < tab+n; p++) {
        scanf("%d", p); // Lire l'entier depuis l'entrée standard
    }
    return tab;
}

// Fonction pour afficher le contenu d'un tableau d'entiers
void Afficher(int* tab, int n) {
    printf("Contenu du tableau :\n");
    int * p ;
    for (p = tab; p < tab+n; p++) {
        printf("%d ",*p);
    }
    printf("\n");
}

//Fonction pour trouver min
int *rechercheMin(int * deb, int *fin) {
    int *p, *min;
    min= deb;
    for (p=deb+1 ; p < fin; p++) {
        
        if (*p < *min) {
            min = p;// Mettre à jour le pointeur du minimum
        }
    }
    return min; 
}



void Permutation(int* a, int* b) {
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

// Fonction pour effectuer le tri par sélection (tri croissant) d'un tableau d'entiers
void triSelection(int* tab, int n) {
    int *courant, *minIndex;
    // Parcourir le tableau jusqu'à l'avant-dernier élément
    for (courant = tab; courant < tab+n-1; courant++) {
        minIndex = rechercheMin(courant, tab+n);
        // Échanger l'élément actuel avec l'élément minimum trouvé
        if (minIndex != courant) {
            Permutation (courant, minIndex ) ;
        }
    }
}


int main() {
    int n;
    printf("Entrez le nombre d'entiers à saisir : ");
    scanf("%d", &n);

    // Saisie des entiers dans un tableau avec allocation dynamique
    int* tab = Saisie(n);

    // Affichage du tableau avant le tri
    printf("\nTableau avant le tri :\n");
    Afficher(tab, n);

    // Tri du tableau par ordre croissant (tri par sélection)
    triSelection(tab, n);

    // Affichage du tableau après le tri
    printf("\nTableau après le tri :\n");
    Afficher(tab, n);

    // Libération de la mémoire allouée pour le tableau
    free(tab);

    return 0;
}