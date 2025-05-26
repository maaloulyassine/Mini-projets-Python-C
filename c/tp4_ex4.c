#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure de la cellule contenant les infos d'un étudiant de la liste chaînée 
struct Cellule {
    char nom[50];
    char prenom [50];
    float moyenne;
    struct Cellule *suivant;
} ;


// Fonction pour saisir les informations d'un étudiant
struct Cellule * saisieEtudiant () {
    struct Cellule * e= (struct Cellule *)malloc(sizeof(struct Cellule));
    printf("Nom : ");     scanf("%s", e->nom);
    printf("Prénom : ");
    scanf("%s", e->prenom);
    printf("Moyenne : ");
    scanf("%f", &e->moyenne);
    e->suivant=NULL ;
    return e;
}

// Fonction pour afficher les informations d'un étudiant
void affichageEtudiant(struct Cellule *e) {
    printf("Nom : %s\n", e->nom);
    printf("Prénom : %s\n", e->prenom);
    printf("Moyenne : %.2f\n", e->moyenne);
    printf("\n ------------------ \n ");
}


// Fonction pour insérer un étudiant en tête de la liste
struct Cellule * insererTete(struct Cellule *liste) {
    
    struct Cellule * nouvelleCellule=saisieEtudiant () ;
    nouvelleCellule->suivant = liste;
    liste = nouvelleCellule;
    return liste;
} 

// Fonction pour afficher tous les étudiants dans la liste
void affichageListe(struct Cellule * liste) {
    struct Cellule *p  ;
    p= liste;
    while (p != NULL) {
        affichageEtudiant(p);
        p = p->suivant;
    }
}

// Fonction pour rechercher un étudiant par nom et prénom
struct Cellule *rechercheEtudiant(struct Cellule * liste, char nom[], char prenom[]) {
    struct Cellule *p; p= liste;
    while (p != NULL) {
        if (strcmp(p->nom, nom) == 0 && strcmp(p->prenom, prenom) == 0) {
            return p;
        }
        p = p->suivant;
    }
    return NULL; // Étudiant non trouvé
}

//Fonction pour trouver l'étudiant avec la plus basse moyenne dans la liste
struct Cellule *rechercheMin(struct Cellule * liste) {
    struct Cellule *p, *min;
    min= liste;
    p = liste->suivant ;
    while (p != NULL) {
        if (p->moyenne < min->moyenne) {
            min = p;
        }
        p = p->suivant;
    }
    return min; 
}

// Permutation des cellules si nécessaire
void Permutation (struct Cellule *courant, struct Cellule *min ) {
    char tempNom[50], tempPrenom[50]  ;
    float tempMoyenne ;
    // Permutation des noms
    strcpy(tempNom,courant->nom ) ;
    strcpy(courant->nom,min->nom ) ;
    strcpy(min->nom,tempNom ) ;
    
      // Permutation des prénoms
    strcpy(tempPrenom,courant->prenom ) ;
    strcpy(courant->prenom,min->prenom ) ;
    strcpy(min->prenom,tempPrenom ) ;

      // Permutation des moyennes
      tempMoyenne = courant->moyenne;
      courant->moyenne = min->moyenne;
      min->moyenne = tempMoyenne;
    
}
// Fonction pour trier la liste par ordre croissant de moyenne
void TriListe (struct Cellule **liste) {
  struct Cellule *courant = *liste;
  struct Cellule *min;

  while (courant != NULL) {
    min=rechercheMin(courant);

    // Echange des cellules si nécessaire
    if (courant != min) {
      Permutation (courant, min ) ;
    }
    courant = courant->suivant;
  }
}

// Fonction pour supprimer un étudiant par nom et prénom
struct Cellule *supprimerEtudiant(struct Cellule * liste, char nom[], char prenom[]) {
    struct Cellule *precedent,*courant ; 
    

    courant = rechercheEtudiant(liste,nom, prenom);
    if (courant==NULL){
        return liste;
    }
    else if (courant==liste){
        liste= liste->suivant ;
        free(courant) ;
    }else{
        precedent= liste;
        while (precedent->suivant != courant) {
            precedent = precedent->suivant;
        }
        precedent->suivant= courant->suivant ;
        free(courant) ;
    }
    return liste;
}

// Libérer la mémoire allouée pour la liste
struct Cellule *libererListe(struct Cellule * liste) {
    struct Cellule *p ; 
    
    while (liste != NULL) {
        p = liste;
        liste = liste->suivant;
        free(p);
    }
} 

int main () {
    struct Cellule * liste=NULL ;
    
    // Remplissage de la liste
    int n,i ;
    printf("REMPLISSAGE DE LA LISTE\n");
    
    printf("Donner le nombre d'etdiants : "); scanf("%d",&n) ; // nombre de cellules de la liste
    
    for (i=0;i<n;i++){
        printf("\n------- Insérer etudiant %d --------\n",i+1);
        liste=insererTete (liste) ;    
    }
    
    
    // Affichage de liste avant le tri
    printf("\n AFFICHAGE (AVANT TRI)\n");
    affichageListe(liste);
    
    // Affichage de liste après le tri (Tri de la liste par ordre croissant de moyenne)
    printf("\n AFFICHAGE (APRES TRI)\n");
    TriListe (&liste) ;
    affichageListe(liste);
    
    // rechercher un étudiant par nom et prénom
    char nom[50],prenom[50] ;
    printf("\n RECHERCHER UN ETUDIANT\n");
    
    printf("Donner le nom : "); scanf("%s",nom) ;
    printf("Donner le prénom : "); scanf("%s",prenom) ;
    struct Cellule * r;
    r=rechercheEtudiant(liste,nom, prenom);
    if (r==NULL) {
        printf("\n Aucun étudiant avec ce nom et prénom trouvé.\n");
    }else{
        printf("\n étudiant trouvé.\n");
        affichageEtudiant(r);
    }
    
    // supprimer un étudiant par nom et prénom
    printf("\n SUPPRIMER UN ETUDIANT\n");
    printf("Donner le nom : "); scanf("%s",nom) ;
    printf("Donner le prénom : "); scanf("%s",prenom) ;
    liste=supprimerEtudiant(liste,nom, prenom);
    
    printf("\n AFFICHAGE (APRES SUPPRESSION)\n");
    affichageListe(liste);
    
    // Libérer la mémoire allouée pour la liste
    printf("\n LIBERATION DE LA MEMOIRE \n");
    liste= libererListe(liste) ;
    if (liste==NULL){
        printf("\n Liberation de memoire effectuee avec succes \n");
    }
 return 0 ;   
}