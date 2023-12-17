//Le but de ce programme est d'implémenter une version solo de Pierre-Papier-Ciseaux 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure pour enregistrer les informations du joueur
struct Joueur {
    char nom[50];
    char prenom[50];
    int age;
};

// Fonction pour générer le choix aléatoire de l'ordinateur
int choixOrdinateur() {
    return rand() % 3; // 0 pour Pierre, 1 pour Papier, 2 pour Ciseaux
}

// Fonction pour déterminer le gagnant de la manche
int determinerGagnant(int choixJoueur, int choixOrdi) {
    if (choixJoueur == choixOrdi) {
        return 0; // Égalité
    } else if ((choixJoueur == 0 && choixOrdi == 2) || (choixJoueur == 1 && choixOrdi == 0) || (choixJoueur == 2 && choixOrdi == 1)) {
        return 1; // Le joueur gagne
    } else {
        return -1; // L'ordinateur gagne
    }
}

int main() {
    srand(time(NULL));

    // Enregistrement du joueur
    struct Joueur joueur;
    printf("Entrez votre nom : ");
    scanf("%s", joueur.nom);
    printf("Entrez votre prenom : ");
    scanf("%s", joueur.prenom);
    printf("Entrez votre age : ");
    scanf("%d", &joueur.age);

    // Configuration du jeu
    int nbManches, nbTentatives;
    printf("Entrez le nombre de manches : ");
    scanf("%d", &nbManches);
    printf("Entrez le nombre de tentatives par manche : ");
    scanf("%d", &nbTentatives);

    // Initialisation des statistiques
    int victoires = 0;
    int manchesJouees = 0;

    // Boucle de jeu
    for (int i = 0; i < nbManches; i++) {
        printf("\n=== Manche %d ===\n", i + 1);

        // Choix du joueur
        int choixJoueur;
        printf("Choisissez entre Pierre (0), Papier (1) et Ciseaux (2) : ");
        scanf("%d", &choixJoueur);

        // Validation du choix du joueur
        if (choixJoueur < 0 || choixJoueur > 2) {
            printf("Choix invalide. Veuillez entrer 0, 1 ou 2.\n");
            i--; // Répéter la manche
            continue;
        }

        // Choix de l'ordinateur
        int choixOrdi = choixOrdinateur();

        // Détermination du gagnant
        int resultat = determinerGagnant(choixJoueur, choixOrdi);

        // Affichage des résultats
        printf("%s %s a choisi : ", joueur.prenom, joueur.nom);
        switch (choixJoueur) {
            case 0:
                printf("Pierre\n");
                break;
            case 1:
                printf("Papier\n");
                break;
            case 2:
                printf("Ciseaux\n");
                break;
        }

        printf("L'ordinateur a choisi : ");
        switch (choixOrdi) {
            case 0:
                printf("Pierre\n");
                break;
            case 1:
                printf("Papier\n");
                break;
            case 2:
                printf("Ciseaux\n");
                break;
        }

        if (resultat == 0) {
            printf("Égalité !\n");
        } else if (resultat == 1) {
            printf("Vous avez gagné la manche !\n");
            victoires++;
        } else {
            printf("L'ordinateur a gagné la manche.\n");
        }

        manchesJouees++;

        // Vérification de la fin du jeu
        if (victoires >= nbManches / 2 + 1) {
            printf("\nFélicitations, vous avez remporté la partie en %d manches !\n", manchesJouees);
            break;
        }
    }

    // Affichage des statistiques
    printf("\n=== Statistiques ===\n");
    printf("Nombre total de manches jouées : %d\n", manchesJouees);
    printf("Nombre de victoires : %d\n", victoires);

    return 0;
}
