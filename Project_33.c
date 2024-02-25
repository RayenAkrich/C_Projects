//Le but de ce programme est de remplir une liste doublement chainée en date et température ,
//supprime de cases selon le choix de la temperature par l'utilisateur
//ou bien ajouter une case après une temperature donné par l'utilisateur

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

T *p2=NULL;
void Add_Element(T** p){
    // Allocation d'une nouvelle case mémoire
    T *nouveau_case = (T*)malloc(sizeof(T));
    if (nouveau_case == NULL) {
        printf("Erreur d'allocation de mémoire");
        exit(0);
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
    if (*p == NULL) {
        *p = nouveau_case;
        p2 = nouveau_case;
        nouveau_case->next=NULL;
        //Sinon
    } else {
        nouveau_case->previous=p2;
        p2->next = nouveau_case;
        p2 = p2->next;
        nouveau_case->next=NULL;
    }
}

void Afficher_Liste(T* p){
    if(p==NULL){
        printf("\nLa liste est vide!\n");
    }else{
        T* p2;
        printf("\nAffichage de la liste:\n");
        p2 = p;
        while (p2 != NULL) {
            printf("Date: %s, Temperature: %f\n", p2->date, p2->temp);
            p2 = p2->next;
        }
    }
}

void Supprimer_case(T* p,float temperture_X){
    //Recherche et supression des élements contenant la temperature saisie par l'utilisateur
    //Check pour les premieres cases
    while (p != NULL && p->temp == temperture_X) {
        T *temp = p->next;
        p->next=NULL;
        p->previous=NULL;
        free(p);
        p=temp;
    }
    if(p!=NULL){
        p->previous=NULL;//initialisation pour la premiere case
    }
    T* p2 = p;
    if (p2!=NULL){
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
                    if(p3->next!=NULL){p2->next = p3->next;}
                    p3->next=NULL;
                    p3->previous=NULL;
                    if(p2->next!=NULL){p2->next->previous=p2;}
                    free(p3);
                }
            } else {
                p2 = p2->next;
            }}
    }
}

void Add_Element_After_X(T** p,float temperture_X){
    // Allocation d'une nouvelle case mémoire
    T *nouveau_case = (T*)malloc(sizeof(T));
    if (nouveau_case == NULL) {
        printf("Erreur d'allocation de mémoire");
        exit(0);
    }

    // Saisie de la date et de la température
    printf("Saisir la date: ");
    fflush(stdin);
    gets(nouveau_case->date);
    fflush(stdout);

    printf("Saisir la temperature: ");
    scanf("%f", &nouveau_case->temp);

    // La liste est vide
    if(*p==NULL){
        *p=nouveau_case;
        return;
    }

    T *p2 = *p;
    // La température X n'est pas trouvée dans la liste
    while (p2->next != NULL && p2->temp != temperture_X) {
        p2 = p2->next;
    }

    if (p2->temp != temperture_X) {
        // On ajoute la nouvelle case à la fin de la liste
        p2->next = nouveau_case;
        nouveau_case->previous = p2;
        return;
    }else {
        // La température X est trouvée dans la liste
        T *p3 = p2->next;
        p2->next = nouveau_case;
        nouveau_case->previous = p2;
        nouveau_case->next = p3;
        if (p3 != NULL) {
            p3->previous = nouveau_case;
        }
    }
}

void Sortir(T* p){
    // Free de p
    while (p!= NULL) {
        T *temp = p->next;
        p->next=NULL;
        p->previous=NULL;
        free(p);
        p=temp;
    }
    exit(1);
}

int main()
{
    T *p;
    T *p2;


    while(1){
        // Choix de l'utilisateur
        int choix;
        do{
            printf("\n0: Affichage de la liste\n1: Ajouter une case\n2: Supprimer les cases selon une temperature\n3: Ajouter une case apres une temperature\n4: Sortir du programme\n_____");
            scanf("%d", &choix);} while (!(choix==1 || choix==2 || choix==3 || choix==4 || choix==0));

        // Choix 0
        if(choix==0){
            Afficher_Liste(p);
        }

        // Choix 1
        if(choix==1){
            int test_ajout;
            do{
                Add_Element(&p);
                // Demande à l'utilisateur s'il veut ajouter une autre case
                printf("Voulez vous ajouter une autre case ? (1 pour oui, 0 pour non): ");
                scanf("%d", &test_ajout);
            }while(test_ajout==1);
        }

        // Choix 2
        if(choix==2){
            //Saisie de la temprerature qu'on veut supprimer
            float temperture_X;
            printf("\nQuelle est la temperature que vous voulez supprimer:\n");
            scanf("%f",&temperture_X);
            Supprimer_case(p,temperture_X);
        }

        // Choix 3
        if(choix==3){
            //Saisie de la temprerature qu'on veut ajouter apres lui
            float temperture_X;
            printf("\nQuelle est la temperature que vous voulez ajouter apres lui:\n");
            scanf("%f",&temperture_X);
            Add_Element_After_X(&p,temperture_X);
        }

        // Choix 4
        if(choix==4){
            Sortir(p);
        }
    }
}
