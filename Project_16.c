//Le but de ce programme est d'implémenter une version solo du jeu Tic-Tac-Toe

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure pour représenter un joueur
struct Joueur {
    char nom[50];
    char prenom[50];
    int age;
};

// Fonction pour afficher le plateau de jeu
void afficherPlateau(char plateau[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", plateau[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Fonction pour vérifier s'il y a un gagnant
int verifierGagnant(char plateau[3][3], char symbole) {
    // Vérification des lignes et des colonnes
    for (int i = 0; i < 3; i++) {
        if (plateau[i][0] == symbole && plateau[i][1] == symbole && plateau[i][2] == symbole)
            return 1; // Gagnant trouvé dans une ligne
        if (plateau[0][i] == symbole && plateau[1][i] == symbole && plateau[2][i] == symbole)
            return 1; // Gagnant trouvé dans une colonne
    }

    // Vérification des diagonales
    if (plateau[0][0] == symbole && plateau[1][1] == symbole && plateau[2][2] == symbole)
        return 1; // Gagnant trouvé dans la diagonale principale
    if (plateau[0][2] == symbole && plateau[1][1] == symbole && plateau[2][0] == symbole)
        return 1; // Gagnant trouvé dans l'autre diagonale

    return 0; // Aucun gagnant trouvé
}

// Fonction pour vérifier si le plateau est complet (match nul)
int plateauComplet(char plateau[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (plateau[i][j] == ' ')
                return 0; // Il y a une case vide, le plateau n'est pas complet

    return 1; // Le plateau est complet (match nul)
}

// Fonction pour choisir la meilleure case pour l'ordinateur
// Fonction pour choisir la meilleure case pour l'ordinateur
void choisirCaseOrdinateur(char plateau[3][3], int niveau, int *ligne, int *colonne) {
    switch (niveau) {
        case 1: // Facile - Choix aléatoire
            *ligne = rand() % 3;
            *colonne = rand() % 3;
            break;
        case 2: // Difficile - Bloquer le joueur ou choix aléatoire
            // Bloquer le joueur s'il est sur le point de gagner
            for (int i = 0; i < 3; i++) {
                if (plateau[i][0] == 'X' && plateau[i][1] == 'X' && plateau[i][2] == ' ') {
                    *ligne = i;
                    *colonne = 2;
                    return;
                }
                if (plateau[i][0] == 'X' && plateau[i][2] == 'X' && plateau[i][1] == ' ') {
                    *ligne = i;
                    *colonne = 1;
                    return;
                }
                if (plateau[i][1] == 'X' && plateau[i][2] == 'X' && plateau[i][0] == ' ') {
                    *ligne = i;
                    *colonne = 0;
                    return;
                }

                if (plateau[0][i] == 'X' && plateau[1][i] == 'X' && plateau[2][i] == ' ') {
                    *ligne = 2;
                    *colonne = i;
                    return;
                }
                if (plateau[0][i] == 'X' && plateau[2][i] == 'X' && plateau[1][i] == ' ') {
                    *ligne = 1;
                    *colonne = i;
                    return;
                }
                if (plateau[1][i] == 'X' && plateau[2][i] == 'X' && plateau[0][i] == ' ') {
                    *ligne = 0;
                    *colonne = i;
                    return;
                }
            }

            if (plateau[0][0] == 'X' && plateau[1][1] == 'X' && plateau[2][2] == ' ') {
                *ligne = 2;
                *colonne = 2;
                return;
            }
            if (plateau[0][0] == 'X' && plateau[2][2] == 'X' && plateau[1][1] == ' ') {
                *ligne = 1;
                *colonne = 1;
                return;
            }
            if (plateau[1][1] == 'X' && plateau[2][2] == 'X' && plateau[0][0] == ' ') {
                *ligne = 0;
                *colonne = 0;
                return;
            }

            if (plateau[0][2] == 'X' && plateau[1][1] == 'X' && plateau[2][0] == ' ') {
                *ligne = 2;
                *colonne = 0;
                return;
            }
            if (plateau[0][2] == 'X' && plateau[2][0] == 'X' && plateau[1][1] == ' ') {
                *ligne = 1;
                *colonne = 1;
                return;
            }
            if (plateau[1][1] == 'X' && plateau[2][0] == 'X' && plateau[0][2] == ' ') {
                *ligne = 0;
                *colonne = 2;
                return;
            }

            // Si le joueur n'est pas sur le point de gagner, choix aléatoire
            *ligne = rand() % 3;
            *colonne = rand() % 3;
            break;
        default:
            break;
    }
}


// Fonction principale du jeu
int main() {
    struct Joueur joueur;
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char ordinateur = 'O';
    int ligne, colonne;
    int tourJoueur = 1;
    int niveau;

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

    // Demander les informations du joueur

    printf("Entrez le prénom du joueur : ");
    scanf("%s", joueur.prenom);

    printf("Entrez le nom du joueur : ");
    scanf("%s", joueur.nom);
    printf("Entrez l'âge du joueur : ");
    scanf("%d", &joueur.age);

    // Demander le niveau de difficulté
    do {
        printf("Choisissez le niveau de difficulte (1: Facile, 2: Difficile) : ");
        scanf("%d", &niveau);
    } while (niveau < 1 || niveau > 3);

    do {
        // Afficher le plateau de jeu
        afficherPlateau(plateau);

        // Tour du joueur
        if (tourJoueur) {
            printf("Tour de %s %s (X)\n", joueur.prenom, joueur.nom);
            printf("Entrez la ligne (1-3) : ");
            scanf("%d", &ligne);
            printf("Entrez la colonne (1-3) : ");
            scanf("%d", &colonne);
            ligne--;
            colonne--;

            // Vérifier si le mouvement est valide
            if (ligne >= 0 && ligne < 3 && colonne >= 0 && colonne < 3 && plateau[ligne][colonne] == ' ') {
                plateau[ligne][colonne] = 'X';
                tourJoueur = 0;
            } else {
                printf("Mouvement invalide. Veuillez réessayer.\n");
                continue;
            }
        } else { // Tour de l'ordinateur
            printf("Tour de l'ordinateur (O)\n");
            choisirCaseOrdinateur(plateau, niveau, &ligne, &colonne);

            // Vérifier si le mouvement est valide
            if (plateau[ligne][colonne] == ' ') {
                plateau[ligne][colonne] = ordinateur;
                tourJoueur = 1;
            }
        }

        // Vérifier s'il y a un gagnant
        if (verifierGagnant(plateau, 'X')) {
            afficherPlateau(plateau);
            printf("%s %s a gagné ! Félicitations !\n", joueur.prenom, joueur.nom);
            break;
        } else if (verifierGagnant(plateau, 'O')) {
            afficherPlateau(plateau);
            printf("L'ordinateur (O) a gagné ! Essayez encore.\n");
            break;
        }

        // Vérifier s'il y a match nul
        if (plateauComplet(plateau)) {
            afficherPlateau(plateau);
            printf("Match nul ! Pas de gagnant.\n");
            break;
        }

    } while (1);

    return 0;
}
