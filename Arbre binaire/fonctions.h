#ifndef UNTITLED_FONCTIONS_H
#define UNTITLED_FONCTIONS_H

//Type arbre binaire
struct Arbre_b{
    struct Arbre_b *F_d; //Fils droit
    struct Arbre_b *F_g; //Fils gauche
    int a; //Type de l'information est un entier 
};
typedef struct Arbre_b Arbre;

Arbre* create(int n); //n est le nombre de niveaux

void liberer_arbre(Arbre* arbre); //Fonction pour la libèration de la mémoire

Arbre* recherche(Arbre* racine, int x) ; //Fonction de recherche d'un élément x dans une arbre

#endif //UNTITLED_FONCTIONS_H
