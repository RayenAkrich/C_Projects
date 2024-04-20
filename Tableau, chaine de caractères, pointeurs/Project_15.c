//Le but de programme est de remplir un tableau T de N étudiant saisit par l'utilisateur .. Chaque étudiant se caractérise par un Nom , un Prénom , Age et numéro de CIN.
#include <stdlib.h>
#include <stdio.h>

struct Etud{
    char *nom;
    char *pren;
    int age;
    int cin;
};
typedef struct Etud Etud;
int main(){
    int n;
    Etud *T;

    printf("Donner le nombre des étudiants: ");
    scanf("%d",&n);

    T=(Etud*)malloc(n*sizeof(Etud));
    if(T==NULL){
        printf("Error");
        return 0;
    }
    for(int i=0;i<n;i++){
        int n1,n2;
      
        printf("Saisir la taille du nom de l'élève %d: ",i+1);
        scanf("%d",&n1 );
      
        T[i].nom=(char*)malloc((n1+1)*sizeof(char));
        if(T[i].nom==NULL) {
            printf("error");
            if(T!=NULL){
                for(int j=0;j<i;j++){
                    if(T[j].nom!=NULL){
                        free(T[j].nom);}
                    if(T[j].pren!=NULL){
                        free(T[j].pren);}
                }
                free(T);
            }
            return 0;
        }
      
        printf("Donner le nom du %d eleve: ",i+1);
        scanf("%s",T[i].nom);
        
        printf("Saisir la taille du prenom de l'élève %d: ",i+1);
        scanf("%d",&n2 );
      
        T[i].pren=(char*)malloc((n2+1)*sizeof(char));
        if(T[i].pren==NULL) {
            printf("error");
            if(T!=NULL){
                free(T[i].nom);
                for(int j=0;j<i;j++){
                    if(T[j].nom!=NULL){
                        free(T[j].nom);}
                    if(T[j].pren!=NULL){
                        free(T[j].pren);}
                }
                free(T);
            }
            return 0;
        }
      
        printf("Donner le prénom de l'élève %d: ",i+1);
        scanf("%s",T[i].pren);

        printf("Donner l'age du de l'élève %d: ",i+1);
        scanf("%d",&T[i].age);

        printf("Donner le cin du de l'élève %d: ",i+1);
        scanf("%d",&T[i].cin);

    }
  
    for(int i=0;i<n;i++){
        printf("-L'élève %d:\nNom: %s\nPrénom: %s\nAge: %d\nN.CIN: %d\n",i+1,T[i].nom,T[i].pren,T[i].age,T[i].cin);
    }
  
    if(T!=NULL){
        for(int i=0;i<n;i++){
            if(T[i].nom!=NULL){
                free(T[i].nom);}
            if(T[i].pren!=NULL){
                free(T[i].pren);}
        }
        free(T);
    }
}
