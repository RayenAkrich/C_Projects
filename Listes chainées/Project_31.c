//Le but de ce programme est de remplir une liste chainée en date et température puis supprimer les cases contenant une température égale à 20°C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct T
{
    char date[100];
    float temp;
    struct T* next;
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
        //L'ajout de nouveau pour la premiere fois
        if (p == NULL) {
            p = nouveau_case;
            p2 = nouveau_case;
            //Sinon
        } else {
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

    //Recherche et supression des élements contenant Temp=20°C
    p2=p;
    //Check pour la premiere case
    while (p != NULL && p->temp == 20) {
        T* temp = p;
        p = p->next;
        free(temp);
    }
    p2 = p;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->next->temp == 20) {
            //Check pour la derniere case
            if(p2->next->next==NULL){
                free(p2->next);
                p2->next=NULL;
            }//Sinon
            else{
                T* p3 = p2->next;
                p2->next = p2->next->next;
                p3->next=NULL;
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
        free(p);
        p=temp;
    }

    return 0;
}
