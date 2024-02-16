//Le but de ce programme est de remplir une liste doublement chainée en date et température puis supprimer les cases contenant une température saisie par l'utilisateur

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct T
{
    char date[100];
    float temp;
    struct T* next;
    struct T* previous;
} T;

int main()
{
    T *p=NULL;
    T *p2=NULL;

    // Remplissage de la liste chaînée
    int test;
    do {
        // Allocation d'une nouvelle case mémoire
        T *nouveau_case = (T*)malloc(sizeof(T));
        if (nouveau_case == NULL) {
            printf("Erreur d'allocation de mémoire");
            return 1;
        }

        // Saisie de la date et de la température
        printf("Saisir la date: ");
        fflush(stdin);
        gets(nouveau_case->date);
        fflush(stdout);

        printf("Saisir la temperature: ");
        scanf("%f", &nouveau_case->temp);

        // Liaison avec la liste chaînée
        nouveau_case->next = NULL;
        nouveau_case->previous= NULL;
        //L'ajout de nouveau pour la premiere fois
        if (p == NULL) {
            p = nouveau_case;
            p2 = nouveau_case;
            //Sinon
        } else {
            nouveau_case->previous=p2;
            p2->next = nouveau_case;
            p2 = p2->next;
        }

        // Demande à l'utilisateur s'il veut ajouter une autre case
        printf("Voulez vous ajouter une autre case ? (1 pour oui, 0 pour non): ");
        scanf("%d", &test);

    } while (test != 0);

    // Affichage de la liste avant suppression
    printf("\nAffichage avant suppression:\n");
    p2 = p;
    while (p2 != NULL) {
        printf("Date: %s, Temperature: %f\n", p2->date, p2->temp);
        p2 = p2->next;
    }

    //Saisie de la temprerature qu'on veut supprimer
    float temperture_X;
    printf("\nQuelle est la temperature que vous voulez supprimer:\n");
    scanf("%f",&temperture_X);

    //Recherche et supression des élements contenant la temperature saisie par l'utilisateur
    p2=p;
    //Check pour les premieres cases
    while (p != NULL && p->temp == temperture_X) {
        T *temp = p->next;
        p->next=NULL;
        p->previous=NULL;
        free(p);
        p=temp;
    }
    p2 = p;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->next->temp == temperture_X) {
            //Check pour la derniere case
            if(p2->next->next==NULL){
                p2->next->previous=NULL;
                free(p2->next);
                p2->next=NULL;
            }//Sinon
            else{
                T* p3 = p2->next;
                p2->next=NULL;
                p2->next = p3->next;
                p3->next=NULL;
                p3->previous=NULL;
                p2->next->previous=p2;
                free(p3);
            }
        } else {
            p2 = p2->next;
        }}

    // Affichage de la liste après suppression
    printf("\nAffichage apres suppression:\n");
    p2 = p;
    while (p2 != NULL) {
        printf("Date: %s, Temperature: %f\n", p2->date, p2->temp);
        p2 = p2->next;
    }

    // Free de p
    while (p != NULL) {
        T *temp = p->next;
        p->next=NULL;
        p->previous=NULL;
        free(p);
        p=temp;
    }

    return 0;
}
