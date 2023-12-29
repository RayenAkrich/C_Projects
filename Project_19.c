//Examen MPI Janvier 2022 Faculté des Sciences de Tunis.

//Enoncé : 
//On se propose d'écrire un programme qui assiste un utilisateur dans la composition d'un service
//SMS. Chaque service est désigné par un code et doit respecter une forme bien particulière. On
//suppose que l'on dispose de la fonction suivante:
//exec_service(char *sms, char *message_retour);
//Les services gérés par le programme sont les suivants:
//* Affichage du solde restant
//Code: 100
//forme du SMS: *100#
//Pour ce service le programme doit envoyer à la fonction exec_service() la chaine de caractères de la
//forme si dessus et afficher son message de retour
//* Demande d'appel
//Code: 200
//Donnée: Numéro de portable vers lequel la demande d'appel est envoyée
//Forme du SMS: *200*numéro du portable#
//Pour ce service, le programme doit contrôler la validité du numéro de portable. Le numéro de
//portable doit être une chaine de caractères formée par des chiffres, de longueur égale à 8 et dont le
//premier chiffre est 3.
//Si le numéro de portable est valide , le programme produit une chaine de caractères (sms) de la
//forme précisée ci dessus, appelle la fonction exec_service() et affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.
//* Transfert de crédit
//Code: 101
//Données:
//. Numéro du portable vers lequel le crédit est transféré
//. Montant du crédit à transférer
//forme du SMS: *101*numéro de portable*montant du crédit#
//Pour ce service, le programme doit contrôler la validité du numéro de portable et le montant du
//crédit. . Le montant de crédit est exprimé en millimes, il doit correspondre à une chaine de
//caractères formée par des chiffres, le montant doit etre &gt;= à 500 et inférieure à 5000.
//Si le numéro de portable est valide et le montant du crédit est valide, le programme produit une
//chaine de caractères (sms) de la forme précisée ci dessus, appelle la fonction exec_service() et
//affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.
//* Forfait Internet
//Code: 104
//Données: Volume de données (en Méga)
//Forme du SMS: *104*volume#
//Pour ce service, le volume doit être une chaine formée par des chiffres et la valeur correspondante
//est supérieur ou égale à 500 et inférieure ou égale à 1000 et en multiple de 100.
//Si le volume est valide , le programme produit une chaine de caractères (sms) de la forme précisée cidessus,
//appelle la fonction exec_service() et affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.


//NB:la fonction exec_service() est utilisée pour lancer les différents services en fonction du choix de l'utilisateur.
//On n'est pas obligé de la définir

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Fonction qui retourne 1 si tous les caractères de la chaine s sont des chiffres, et retourne 0 dans le cas contraire
int est_numerique(char *s){
    int test=1,i=0;
    while(test && i<strlen(s)){
        if(!isdigit(s[i])){
            test=0;
        }
        i++;
    }
    return test;
}
//Foncion qui qui retourne 1 si le numéro de portable est valide, et retourne 0 dans le cas contraire
int portable_valide (char * portable){
    int test=1;
    if (portable[0]!='3' || strlen(portable)!=8){
        return 0;
    }
    test= est_numerique(portable);
    return test;
}
//Fonction qui qui retourne 1 si le crédit à transférer est valide, et retourne 0 dans le cas contraire
int credit_valide(char *credit){
    if (!est_numerique(credit)){
        return 0;
    }
    int C=atoi(credit);
    return 500<=C && C<=5000;
}
//Fonction qui retourne 1 si le volume du forfait internet demandé est valide, et retourne 0 sinon.
int volume_valide(char *volume){
    if(!est_numerique(volume)){
        return 0;
    }
    int V= atoi(volume);
    return V%100==0 && V<=1000 && 500<=V;
}
//Pour ce service le programme doit envoyer à la fonction exec_service() la chaine de caractères de la forme si dessus et afficher son message de retour
void service_solde(){
    char s[8],retour[100];
    strcpy(s,"*100#");
    exec_service(s,retour);
    printf("%s",retour);
}
//Pour ce service, le programme doit contrôler la validité du numéro de portable. Si le numéro de portable est valide ,
//le programme produit une chaine de caractères (sms) de la
//forme précisée ci dessus, appelle la fonction exec_service() et affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.
void service_demande_appel(char *portable){
    if(!portable_valide(portable)){
        printf("Numéro portable invalide.");
    }
    else{
        char s[20],retour[100];
        sprintf(s,"*200*%s#",portable);
        exec_service(s,retour);
        printf("%s",retour);
    }
}
//Pour ce service, le programme doit contrôler la validité du numéro de portable et le montant du crédit.
//Si le numéro de portable est valide et le montant du crédit est valide, le programme produit une
//chaine de caractères (sms) de la forme précisée ci dessus, appelle la fonction exec_service() et
//affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.
void service_transfert_credit(char *portable, char *montant_credit){
    if(!portable_valide(portable)){
        printf("Numéro portable invalide.");
    }
    if(!credit_valide(montant_credit)){
        printf("Montant crédit invalide.");
    }
    char s[20],retour[100];
    sprintf(s,"*101*%s*%s#",portable,montant_credit);
    exec_service(s,retour);
    printf("%s",retour);
}
//Pour ce service, le programme doit contrôler la validité du volume.
//Si le volume est valide , le programme produit une chaine de caractères (sms) de la forme précisée ci
//dessus, appelle la fonction exec_service() et affiche son message de retour.
//Sinon il produit une chaine de caractères qui contient la nature de l'erreur et l'affiche.
void service_forfait_internet (char *volume){
    if(!volume_valide(volume)){
        printf("Volume invalide.");
    }
    char s[20],retour[100];
    sprintf(s,"*104*%s#",volume);
    exec_service(s,retour);
    printf("%s",retour);
}
//Le programme principale qui permet à un utilisateur de choisir un service et de la lancer.
int main() {
    int service;char portable[9],credit[5],volume[5];
    do{
        printf("Choisir le service :\n1: Affichage du solde restant\n2: Demande d'appel\n3: Transfert de crédit\n4: Forfait Internet: ");
        scanf("%d",&service);
    }while(!(1<=service && service<=4));
    switch (service) {
        case 1:service_solde();break;
        case 2:
            printf("Saisir votre numéro portable: ");
            gets(portable);
            service_demande_appel(portable);
            break;
        case 3:
            printf("Saisir votre numéro portable: ");
            gets(portable);
            printf("Saisir votre crédit: ");
            gets(credit);
            service_transfert_credit(portable,credit);
            break;
        case 4:
            printf("Saisir votre volume: ");
            gets(volume);
            service_forfait_internet(volume);
            break;
        default:
            printf("Veuillez choisir un numéro entre 1 et 4.");
    }
}
